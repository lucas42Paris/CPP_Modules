/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:43:58 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:48:28 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	makeFormTest(std::string formName, std::string formTarget)
{
	std::cout << std::endl << YELLOW "[" << formName << " form have been created with \"" 
			  << formTarget << "\" as target]" RESET << std::endl;

	Intern		newIntern = Intern();
	Bureaucrat	ceo("CEO", 1);
	AForm		*form;

	try
	{
		form = newIntern.makeForm(formName, formTarget);
		ceo.signForm(*form);
		ceo.executeForm(*form);
		delete form;
	}
	catch(const std::exception &e)
	{
		std::cout << RED ": " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	const std::string	shrubberyFormName = "shrubbery creation";
	const std::string	robotomyFormName = "robotomy request";
	const std::string	presidentialFormName = "presidential pardon";

	makeFormTest(shrubberyFormName, "IratyForest");
	makeFormTest(robotomyFormName, "Husqvarna drill");
	makeFormTest(presidentialFormName, "Emmanuel Macron");
	makeFormTest("njwfjndjk", "mwjfkefjkne");

	return (0);
}
