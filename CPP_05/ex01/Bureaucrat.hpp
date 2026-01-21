/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:57:53 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/20 20:32:36 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <ostream>
#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
	
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void 				Increment();
		void				Decrement();
		std::string  		signForm(const Form& form);

		class GradeTooHighException : std::exception {
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : std::exception {
			public:	
				const char* what() const throw();	
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif