/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:57:52 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:44:05 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	createTestBureaucrat(std::string name, int grade)
{
	std::cout << std::endl << "Creating bureaucrat named \""
		<< name << "\" (grade: " << grade << ")" << std::endl;

	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat << " has been created" << std::endl;
		return;
	}

	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}

	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	std::cout << std::endl << YELLOW "[DEFAULT CONSTRUCTOR TEST]" RESET << std::endl;
	{
		Bureaucrat bureaucrat;
		std::cout << "Default bureaucrat is " << bureaucrat << std::endl;
	}

	std::cout << std::endl << YELLOW "[NAME/GRADE CONSTRUCTORS TESTS]" RESET;

	createTestBureaucrat("Lowkid", -40);
	createTestBureaucrat("Highkid", 200);
	createTestBureaucrat("Le boss", 1);
	createTestBureaucrat("Junior", 110);

	{
		std::cout << std::endl << YELLOW "[ASSIGNMENT OPERATOR TEST]" RESET << std::endl;
		Bureaucrat bureaucrat1("Aphrodite", Bureaucrat::lowestGrade);
		Bureaucrat bureaucrat2("Apollon", 89);

		std::cout << std::endl;

		std::cout << "Two bureaucrats have been created:\n"
			"\t" << bureaucrat1 << "\n"
			"\t" << bureaucrat2 << std::endl;

		std::cout << std::endl;

		bureaucrat1 = bureaucrat2;
		
		std::cout << GREEN "First bureaucrat = second bureaucrat\n" RESET << std::endl;
		std::cout <<	"\t" << bureaucrat1 << "\n"
						"\t" << bureaucrat2 << std::endl << std::endl;
	}

	{
		std::cout << std::endl << YELLOW "[INCREMENT/DECREMENT GRADE TEST]" RESET << std::endl;

		Bureaucrat bureaucrat("Right-Hand", 2);

		std::cout << RED "A bureaucrat called 'Right-Hand' has been created with grade 2" RESET << std::endl;

		try
		{
			std::cout << "Decrementing Right-Hand grade by 1 --> result should be " 
					  << bureaucrat.getGrade() + 1 << ":" << std::endl;

			bureaucrat.decrementGrade();
			std::cout << GREEN << bureaucrat << RESET << std::endl;

			std::cout << "Incrementing grade by 1 -> result should be " << bureaucrat.getGrade() - 1
					  << ":" << std::endl;

			bureaucrat.incrementGrade();
			std::cout << GREEN << bureaucrat << RESET << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}

		return (0);
	}
}
