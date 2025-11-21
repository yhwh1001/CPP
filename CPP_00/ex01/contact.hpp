/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:18:11 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/21 16:58:40 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
public:
		Contact();
		Contact(
			const std::string &first_name,
			const std::string &last_name,
			const std::string &nickname,
			const std::string &phone_number,
			const std::string &darkest_secret);
		~Contact();

		void show_Contact() const;
		void list_Contacts() const;

private:
			std::string first_Name;
			std::string last_Name;
			std::string nickName;
			std::string phone_Number;
			std::string darkest_Secret;
};

#endif