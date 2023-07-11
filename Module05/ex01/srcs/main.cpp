/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:47:02 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:45:14 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	createForms(std::string name, int gradeToSign, int gradeToExecute)
{
	std::cout << "\"" << name << "\" has been created (Required grade to sign = " << gradeToSign << 
	"; to execute = " << gradeToExecute << ")" << std::endl;

	try
	{
		Form form(name, gradeToSign, gradeToExecute);
		std::cout << CYAN << form << " successfully created" << RESET << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception : " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	std::cout << std::endl << YELLOW "[FORM DEFAULT CONSTRUCTOR TEST]" RESET << std::endl;
	{
		Form form;
		std::cout << "Default form is : " << form << std::endl;
	}

	std::cout << std::endl << YELLOW "[FORM ATTRIBUTE CONSTRUCTOR TEST]" RESET << std::endl;

	createForms("Basic Form", 78, 78);
	std::cout << std::endl;
	
	createForms("Signable/Executable Form", 150, 1);
	std::cout << std::endl;
	
	createForms("Unsignable Form", 180, 1);
	std::cout << std::endl;
	
	createForms("Unexecutable Form", -50, 200);

	{
		std::cout << std::endl << YELLOW "[FORM COPY CONSTRUCTOR TEST]" RESET << std::endl;

		Form form("Light Form", 78, 78);
		std::cout << CYAN << "Form is "<< form << RESET << std::endl;

		Form formCopy(form);
		std::cout << CYAN << "Form copy is "<< formCopy << RESET << std::endl;
	}

	{
		std::cout << std::endl << YELLOW "FORM ASSIGNMENT OPERATOR TEST" RESET << std::endl;

		Bureaucrat	bureaucrat("Francois", 42);

		Form form1("Form #1", Bureaucrat::lowestGrade, Bureaucrat::highestGrade);
		Form form2("Form #2", 42, 42);

		std::cout << std::endl << "Two forms created:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl << std::endl;

		bureaucrat.signForm(form2);

		std::cout << std::endl << "Form 2 signed:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl << std::endl;

		form1 = form2;

		std::cout << std::endl << "First form = second form:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl << std::endl;
	}

	{
		std::cout << std::endl << YELLOW "[BUREAUCRAT FORM SIGNING TEST]" RESET << std::endl;

		Bureaucrat junior("Junior", 150);
		Bureaucrat intermediate("Intermediate", 75);
		Bureaucrat ceo("CEO", 1);

		Form light("Light", 150, 150);
		Form moderate("Moderate", 75, 75);
		Form consistent("Consistent", 1, 1);

		std::cout << std::endl << "Three bureaucrats have been created:\n"
			"\t" << junior << "\n"
			"\t" << intermediate << "\n"
			"\t" << ceo << std::endl;

		std::cout << std::endl << "Attempting to sign " << light << ":" << std::endl;

		junior.signForm(light);
		intermediate.signForm(light);
		ceo.signForm(light);

		std::cout << std::endl << "Attempting to sign " << moderate << ":" << std::endl;

		junior.signForm(moderate);
		intermediate.signForm(moderate);
		ceo.signForm(moderate);

		std::cout << std::endl << "Attempting to sign " << consistent << ":" << std::endl;

		junior.signForm(consistent);
		intermediate.signForm(consistent);
		ceo.signForm(consistent);
		
		std::cout << std::endl;
	}

	return (0);
}
