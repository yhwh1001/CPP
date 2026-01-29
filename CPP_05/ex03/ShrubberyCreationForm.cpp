/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 23:04:17 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/01/27 17:22:01 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), _target("default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Shrubbery Creation", 145, 137), _target(target) 
{
	if (_target.empty())
		throw std::invalid_argument("Target empty... fill it with love(?)");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

const char* ShrubberyCreationForm::ExecFormTooHigh::what() const throw() {
	return "No shrubbery execution... get higher grade";
}

// const char* ShrubberyCreationForm::For::what() const throw() {

// }

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (this->getSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw ExecFormTooHigh();
	else {
		std::ofstream file((_target + "_shrubbery").c_str());
		if (!file.is_open())
			throw std::runtime_error("Cannot open shrubbery file...");
		file	<< "	     *\n"
				<< "		^^^\n"
				<< "	   ^^^^^\n"
				<< "	  ^^^^^^^\n"
				<< "	 ^^^^^^^^^\n"
				<< "	^^^^^^^^^^^\n"
				<< "   ^^^^^^||^^^^^\n"
				<< "		 ||" << std::endl;
		file.close();
		std::cout << "EXECUTE SHRUBBERY " << _target << std::endl;
	}
	
}

// std::ostream& operator<<(std::ostream& os, const AForm& form) {
// 	os << "Form: " << form.getName()
// 	   << ", Signed: " << (form.getSigned() ? "Yes" : "No")
// 	   << ", Grade to sign: " << form.getGradeSign()
// 	   << ", Grade to execute: " << form.getGradeExec();
// 	return os;
// }