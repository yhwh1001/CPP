/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 07:56:22 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/01 08:07:44 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : abst_type("AAnimal") {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal &copy) {
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &copy) {
		this->abst_type = copy.abst_type;
	}
	return *this;
}

std::string AAnimal::getType() const {
	return abst_type;
}