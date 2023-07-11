/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:05:05 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:36:41 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), 
						   _hitPoints(ClapTrap::defaultHitPoints),
						   _energyPoints(ClapTrap::defaultEnergyPoints),
						   _attackDamage(ClapTrap::defaultAttackDamage) 
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name),
									   _hitPoints(ClapTrap::defaultHitPoints),
									   _energyPoints(ClapTrap::defaultEnergyPoints),
									   _attackDamage(ClapTrap::defaultAttackDamage) 
{
	std::cout << CYAN "ClapTrap " << name << " has been created" RESET << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap(void) 
{
	std::cout << CYAN "ClapTrap " << this->_name << " has been destroyed" RESET << std::endl;
	return;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
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

void	ClapTrap::attack(std::string &target) 
{
	if (this->_hitPoints == 0) 
	{
		std::cout << "ClapTrap " << this->_name << " can't attack (destroyed)" 
				  << std::endl;
		return;
	}

	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " does not have enough energy to attack" 
				  << std::endl;
		return;
	}

	if (target == this->_name)
		target = "itself";

	this->_energyPoints--;

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " 
			  << this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can no longer take damage"
				  << std::endl;
		return;
	}

	if ((int)this->_hitPoints - (int)amount <= 0) 
	{
		this->_hitPoints = 0;
		std::cout << RED "ClapTrap " << this->_name << " takes " << amount 
				  << " points of damage and is destroyed !" RESET << std::endl;
	}

	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" 
				  << std::endl;
	}
	return;
}

void	ClapTrap::beRepaired(unsigned int amount) 
{
	if (this->_hitPoints == 0) 
	{
		std::cout << "ClapTrap " << this->_name << " is too damaged to be repaired" << std::endl;
		return;
	}

	if (this->_energyPoints == 0) 
	{
		std::cout << "ClapTrap " << this->_name << " has no more energy points to be repaired"
				  << std::endl;
		return;
	}

	if ((this->_hitPoints + amount) > ClapTrap::defaultHitPoints)
		amount = ClapTrap::defaultHitPoints - this->_hitPoints;

	if (amount == 0)
	{
		this->_energyPoints--;

		std::cout << "ClapTrap " << this->_name << " does not need to be repaired"
				  << std::endl;
		return;
	}

	this->_energyPoints--;
	this->_hitPoints += amount;

	std::cout << GREEN "ClapTrap " << this->_name << " is repaired for " << amount << " points!" RESET
			  << std::endl;
	return;
}

std::string	ClapTrap::getName(void) const 
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const 
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const 
{
	return (this->_attackDamage);
}
