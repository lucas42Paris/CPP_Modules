/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:45:49 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/04 12:10:23 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : _type(type)
{
    return;
}

Weapon::~Weapon(void) 
{
    return;
}

const	std::string	&Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(const std::string newType)
{
    this->_type = newType;
	return;
}
