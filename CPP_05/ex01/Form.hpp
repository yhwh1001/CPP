/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:22:58 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/20 20:34:32 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

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
		
		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
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


#endif