/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:45:36 by manelcarval       #+#    #+#             */
/*   Updated: 2026/02/03 19:53:33 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();	

	public:
	// public static - anyone can call method without object
	// satic method can only accesss static members 
		static void	convert(const std::string& literal);
};

// int		getType(const std::string &literal);
void	printChar(const std::string &literal);
void	printInt(const std::string &literal);
void	printFloat(const std::string &literal);
void	printDouble(const std::string &literal);

#endif