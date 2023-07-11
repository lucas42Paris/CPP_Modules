/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:46:40 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/31 19:42:25 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) :_name("Light Form"), 
					_isSigned(false),
					_gradeRequiredToSign(Bureaucrat::lowestGrade), 
					_gradeRequiredToExecute(Bureaucrat::lowestGrade)
{
	std::cout << "Form default constructor called" << std::endl;
	return;
}

AForm::AForm(const AForm &src) : _name(src._name),
							  	 _isSigned(false),
								 _gradeRequiredToSign(src._gradeRequiredToSign),
							 	 _gradeRequiredToExecute(src._gradeRequiredToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	return;
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name),
																					  	 _isSigned(false),
																					  	 _gradeRequiredToSign(gradeToSign),
																						 _gradeRequiredToExecute(gradeToExecute)
{
	std::cout << "Form attribute constructor called" << std::endl;

	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
		throw (AForm::GradeTooHighException());

	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (AForm::GradeTooLowException());

	return;
}

AForm::~AForm(void)
{
	std::cout << "Form destructor called" << std::endl;
	return;
}

AForm	&AForm::operator=(const AForm &src)
{
	std::cout << "Form assignment operator overload called" << std::endl;
	this->_isSigned = src._isSigned;
	return (*this);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char	*AForm::AlreadySignedException::what(void) const throw()
{
	return ("AForm already signed");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Form has not been signed");
}

std::string const &AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::isSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeSign(void) const
{
	return (this->_gradeRequiredToSign);
}

int	AForm::getGradeExecute(void) const
{
	return (this->_gradeRequiredToExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned != 0)
		throw (AForm::AlreadySignedException());

	if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		throw (AForm::GradeTooLowException());

	this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat &bureaucrat) const
{
	if (this->_isSigned == false)
		throw (AForm::NotSignedException());

	if (bureaucrat.getGrade() > this->_gradeRequiredToExecute)
		throw (AForm::GradeTooLowException());

	this->beExecuted();
}

std::ostream	&operator<<(std::ostream &os, const AForm &obj)
{
	os << "\"" << obj.getName() << "\"" << "(Required grade to sign = " 
	   << obj.getGradeSign() << " && to execute = " << obj.getGradeExecute() << ")";

	return (os);
}
