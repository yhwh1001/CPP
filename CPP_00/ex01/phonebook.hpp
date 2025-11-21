/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:14:25 by manelcarval       #+#    #+#             */
/*   Updated: 2025/11/21 16:41:39 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "contact.hpp"

class Phonebook {
public:
		Phonebook();
		~Phonebook();

		void add_contact();
		void search_contact() const;
		void exit() const;

private:
		Contact contacts[8];
		int		counter;
		int		index;

};

#endif