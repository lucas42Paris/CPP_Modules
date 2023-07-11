/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:02:58 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/07 13:23:39 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() 
{
	std::cout << "FragTrap default constructor called" << std::endl;
	
	this->_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_maxHitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_maxEnergyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	this->_maxAttackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	
	return;
}

FragTrap::FragTrap(std::string &name) : ClapTrap(name) 
{
	std::cout << CYAN "FragTrap " << name << " has been created" RESET << std::endl;
	
	this->_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_maxHitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_maxEnergyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	this->_maxAttackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	
	return;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap()
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << CYAN "FragTrap " << this->_name << " has been destroyed" RESET << std::endl;
	return;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	if (this != &src) 
	{
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}

	return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    if (this->_hitPoints == 0)
        std::cout << this->_name << " is unable to ask for a high five" << std::endl;
    else
	    std::cout << YELLOW << this->_name << " is asking an high fives !" RESET << std::endl;
	return;
}
