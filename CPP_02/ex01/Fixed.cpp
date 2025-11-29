/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:40:20 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/11/29 14:59:35 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = intValue << this->_fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(floatValue * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	// this->_fixedPointValue = copy.getRawBits();
	
	// alternative (to show the extra "Copy assignment operator called", unnecessary overhead process):
	*this = copy;
	// alternative (direct access, no getRawBits message):
	// this->_fixedPointValue = copy._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		// this->_fixedPointValue = copy.getRawBits();
		// alternative:
		this->_fixedPointValue = copy._fixedPointValue;
	}
	return *this;
}

int	Fixed::toInt(void) const {
	return this->_fixedPointValue >> this->_fractionalBits;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
