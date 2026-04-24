	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:54:37 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/02/26 14:54:37 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
	_max_size = 0;
}

Span::Span(unsigned int N) : _max_size(N) {}

Span::Span(const Span& other) : _numbers(other._numbers), _max_size(other._max_size) {}


Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_numbers = other._numbers;
		_max_size = other._max_size;
	}
	return *this;
}


Span::~Span() {}

unsigned int Span::getSize() const {
	return _max_size;
}


void Span::addNumber(int nbr) {
	if (_numbers.size() >= _max_size)
		throw std::out_of_range("Span is full");
	_numbers.push_back(nbr);
}

int	Span::longestSpan() {
	int	min;
	int	max;
	int	result;
	if (_numbers.size() < 2)
		throw std::logic_error("Span is smalller than 2 digits");
	min = *std::min_element(_numbers.begin(), _numbers.end());
	max = *std::max_element(_numbers.begin(), _numbers.end());
	result = max - min;
	return result;
	/*
	int min = _arr[0];
	int max = _arr[0];

	for (unsigned int i = 1; i < _idx; i++)
	{
		if (_arr[i] < min) 
			min = _arr[i];
		if (_arr[i] > max)
			max = _arr[i];
	}
	*/
}

int	Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Span is smalller than 2 digits");
	std::vector<int> tmp = _numbers;
	// std::copy(_numbers.begin(), _numbers.end(), tmp.begin());
	int min_span;
	int buf;
	std::sort(tmp.begin(), tmp.end());
	min_span = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < _numbers.size() - 1; i++) {
		buf = tmp[i+1] - tmp[i];
		if (min_span > buf)
			min_span = buf;
	}
	return min_span;
}
