/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:26:28 by manelcarval       #+#    #+#             */
/*   Updated: 2026/04/29 17:35:57 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getGrade();
	return (os);
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else 
		_grade = grade;
}

void	Bureaucrat::Increment() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}
 
void	Bureaucrat::Decrement() {
	if (_grade >= 150)
		throw GradeTooHighException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high...";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low...";
}

const std::string	Bureaucrat::getName() const {
	return (this->_name);	
}

int					Bureaucrat::getGrade() const {
	return (this->_grade);
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