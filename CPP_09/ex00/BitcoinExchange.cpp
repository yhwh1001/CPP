/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:28:46 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/04/29 18:03:26 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other){
		_btc_data = other._btc_data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase() 
{
	std::ifstream myData("data.csv");
	if (myData.is_open()) 
	{
		std::string line;
		getline(myData, line);
		while(getline(myData, line)) 
		{
			// std::cout << line << std::endl;
			std::stringstream ss(line);
			std::string date;
			getline(ss, date, ',');
			std::string value;
			getline(ss, value, ',');
			_btc_data[date] = std::stof(value);
			// std::cout << _btc_data[date] << std::endl;
		}
		
	}
	myData.close();
}

// void BitcoinExchange::parseInput(std::string input) {
	
// }

