/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:18:13 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/26 17:12:58 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/* other alternatives:
#include <iomanip>
std::cout << std::setw(10) << s; — this right-aligns to width 10 for output.
However, std::setw does not truncate; if s is longer than 10 it will print the whole string. 
To both truncate and align, you still need a truncation step (or a custom formatting function).

#include <iomanip>
helper: truncate to 10 chars (9 + '.')
static std::string truncate_field(const std::string &s) {
    if (s.length() > 10) return s.substr(0, 9) + ".";
    return s;
}

Then, in Contact::list_Contacts(), you can print without building temporary padded strings:
std::cout << "|" << std::setw(10) << truncate_field(first_Name)
          << "|" << std::setw(10) << truncate_field(last_Name)
          << "|" << std::setw(10) << truncate_field(nickName)
          << "|" << std::setw(10) << truncate_field(phone_Number)
          << "|" << std::setw(10) << truncate_field(darkest_Secret)
          << "|" << std::endl;

Notes:
- std::setw affects the next output operation only and will right-align by default.
- std::setw does NOT truncate long strings, so call truncate_field() first.
- Remember to #include <iomanip> at the top of the file when enabling this.
*/

// helper to format a field as a 10-char right-aligned column
// static std::string formatting(const std::string &s)
// {
// 	if (s.length() > 10)
// 		return s.substr(0, 9) + "."; // truncate, add '.'
// 	return (std::string(10 - s.length(), ' ') + s); 
// }

static std::string truncate_field(const std::string &s) {
    if (s.length() > 10)
		return s.substr(0, 9) + ".";
    return s;
}

Contact::Contact() {
	// default consytructor
}

Contact::Contact(
	const std::string &first_name,
	const std::string &last_name,
	const std::string &nickname,
	const std::string &phone_number,
	const std::string &darkest_secret) 
{
	first_Name = first_name;
	last_Name = last_name;
	nickName = nickname;
	phone_Number = phone_number;
	darkest_Secret = darkest_secret;	
}

void	Contact::show_Contact() const {
	std::cout << "First Name: " + first_Name << std::endl;
	std::cout << "Last Name: " << last_Name << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phone_Number << std::endl;
	std::cout << "The Darkest secret: " << darkest_Secret << std::endl;
}

void Contact::list_Contacts() const {
	// std::cout << "|" << formatting(first_Name)
	// 		  << "|" << formatting(last_Name)
	// 		  << "|" << formatting(nickName)
	// 		  << "|" << formatting(phone_Number)
	// 		  << "|" << formatting(darkest_Secret)
	// 		  << "|" << std::endl;
	std::cout << "|" << std::setw(10) << truncate_field(first_Name)
          << "|" << std::setw(10) << truncate_field(last_Name)
          << "|" << std::setw(10) << truncate_field(nickName)
        //   << "|" << std::setw(10) << truncate_field(phone_Number)
        //   << "|" << std::setw(10) << truncate_field(darkest_Secret)
          << "|" << std::endl;
}

Contact::~Contact() {
	// Desctructoooor
}
