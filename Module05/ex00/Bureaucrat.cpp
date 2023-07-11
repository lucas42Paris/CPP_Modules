/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:57:55 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:43:49 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Jean"), _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat default constructor called" RESET << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << CYAN "Bureaucrat copy constructor called" RESET << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), 
															 _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat name/grade constructor called" RESET << std::endl;

	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());

	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());

	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << CYAN "Bureaucrat destructor called" RESET << std::endl;
	return;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << CYAN "Bureaucrat assignment operator overload called" RESET << std::endl;
	this->_grade = src._grade;
	return (*this);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;

	if (this->_grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;

	if (this->_grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooHighException());
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("grade too low");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("grade too high");
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << "Bureaucrat \"" << obj.getName()
		<< "\" (grade: " << obj.getGrade() << ")";
	return (os);
}
