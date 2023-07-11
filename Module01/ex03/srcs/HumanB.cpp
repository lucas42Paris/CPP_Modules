/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:45:44 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/04 12:50:42 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string newName) : _name(newName), _weapon(NULL)
{
	return;
}

HumanB::~HumanB()
{
	return;
}

void	HumanB::setWeapon(Weapon &newWeapon) 
{
	this->_weapon = &newWeapon;
}

void	HumanB::attack(void) const
{
	if (_weapon == NULL)
	{
		std::cout << _name << " has no weapon to attack with." << std::endl;
		return;
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;	
}
