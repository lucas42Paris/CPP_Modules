/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:38:32 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/31 19:41:07 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	protected:
		virtual void	beExecuted(void) const = 0;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;

	public:
		AForm(void);
		AForm(const AForm &src);
		AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
		virtual ~AForm(void);

		AForm	&operator=(const AForm &src);

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

		class NotSignedException : public std::exception 
		{
			public:
				const virtual char	*what(void) const throw();
		};

		const std::string	&getName(void) const;
		bool				isSigned(void) const;

		int					getGradeSign(void) const;
		int					getGradeExecute(void) const;

		void				beSigned(const Bureaucrat &bureaucrat);
		void				execute(const Bureaucrat &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &os, const AForm &obj);

#endif