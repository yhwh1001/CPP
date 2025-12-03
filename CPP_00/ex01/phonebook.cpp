/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:13:13 by manelcarval       #+#    #+#             */
/*   Updated: 2025/12/03 23:39:59 by manelcarval      ###   ########.fr       */
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
	if (!std::getline(std::cin, first_Name)) {
		std::cout << "\nInput cancelled." << std::endl;
		std::cin.clear();
		return;
	}
	while (first_Name.empty()) {
		std::cout << "No empty fields allowed, please enter valid first name" << std::endl;
		if (!std::getline(std::cin, first_Name)) {
			std::cout << "\nInput cancelled." << std::endl;
			std::cin.clear();
			return;
		}
	}

	std::cout << "Enter last Name..." << std::endl;
	if (!std::getline(std::cin, last_Name)) {
		std::cout << "\nInput cancelled." << std::endl;
		std::cin.clear();
		return;
	}
	while (last_Name.empty()) {
		std::cout << "No empty fields allowed, please enter valid last name" << std::endl;
		if (!std::getline(std::cin, last_Name)) {
			std::cout << "\nInput cancelled." << std::endl;
			std::cin.clear();
			return;
		}
	}

	std::cout << "Enter nickname..." << std::endl;
	if (!std::getline(std::cin, nickName)) {
		std::cout << "\nInput cancelled." << std::endl;
		std::cin.clear();
		return;
	}
	while (nickName.empty()) {
		std::cout << "No empty fields allowed, please enter valid nickname" << std::endl;
		if (!std::getline(std::cin, nickName)) {
			std::cout << "\nInput cancelled." << std::endl;
			std::cin.clear();
			return;
		}
	}

	std::cout << "Enter the phone number..." << std::endl;
	if (!std::getline(std::cin, phone_Number)) {
		std::cout << "\nInput cancelled." << std::endl;
		std::cin.clear();
		return;
	}
	while (phone_Number.empty()) {
		std::cout << "No empty fields allowed, please enter valid phone number" << std::endl;
		if (!std::getline(std::cin, phone_Number)) {
			std::cout << "\nInput cancelled." << std::endl;
			std::cin.clear();
			return;
		}
	}

	std::cout << "Enter your darkest secret... be careful what you wish for..." << std::endl;
	if (!std::getline(std::cin, darkest_Secret)) {
		std::cout << "\nInput cancelled." << std::endl;
		std::cin.clear();
		return;
	}
	while (darkest_Secret.empty()) {
		std::cout << "No empty fields allowed, please your darkest secret" << std::endl;
		if (!std::getline(std::cin, darkest_Secret)) {
			std::cout << "\nInput cancelled." << std::endl;
			std::cin.clear();
			return;
		}
	}

	Contact newContact(first_Name, last_Name, nickName, phone_Number, darkest_Secret);	
	if (counter < 8) {
		contacts[counter] = newContact;
		counter++;
	}
	else {
		for (int i = 0; i < 7; i++) {
			contacts[i] = contacts[i + 1];
		}
		contacts[7] = newContact;
	}

}

void	Phonebook::search_contact() const {
	std::string	input;

	if (counter == 0) {
		std::cout << "Phonebook is empty. Add contacts first." << std::endl;
		return;
	}


	std::cout << "|" << std::setw(10) << "Index"
		  << "|" << std::setw(10) << "First Name"
		  << "|" << std::setw(10) << "Last Name"
		  << "|" << std::setw(10) << "Nickname"
		  << "|\n";

	for (int i = 0; i < counter; ++i) {
		std::cout << "|" << std::setw(10) << i;
		contacts[i].list_Contacts();
	}

	std::cout << "Please enter Contact Index to search (0-" << counter - 1 << ") or 'EXIT' to cancel" << std::endl;
	if (!std::getline(std::cin, input)) {
		std::cout << "\nInput cancelled." << std::endl;
		return;
	}
	while(input.empty() || input.length() > 1 || input[0] < '0' || input[0] > '7') {
		if (input == "EXIT") {
			std::cout << "Exiting search." << std::endl;
			return;
		}
		std::cout << "Invalid index. Please enter a valid index (0-" << counter - 1 << ") or 'EXIT' to cancel" << std::endl;
		if (!std::getline(std::cin, input)) {
			std::cout << "\nInput cancelled." << std::endl;
			return;
		}
	}
	int selected_index = input[0] - '0';
	if (selected_index >= counter) {
		std::cout << "Contact at index " << selected_index << " does not exist. Only " << counter << " contact(s) saved." << std::endl;
		return;
	}
	contacts[selected_index].show_Contact();
}

void	Phonebook::exit() const {
	std::cout << "Hasta la vista, baby?" << std::endl;
}