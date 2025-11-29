/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:40:20 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/11/29 17:02:54 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	// std::cout << "Default constructor called" << std::endl;
} 

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = intValue << this->_fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(floatValue * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& copy) {
	// std::cout << "Copy constructor called" << std::endl;
	// this->_fixedPointValue = copy.getRawBits();
	
	// alternative (to show the extra "Copy assignment operator called", unnecessary overhead process):
	// *this = copy;
	// alternative (direct access, no getRawBits message):
	this->_fixedPointValue = copy._fixedPointValue;
}

Fixed&	Fixed::operator=(const Fixed& copy) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		// this->_fixedPointValue = copy.getRawBits();
		// alternative:
		this->_fixedPointValue = copy._fixedPointValue;
	}
	return *this;
}

int		Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

int		Fixed::toInt(void) const {
	return this->_fixedPointValue >> this->_fractionalBits;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

// Comparison operators
bool	Fixed::operator>(const Fixed& other) const {
	return this->_fixedPointValue > other._fixedPointValue;
}

bool	Fixed::operator<(const Fixed& other) const {
	return this->_fixedPointValue < other._fixedPointValue;
}

bool	Fixed::operator>=(const Fixed& other) const {
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool	Fixed::operator<=(const Fixed& other) const {
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool	Fixed::operator==(const Fixed& other) const {
	return this->_fixedPointValue == other._fixedPointValue;
}

bool	Fixed::operator!=(const Fixed& other) const {
	return this->_fixedPointValue != other._fixedPointValue;
}

// Arithmetic operators
Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> this->_fractionalBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_fixedPointValue << this->_fractionalBits) / other._fixedPointValue);
	return result;
}

// Increment / Decrement operators
Fixed&	Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp = *this;
	this->_fixedPointValue++;
	return temp;
}

Fixed&	Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed temp = *this;
	this->_fixedPointValue--;
	return temp;
}

// Static member functions for min and max
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
