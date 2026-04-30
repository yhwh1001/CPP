/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:56:54 by manelcarval       #+#    #+#             */
/*   Updated: 2026/04/29 17:35:08 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void separator(std::string title)
{
	std::cout << "------------------------" << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

int	main() {
	Bureaucrat bob("Bob", 42);
	Bureaucrat zoe("Zoe", 144);
	
	std::cout << zoe.getName() 
			  << ", a bureaucrat with grade "
			  << zoe.getGrade()
			  << std::endl;
	std::cout << bob.getName() 
			  << ", a bureaucrat with grade "
			  << bob.getGrade()
			  << std::endl;
	separator("THE EXCEPTIONS");
	try {
		Bureaucrat roland("Rolling", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat maximus("maximus", -1);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat minion("Minion", 160);
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}