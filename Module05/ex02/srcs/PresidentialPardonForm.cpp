/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonAForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:18:12 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/31 15:18:14 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form",
													   PresidentialPardonForm::gradeToSign,
													   PresidentialPardonForm::gradeToExecute),
													   _target("Unknown")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src),
																					_target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Presidential Pardon Form", 
																		   PresidentialPardonForm::gradeToSign,
																		   PresidentialPardonForm::gradeToExecute),
																		   _target(target)
{
	std::cout << "PresidentialPardonForm attribute constructor called" << std::endl;

	if (_target.empty())
		_target = "Unknown";

	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->_target = src._target;
	return (*this);
}

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << "Zaphod Beeblebrox forgive " << this->_target << std::endl;
	return;
}
