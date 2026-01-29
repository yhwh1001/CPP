/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:56:54 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/23 16:36:18 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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
			  << ", a bureaucrat (crazy) with grade "
			  << zoe.getGrade()
			  << std::endl;
	std::cout << bob.getName() 
			  << ", a bureaucrat (crazy) with grade "
			  << bob.getGrade()
			  << std::endl;
	separator("THE EXCEPTIONS");
	try {
		Bureaucrat roland("Rolling", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat maximus("maximus", -1);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	try {
		Bureaucrat minion("Minion", 160);
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	separator("FORM TESTS");

	// Create a form that requires grade 50 to sign, grade 25 to execute
	Form taxForm("Tax Declaration", 50, 25);
	std::cout << taxForm << std::endl;

	// Bob (grade 42) should be able to sign (42 <= 50)
	bob.signForm(taxForm);
	std::cout << taxForm << std::endl;

	// Create a high-security form (requires grade 1)
	Form secretForm("Top Secret", 1, 1);
	std::cout << secretForm << std::endl;

	// Zoe (grade 144) cannot sign (144 > 1)
	zoe.signForm(secretForm);
	std::cout << secretForm << std::endl;

	separator("FORM EXCEPTIONS");

	// Try to create invalid forms
	try {
		Form invalidForm("Invalid", 0, 50);  // grade too high
	}
	catch (const Form::GradeTooHighException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Form invalidForm("Invalid", 50, 200);  // grade too low
	}
	catch (const Form::GradeTooLowException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}