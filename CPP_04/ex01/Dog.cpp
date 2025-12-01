/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 03:03:10 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 06:02:50 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
	dog_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	if (dog_brain)
		delete dog_brain;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->dog_brain = new Brain(*(copy.dog_brain));
	*this = copy;
}

Dog& Dog::operator=(const Dog &copy) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
		*(this->dog_brain) = *(copy.dog_brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof i wanna "
			  << this->dog_brain->getIdea(77) << std::endl;
}