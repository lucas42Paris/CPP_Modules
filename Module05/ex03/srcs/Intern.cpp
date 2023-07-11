/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:13:13 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:48:24 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	return;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)src;
	return;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	return;
}

Intern	&Intern::operator=(const Intern &src)
{
	std::cout << "Intern assignment operator overload called" << std::endl;
	(void)src;
	return (*this);
}

static AForm	*createShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}


AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm	*formToCreate = NULL;

	static const t_data	formsArray[3] = 
	{
		{"shrubbery creation", createShrubberyCreationForm},
		{"robotomy request", createRobotomyRequestForm},
		{"presidential pardon", createPresidentialPardonForm}
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (formsArray[i].formName == formName)
		{
			formToCreate = formsArray[i].function(formTarget);
			std::cout << GREEN "Intern created " << *formToCreate << RESET << std::endl;
			return (formToCreate);
		}
	}

	std::cout << RED "Intern could'nt create form named " << formName << RESET;
	throw Intern::InvalidFormName();
}

const char *Intern::InvalidFormName::what(void) const throw()
{
	return ("Invalid form name");
}
