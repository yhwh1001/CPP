/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:08:17 by manelcarval       #+#    #+#             */
/*   Updated: 2026/04/29 18:04:18 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc [input bitcoin datasbase]" << std::endl;
		return 1;
	}
	std::string input_file = argv[1];
	if (input_file.find(".txt") == std::string::npos) {
		std::cerr << "Error: Input is not a .txt file" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	btc.loadDatabase();
	// btc.parseInput(argv[1]);
}