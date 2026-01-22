/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:35:00 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/22 15:24:11 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_grade_sign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form Grade is too low... dreaming may help(?)");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form Grade is too high... water may help(?)");
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName()
	   << ", Signed: " << (form.getSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeSign()
	   << ", Grade to execute: " << form.getGradeExec();
	return os;
}

Form::Form(): _form("default"), _signed(false), _grade_sign(150), _grade_exec(150) {

}

Form::Form(const std::string form, const int grade_sign, const int grade_exec): _form(form), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec) {
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
	else if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other): _form(other._form), _signed(other._signed), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec) {

}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		this->_signed = other._signed;
	}
	return (*this);
}

Form::~Form() {

}

const std::string Form::getName() const {
	return this->_form;
}

bool Form::getSigned() const {
	return this->_signed;
}

int Form::getGradeSign() const {
	return this->_grade_sign;
}

int Form::getGradeExec() const {
	return this->_grade_exec;
}

