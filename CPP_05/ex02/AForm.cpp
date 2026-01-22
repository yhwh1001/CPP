/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:35:00 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/22 23:23:27 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_grade_sign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

AForm::AForm()
	: _form("default"), _signed(false), _grade_sign(150), _grade_exec(150) {

}

AForm::AForm(const std::string form, const int grade_sign, const int grade_exec)
	: _form(form), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec) 
{
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
	else if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other): _form(other._form), _signed(other._signed), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec) {

}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		this->_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm() {

}

const std::string AForm::getName() const {
	return this->_form;
}

bool AForm::getSigned() const {
	return this->_signed;
}

int AForm::getGradeSign() const {
	return this->_grade_sign;
}

int AForm::getGradeExec() const {
	return this->_grade_exec;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Form Grade is too high... water may help(?)");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Form Grade is too low... dreaming may help(?)");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed... get higher");
}

const char* AForm::FormNotExecutedException::what() const throw() {
	return ("Form non-executable... start thinking before executing");
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form: " << form.getName()
	   << ", Signed: " << (form.getSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeSign()
	   << ", Grade to execute: " << form.getGradeExec();
	return os;
}

