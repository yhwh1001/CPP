/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:03:06 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 07:21:54 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor" << std::endl;
	this->type = "Cat";
	cat_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	if (cat_brain)
		delete cat_brain;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->cat_brain = new Brain(*(copy.cat_brain));
	*this = copy;
}

Cat& Cat::operator=(const Cat &copy) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
		*(this->cat_brain) = *(copy.cat_brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "rwwr Miauuu i wanna "
	<< this->cat_brain->getIdea(42) << std::endl;
}