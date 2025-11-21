/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:13:13 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/21 17:17:41 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() {
	
	//constructor implementation
	counter = 0;
	index = 0;

	std::cout << "Amazing phonebook created!!!" << std::endl;
}

Phonebook::~Phonebook() {
	//destructor
	std::cout << "Phonebook ist kaputt" << std::endl;
	return;
}

void	Phonebook::add_contact() {
	std::string first_Name;
	std::string last_Name;
	std::string nickName;
	std::string phone_Number;
	std::string darkest_Secret;
	
	std::cout << "Add a new contact..." << std::endl;
	std::getline(std::cin, first_Name);
	while (first_Name.empty()) {
		std::cout << "No empty fields allowed, please enter valid first name" << std::endl;
		std::getline(std::cin, first_Name);
	}
	
	std::cout << "Enter last Name..." << std::endl;
	std::getline(std::cin, last_Name);
	while (last_Name.empty()) {
		std::cout << "No empty fields allowed, please enter valid last name" << std::endl;
		std::getline(std::cin, last_Name);
	}
	
	std::cout << "Enter nickname..." << std::endl;
	std::getline(std::cin, nickName);
	while (nickName.empty()) {
		std::cout << "No empty fields allowed, please enter valid nickname" << std::endl;
		std::getline(std::cin, nickName);
	}

	std::cout << "Enter the phone number..." << std::endl;
	std::getline(std::cin, phone_Number);
	while (phone_Number.empty()) {
		std::cout << "No empty fields allowed, please enter valid phone number" << std::endl;
		std::getline(std::cin, phone_Number);
	}

	std::cout << "Enter your darkest secret... be careful what you wish for..." << std::endl;
	std::getline(std::cin, darkest_Secret);
	while (darkest_Secret.empty()) {
		std::cout << "No empty fields allowed, please your darkest secret" << std::endl;
		std::getline(std::cin, darkest_Secret);
	}
	
	Contact newContacts(first_Name, last_Name, nickName, phone_Number, darkest_Secret);
	if (counter < 8)
	{
		contacts[index] = newContacts;
		counter++;
		index++;
	}
	else
	{
		if (index % 8 == 0)
			index = 0;
		contacts[index] = newContacts;
		index++;
	}
}

void	Phonebook::search_contact() const {
	std::string	index;

	if (counter == 0) {
		std::cout << "Phonebook is empty. Add contacts first." << std::endl;
		return;
	}
	

	std::cout << "|" << std::setw(10) << "Index"
		  << "|" << std::setw(10) << "First Name"
		  << "|" << std::setw(10) << "Last Name"
		  << "|" << std::setw(10) << "Nickname"
		  << "|\n";

	for (int m = 0; m < counter; ++m) {
		std::cout << "|" << std::setw(10) << m;
		contacts[m].list_Contacts();
	}

	std::cout << "Please enter Contact Index to search" << std::endl;
	std::getline(std::cin, index);
	while(index.empty() || index.length() > 1 || index[0] < '0' || index[0] > '7') {
		if (index == "EXIT") {
			std::cout << "Exiting search." << std::endl;
			return;
		}
		std::cout << "Invalid index. Please enter a valid index or 'EXIT' to cancel " << std::endl;
	}
		contacts[index[0] - '0'].show_Contact();
}

void	Phonebook::exit() const {
	std::cout << "Hasta la vista, baby?" << std::endl;
}