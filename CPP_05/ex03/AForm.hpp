/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:22:58 by manelcarval       #+#    #+#             */
/*   Updated: 2026/01/27 17:18:40 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm 
{
	private:
		const std::string	_form;
		bool				_signed;
		const int 			_grade_sign;
		const int 			_grade_exec;

	public:
		AForm();
		AForm(const std::string form, const int grade_sign, const int grade_exec);
		AForm(const AForm& other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		
		//Functions
		virtual void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor) const = 0;
		//Getters
		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		
		class GradeTooHighException : std::exception {
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : std::exception {
			public:	
				const char* what() const throw();	
		};

		class FormNotSignedException : std::exception {
			public:
				const char* what() const throw();
		};

		// class FormNotExecutedException : std::exception {
		// 	public:
		// 		const char* what() const throw();
		// };
	
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif