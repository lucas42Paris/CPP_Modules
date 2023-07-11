/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:38:32 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:44:21 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form 
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;

	public:
		Form(void);
		Form(const Form &src);
		Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
		~Form(void);

		Form	&operator=(const Form &src);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class AlreadySignedException : public std::exception 
		{
			public:
				virtual const char	*what(void) const throw();
		};

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExecute(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &os, const Form &obj);

#endif