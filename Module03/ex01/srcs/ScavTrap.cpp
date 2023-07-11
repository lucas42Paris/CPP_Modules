/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:02:58 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:37:21 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() 
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	
	this->_hitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
	this->_maxHitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	this->_maxEnergyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
	this->_maxAttackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
	
	return;
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name) 
{
	std::cout << CYAN "ScavTrap " << name << " has been created" RESET << std::endl;
	
	this->_hitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
	this->_maxHitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	this->_maxEnergyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
	this->_maxAttackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
	
	return;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap()
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << CYAN "ScavTrap " << this->_name << " has been destroyed" RESET << std::endl;
	return;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
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

void	ScavTrap::attack(std::string &target) 
{
	if (this->_hitPoints == 0) 
	{
		std::cout << "ScavTrap " << this->_name << " can't attack (destroyed)" 
				  << std::endl;
		return;
	}

	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " does not have enough energy to attack" 
				  << std::endl;
		return;
	}

	if (target == this->_name)
		target = "itself";

	_energyPoints--;

	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " 
			  << this->_attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << "doesn't have enough hit points to guard the gate" << std::endl;
	else
		std::cout << YELLOW << this->_name << " switch into Gatekeeper mode" RESET << std::endl;
	return;
}
