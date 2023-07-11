/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:45:41 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:25:30 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string newName, const Weapon &newWeapon) : _name(newName), _weapon(newWeapon)
{
	return;
}

HumanA::~HumanA()
{
	return;
}

void	HumanA::attack(void) const 
{
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
	return;
}
