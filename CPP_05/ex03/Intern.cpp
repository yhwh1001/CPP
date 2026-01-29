/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:06:44 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/28 16:04:13 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {

}

AForm* Intern::makeForm(const std::string form_name, const std::string target) {
	std::string forms[3] = {"shrubbery request", "robotomy request", "presidential pardon"};

	int m = 0;
	while (m < 3 && forms[m] != form_name)
		m++;
	switch (m) {
		case 0:
			std::cout << "Intern creates magic light in " << form_name << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates magic light in " << form_name << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates magic light in " << form_name << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cerr << "Form " << form_name << " not found, is it a ghost?" << std::endl;
			return (NULL);
		
	}
		
}

