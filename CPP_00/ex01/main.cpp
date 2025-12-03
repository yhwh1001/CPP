/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:41:29 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/21 17:19:14 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main() {
	Phonebook	book;
	std::string	opt;

	while (1)
	{
		std::cout << "\nMy Awesome Phonebook :)" << std::endl;
		std::cout << "Select option: ADD, SEARCH or EXIT" << std::endl;
		if (!std::getline(std::cin, opt)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting..." << std::endl;
				break;
			}
			if (std::cin.bad()) {
				std::cout << "Unrecoverable stream error. Exiting..." << std::endl;
				break;
			}
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Input error occurred. Please try again." << std::endl;
				continue;
			}
		}
		if (opt.empty()) {
			std::cout << "Empty input. Please enter ADD, SEARCH or EXIT" << std::endl;
			continue;
		}
		if (opt == "ADD")
			book.add_contact();
		else if (opt == "SEARCH")
			book.search_contact();
		else if (opt == "EXIT")
		{
			book.exit();
			break;
		}
		else
			std::cout << "Incorrect option" << std::endl;
	}
	return 0;
}