/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 23:04:08 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/01/27 20:33:28 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5), _target("default") {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
 : AForm("Presidential Pardon", 25, 5), _target(target) {
	if (_target.empty())
		throw std::invalid_argument("EMPTY PROMISES... EMPTY PARDONS!!");
 }

 const char* PresidentialPardonForm::ExecFormTooHigh::what() const throw() {
	return ("Think more about the causality of your actions...\nPardon execution only for the higher-ups");
 }

 void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
	if (this->getSigned() == false)
		throw FormNotSignedException();
	if (this->getGradeExec() < executor.getGrade())
		throw ExecFormTooHigh();
	std::cout << "Her Highness Zaphod Beeblrbubblebrozinton with the esteem of "
			  << executor.getName()
			  << " pardons " 
			  << _target << " in all of its gracefulness :)" 
			  << std::endl;
	
 }

 