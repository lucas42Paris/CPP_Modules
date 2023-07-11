/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestAForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:18:16 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/31 15:18:17 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 
												 RobotomyRequestForm::gradeToSign,
												 RobotomyRequestForm::gradeToExecute),
												 _target("Unknown")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src),
																		  _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 
																	  RobotomyRequestForm::gradeToSign, 
																	  RobotomyRequestForm::gradeToExecute), 
																	  _target(target)
{
	std::cout << "RobotomyRequestForm attribute constructor called" << std::endl;

	if (_target.empty())
		_target = "Unknown";
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->_target = src._target;
	return (*this);
}

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "* drill noise *" << std::endl;

	if (std::rand() % 2)
		std::cout << this->_target << " have been robotomized" << std::endl;
	else
		std::cout << this->_target << " haven't been robotomized" << std::endl;
}
