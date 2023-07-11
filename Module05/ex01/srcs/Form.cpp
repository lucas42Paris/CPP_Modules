/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:46:40 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:44:47 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) :	_name("Light Form"), _isSigned(false),
					_gradeRequiredToSign(Bureaucrat::lowestGrade), 
					_gradeRequiredToExecute(Bureaucrat::lowestGrade)
{
	std::cout << "Form default constructor called" << std::endl;
	return;
}

Form::Form(const Form &src) : _name(src._name),
							  _isSigned(false),
							  _gradeRequiredToSign(src._gradeRequiredToSign),
							  _gradeRequiredToExecute(src._gradeRequiredToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	return;
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name),
																					   _isSigned(false),
																					   _gradeRequiredToSign(gradeToSign),
																					   _gradeRequiredToExecute(gradeToExecute)
{
	std::cout << "Form attribute constructor called" << std::endl;

	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
		throw (Form::GradeTooHighException());

	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (Form::GradeTooLowException());

	return;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return;
}

Form	&Form::operator=(const Form &src)
{
	std::cout << "Form assignment operator overload called" << std::endl;
	this->_isSigned = src._isSigned;
	return (*this);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char	*Form::AlreadySignedException::what(void) const throw()
{
	return ("Form already signed");
}

std::string const &	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::isSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getGradeSign(void) const
{
	return (this->_gradeRequiredToSign);
}

int	Form::getGradeExecute(void) const
{
	return (this->_gradeRequiredToExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned != 0)
		throw (Form::AlreadySignedException());

	if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		throw (Form::GradeTooLowException());

	this->_isSigned = true;
}

std::ostream	&operator<<(std::ostream &os, const Form &obj)
{
	os << "\"" << obj.getName() << "\"" << "(Required grade to sign = " 
	   << obj.getGradeSign() << " && to execute = " << obj.getGradeExecute() << ")";

	return (os);
}
