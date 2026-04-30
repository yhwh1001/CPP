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

BitcoinExchange::BitcoinExchange() {
	// _btc_data[NULL] = 0;
}

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
			_btc_data[date] = atof(value.c_str());
			// std::cout << _btc_data[date] << std::endl;
		}
	}
	myData.close();
}

bool BitcoinExchange::inputChecker(std::string line) {
	if (line.find(" | ") == std::string::npos)
	{
		std::cerr << "Error bad input: " << line << std::endl;
		return 0;
	}
	return 1;
}

static bool isLeapYear(int year) {
	if (year % 400 == 0)
		return true;
	else if (year % 4 == 0)
		return true;
	else
		return false;
} 

bool BitcoinExchange::checkDate(std::string date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
	{
		std::cerr << "Error wrong date format Year-Month-Day: " << date << std::endl;
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		if (date[4] || date[7])
			continue;
		if (!isdigit(date[i])) {
			std::cerr << "Error bad input: " << date << std::endl;
			return 0;
		}
	}
	int year = atoi(date.substr(0,4).c_str());
	int month = atoi(date.substr(5,2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if ((year < 2009 || year > 2022) || (month < 1 || month > 12) ||( day < 1 || day > 31))
	{
		std::cerr << "Error bad input: " << date << std::endl;
		return 0;
	}
	if (((month % 2 == 0 && day > 30) && month < 8 ) || ((month % 2 == 1 && day > 30) && month > 7))
	{
		std::cerr << "Error bad input: " << date << std::endl;
		return 0;
	}
	if (month == 2 ) {
		int maxDays = isLeapYear(year) ? 29 : 28;
		if (day > maxDays)
		{
			std::cerr << "Error bad input: " << date << std::endl;
			return 0;
		}
	}

	return 1;
}

bool BitcoinExchange::checkValue(std::string value, float &result) {
	(void) value;
	result = 3;
	return 1;
}

void BitcoinExchange::parseInput(std::string input) {
	std::ifstream inputFile(input.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return ;
	}
	std::string line;
	while (getline(inputFile, line)) 
	{
		if (inputChecker(line))
		{
			int pos;
			int end_pos;
			std::string date;
			std::string value;
			pos = line.find(' ');
			date = line.substr(0, pos);
			end_pos = line.find('\n');
			value = line.substr(pos + 3, end_pos);
			float result = 0;
			if (checkDate(date) && checkValue(value, result))
				std::cout << date << " => " << value << " = " << result << std::endl;


		}
	}
	inputFile.close();
}

