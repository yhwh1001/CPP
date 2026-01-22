/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:57:53 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/22 15:17:15 by mcarvalh         ###   ########.fr       */
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
		
		//Getters
		const std::string	getName() const;
		int					getGrade() const;
		void 				Increment();
		void				Decrement();
		
		//Functions
		void  		signForm(Form& form);

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