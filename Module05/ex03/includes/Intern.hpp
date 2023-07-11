/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:12:24 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:47:11 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		typedef struct s_data
		{
			const std::string	&formName;
			AForm				*(*function)(const std::string	&);
		}	t_data;

	public:
		Intern(void);
		Intern(const Intern &src);
		~Intern(void);

		Intern	&operator=(const Intern &src);
	
		AForm	*makeForm(std::string formName, std::string formTarget);

		class InvalidFormName : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif