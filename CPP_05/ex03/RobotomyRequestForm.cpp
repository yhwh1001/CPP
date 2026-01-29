/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 23:04:11 by mcarvalh          #+#    #+#             */
/*   Updated: 2026/01/27 20:13:04 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
: AForm("Robotomy Request", 72, 45), _target(target) {
	if (_target.empty())
		throw std::invalid_argument("No empty strings please... try singing");
}

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy Request", 72, 45), _target("default") {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

const char* RobotomyRequestForm::ExecFormTooHigh::what() const throw() {
	return ("Robotomy is too high for this one... are you arleady a robot(?)");
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (this->getSigned() == false)
		throw FormNotSignedException();
	if (this->getGradeExec() < executor.getGrade())
		throw ExecFormTooHigh();
	std::cout << "BRr BRrRrrR bReerr robotizing...\n"
				<< executor.getName()
				<< " robotizing "
				<< _target 
				<< " is successful 50% of the time...\n\tUnless love previals(?)"
				<< std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotmized!!\n\t BEEP BOP BEEEEP" << std::endl;
	else
		std::cout << _target << " escaped cause only love brings love(?)" << std::endl; 
}