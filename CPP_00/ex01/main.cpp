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
		std::getline(std::cin, opt);
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