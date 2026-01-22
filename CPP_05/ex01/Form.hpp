/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:22:58 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/21 17:05:56 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form 
{
	private:
		const std::string	_form;
		bool				_signed;
		const int 			_grade_sign;
		const int 			_grade_exec;

	public:
		Form();
		Form(const std::string form, const int grade_sign, const int grade_exec);
		Form(const Form& other);
		Form &operator=(const Form &other);
		~Form();
		
		//Getters
		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		
		//Functions
		void				beSigned(const Bureaucrat& bureaucrat);
		
		class GradeTooHighException : std::exception {
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : std::exception {
			public:	
				const char* what() const throw();	
		};
	
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif