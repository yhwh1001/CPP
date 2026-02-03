/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:45:33 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/30 15:50:38 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

int	ScalarConverter::getType(const std::string& literal) {
	int m = 0;
	while (literal[m]) {
		if (literal[m] < 32 || literal[m] > 126)
			return -1;
		m++;
	}
	m--;
	if ((literal[m] >= 48 && literal[m] <= 57) && m == 0)
		return 0;
	while (m > 0) {
		if (literal[m] == 'f' && m > 1) {
			return 2;
		}
		if (literal[m] == '.')
			return 3;
		m--;
	}
	return 1;
}

void	ScalarConverter::convert(const std::string& literal) {
	int type;

	type = getType(literal);

	switch (type) {
		case 0:
		
	}

	// int m = 0;
	// while (literal[m]) {
	// 	if (literal[m] < 32 || literal[m] > 126)
			
	
	// 	m++;
	// }
	
	this->getType()
		
		
	
}