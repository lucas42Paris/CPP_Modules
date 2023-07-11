/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:59:59 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:25:58 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void	Harl::_debug(void)
{
	std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" 
			  << std::endl << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. "
				 "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
			  << std::endl << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. "
				 "I've been coming for years whereas you started working here "
				 "since last month." << std::endl << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now."
			  << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void (Harl::*pointer)(void);

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	pointer		comments[4] = {&Harl::_debug, &Harl::_info,
								&Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*comments[i])();
			return;
		}
	}
	std::cout << RED "Error: [" << level << "] is not a level" RESET << std::endl; 
	return;
}
