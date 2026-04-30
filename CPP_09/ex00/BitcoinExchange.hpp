/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:28:46 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/04/29 15:25:00 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange {
	public:
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange& other);
			BitcoinExchange& operator=(const BitcoinExchange& other);
			~BitcoinExchange();

			void loadDatabase();
			void parseInput(std::string input);
	
	private:
			std::map<std::string, float>	_btc_data;
			// int*							_value;
			bool	checkDate(std::string date);
			bool	checkValue(std::string value, float &result);
			

};

#endif
