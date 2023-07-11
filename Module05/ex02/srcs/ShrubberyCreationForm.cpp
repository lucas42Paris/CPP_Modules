/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationAForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:18:19 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/31 15:18:50 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 
														   ShrubberyCreationForm::gradeToSign,
														   ShrubberyCreationForm::gradeToExecute),
														   _target("Unknown")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), 
																				 _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("Shrubbery Creation Form", 
  		ShrubberyCreationForm::gradeToSign,
		ShrubberyCreationForm::gradeToExecute),
		_target(target)
{
	std::cout << "ShrubberyCreationForm attribute constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->_target = src._target;
	return (*this);
}

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	ofs;

	ofs.open((this->_target + "_shrubbery").c_str(), std::ofstream::out | std::ostream::app);

	if (ofs.is_open())
	{
		if (std::rand() % 2)
			ofs << ShrubberyCreationForm::_shrubbery;
		else
			ofs << ShrubberyCreationForm::_shrubberyAlt;

		std::cout << "Congrats ! A pretty shrubbery has been planted at " << _target << "_shrubbery." 
				  << std::endl;
		ofs.close();
	}
}

const std::string	ShrubberyCreationForm::_shrubbery =
"\n"
"                %%%,%%%%%%%\n"
"                 ,'%% \\\\-*%%%%%%%\n"
"           ;%%%%%*%   _%%%%\"\n"
"            ,%%%       \\(_.*%%%%.\n"
"            % *%%, ,%%%%*(    '\n"
"          %^     ,*%%% )\\|,%%*%,_\n"
"               *%    \\/ #).-\"*%%*\n"
"                   _.) ,/ *%,\n"
"           _________/)#(_____________\n\n";

const std::string	ShrubberyCreationForm::_shrubberyAlt =
"\n"
"           \\/ |    |/\n"
"        \\/ / \\||/  /_/___/_\n"
"         \\/   |/ \\/\n"
"    _\\__\\_\\   |  /_____/_\n"
"           \\  | /          /\n"
"  __ _-----`  |{,-----------~\n"
"            \\ }{\n"
"             }{{\n"
"             }}{\n"
"             {{}\n"
"       , -=-~{ .-^- _\n"
"             `}\n"
"              {\n\n";
