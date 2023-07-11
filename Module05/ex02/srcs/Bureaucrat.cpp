/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:57:55 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:46:20 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Random"), _grade(Bureaucrat::lowestGrade)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), 
															 _grade(Bureaucrat::lowestGrade)
{
	std::cout << "Bureaucrat name/grade constructor called" << std::endl;

	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());

	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());

	else
		this->_grade = grade;

	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat assignment operator overload called" << std::endl;
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
	return ("Grade too low");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too high");
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}


int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << *this << " has signed " << form << RESET << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << RED << *this << " can't sign " << form << " because : " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << *this << " have executed " << form << RESET << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << RED << *this << " couldn't executed " << form << " because : " << e.what()
				  << RESET << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << "Bureaucrat " << obj.getName() << " (grade : " << obj.getGrade() << ")";
	return (os);
}
