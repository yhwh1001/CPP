/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:45:33 by manelcarval       #+#    #+#             */
/*   Updated: 2026/02/05 13:16:48 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
// #include <cctype>
#include <cstdlib>
// #include <algorithm>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void	printChar(const std::string &literal) {
	char c;
	
	c = literal[0];
	std::cout << "char: " << c <<std::endl;
	std::cout << "int: " << static_cast<int>(c) <<std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printInt(const std::string& literal) {
	int value;

	value = static_cast<int>(std::atoi(literal.c_str()));
	if (std::isprint(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void	printFloat(const std::string &literal) {
	float value;
	// is static_cast needed?
	value = static_cast<float>(std::strtof(literal.c_str(), NULL));
	if (std::isprint(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value == static_cast<int>(value)) {
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
		std::cout << "double: " << value << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
}

void	printDouble(const std::string &literal) {
	double value;

	value = std::strtod(literal.c_str(), NULL);
	if (std::isprint(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value == static_cast<int>(value)) {
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
		std::cout << "double: " << value << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
}

void	printNan(const std::string& literal) {
	(void)literal;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	printInf(const std::string& literal) {
	(void)literal;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float:"<< literal[0] << "inff" << std::endl;
	std::cout << "double: " << literal[0] << "inf" << std::endl;
}

int	getType(const std::string& literal) {
	int m = 0;
	
	if (literal == "nan" || literal == "nanf")
		return 4;
	if (literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
		return 5;
	if (literal.find('.') != literal.rfind('.'))
		return -1;
	while (literal[m]) {
		if (literal.empty() || !std::isprint(literal[m]))
			return -1;
		m++;
	}
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return 0;
	m--;
	if (literal[m] == 'f' && literal.find('.') != std::string::npos && std::isdigit(literal[m-1]))
		return 2;
	if (literal.find('.') != std::string::npos && std::isdigit(literal[m]))
		return 3;
	while (literal[m]) {
		if (literal.length() >= 1 && !std::isdigit(literal[m]))
			return -1;
		m--;
	}
	return 1;
		
// 	int m;
// 	m = 0;
// 	if (literal[m] == '\0')
// 		return -1;
// 	while (literal[m]) {
// 		if (!std::isprint(literal[m]))
// 			return -1;
// 		m++;
// 	}
// 	m--;
// 	if (literal == "nan" || literal == "+inf" || literal == "-inf")
// 		return 3;
// 	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
// 		return 2;
// 	if ((literal[m] > '0' && literal[m] < '9') && m == 0)
// 		return 0;
// 	while (m > 0) {
// 		if (literal[m] == 'f' && m > 1) 
// 			return 2;
// 		if (literal[m] == '.')
// 			return 3;
// 		m--;
// 	}
// 	return 1;
}

void	ScalarConverter::convert(const std::string& literal) {
	int type;
	
	type = getType(literal);

	switch (type) {
		case 0:
			printChar(literal);
			return ;
		case 1:
			printInt(literal);
			return ;
		case 2:
			// is static_cast needed?
			printFloat(literal);
			return ;
		case 3:
			printDouble(literal);
			return ;
		case 4:
			printNan(literal);
			return ;
		case 5:
			printInf(literal);
			return ;
		default:
			std::cerr << "Arguments cannot take strings and have to be printable characters :)\n";	
	}
}