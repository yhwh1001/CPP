/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:26:28 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/20 18:21:03 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	Bureaucrat::Increment() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else 
		_grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high... more water pls";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low... get them diamonds";
}

const std::string	Bureaucrat::getName() const {
	return (this->_name);	
}

int					Bureaucrat::getGrade() const {
	return (this->_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getGrade();
	return (os);
}

Bureaucrat::Bureaucrat(): _name("light"), _grade(150) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
	// this->_name = other._name;
	// this->_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}