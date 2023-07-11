/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:47:02 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/09 13:59:42 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat  junior("Junior", 142);
	Bureaucrat  intermediate("Intermediate", 65);
	Bureaucrat  ceo("Ceo", 1);

	std::cout << std::endl << "Three bureaucrats have been created:\n"
			"\t" << junior << "\n"
			"\t" << intermediate << "\n"
			"\t" << ceo << std::endl << std::endl;

	ShrubberyCreationForm	shrubbery("Alpes");
	RobotomyRequestForm		robotomy("Robotomy Request Form");
	PresidentialPardonForm	presidential("Presidential Pardon Form");

	std::cout << std::endl << "Three forms have been created:\n"
			"\t" << shrubbery << "\n"
			"\t" << robotomy << "\n"
			"\t" << presidential << std::endl;

	std::cout << std::endl << YELLOW "[SIGNING AND EXECUTING SHRUBBERY CREATION FORM]" RESET << std::endl;

	junior.signForm(shrubbery);
	junior.executeForm(shrubbery);
	ceo.executeForm(shrubbery);

	std::cout << std::endl << YELLOW "[SIGNING AND EXECUTING ROBOTOMY REQUEST FORM]" RESET << std::endl;

	intermediate.executeForm(robotomy);
	intermediate.signForm(robotomy);
	intermediate.executeForm(robotomy);
	ceo.executeForm(robotomy);

	std::cout << std::endl << YELLOW "[SIGNING AND EXECUTING PRESIDENTIAL PARDON FORM]" RESET << std::endl;

	ceo.executeForm(presidential);
	ceo.signForm(presidential);
	ceo.executeForm(presidential);

	std::cout << std::endl;

	return (0);
}
