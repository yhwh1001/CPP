/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:35:00 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/20 20:36:35 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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