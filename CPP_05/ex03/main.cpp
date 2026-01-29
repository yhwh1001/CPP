/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:56:54 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/28 16:41:21 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void separator(std::string title)
{
	std::cout << "------------------------" << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

int	main() {
	srand(time(NULL));

	Bureaucrat bob("Bob", 42);
	Bureaucrat zoe("Zoe", 147);
	
	std::cout << zoe.getName() 
			  << ", a bureaucrat (crazy) with grade "
			  << zoe.getGrade()
			  << std::endl;
	std::cout << bob.getName() 
			  << ", a bureaucrat (crazy) with grade "
			  << bob.getGrade()
			  << std::endl;
	Intern	randomIntern;
	
	separator("SHRUBBERY TESTS");
	AForm*	shrubbery;
	shrubbery = randomIntern.makeForm("shrubbery request", "Beeendeer");
	std::cout << shrubbery << std::endl;

	try {
		shrubbery->execute(bob);
	}
	catch (const AForm::FormNotSignedException& e) {
		std::cerr << "Error: " << e.what() << std::endl; 
	}
	catch (const ShrubberyCreationForm::ExecFormTooHigh& e) {
		std::cerr << "Error: " << e.what() << std::endl; 
	}
	// Bob (grade 42) should be able to sign (42 <= 50)
	try {
		bob.signForm(*shrubbery);
		shrubbery->execute(bob);
	}
	catch (const AForm::FormNotSignedException& e) {
		std::cerr << "Error: " << e.what() << std::endl; 
	}
	catch (const ShrubberyCreationForm::ExecFormTooHigh& e) {
		std::cerr << "Error: " << e.what() << std::endl; 
	}
	// Zoe smaller grade
	try {
		shrubbery->execute(zoe);
	}
	catch (const ShrubberyCreationForm::ExecFormTooHigh& e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	// tryout new Form, exceptions
	try {
		AForm* tryout;
		tryout = randomIntern.makeForm("shrubbery request", "Zoe's try");
		zoe.signForm(*tryout);
		tryout->execute(zoe);
	}
	catch (const AForm::GradeTooHighException& e) {
		std::cerr << "Error: " << e.what() << std::endl; 
	}
	catch (const AForm::FormNotSignedException& e) {
		std::cerr << "Error: " << e.what() << std::endl; 
	}
	catch (const ShrubberyCreationForm::ExecFormTooHigh& e) {
		std::cerr << "Error: " << e.what() << std::endl; 
	}

	separator("ROBOTOMYYYY CRAZYYY");
	AForm* zoro_robot;
	zoro_robot = randomIntern.makeForm("robotomy request", "Zoro");
	std::cout << zoro_robot << std::endl;
	try {
		zoro_robot->execute(bob);
	}
	catch (const AForm::FormNotSignedException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		bob.signForm(*zoro_robot);
		zoro_robot->execute(bob);
	}
	catch (const AForm::FormNotSignedException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const RobotomyRequestForm::ExecFormTooHigh& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	try {
		zoe.signForm(*zoro_robot);
		zoro_robot->execute(zoe);
	}
	catch (const AForm::FormNotSignedException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const RobotomyRequestForm::ExecFormTooHigh& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	separator("PRESIDENTIAL PARDON FOR WHO???");
	AForm* presi;
	presi = randomIntern.makeForm("presidential pardon", "DARK FORCES");
	Bureaucrat king("Three-Eyed King", 1);
	std::cout << presi << std::endl;

	try {
		bob.signForm(*presi);
		presi->execute(king);
	}
	catch (const AForm::FormNotSignedException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		king.signForm(*presi);
		presi->execute(bob);
	}
	catch(const PresidentialPardonForm::ExecFormTooHigh& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		presi->execute(king);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		zoe.executeForm(*presi);	
	}
	catch (const PresidentialPardonForm::ExecFormTooHigh& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		king.executeForm(*presi);
	}
	catch (const PresidentialPardonForm::ExecFormTooHigh& e) {
		std::cerr << e.what() << std::endl;
	}
	

	delete shrubbery;
	delete zoro_robot;
	delete presi;
}