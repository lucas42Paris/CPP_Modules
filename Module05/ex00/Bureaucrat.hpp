/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:57:57 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:43:59 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#define GREEN "\e[32m"
#define RED "\e[31m"
#define YELLOW "\e[33m"
#define CYAN "\e[36m"
#define RESET "\e[0m"

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &src);

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

		static const int 	highestGrade = 1;
		static const int	lowestGrade = 150;

		void				incrementGrade(void);
		void				decrementGrade(void);

		const std::string	&getName(void) const;
		int					getGrade(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj);

#endif