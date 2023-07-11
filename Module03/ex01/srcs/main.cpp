/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:49:39 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/07 13:12:12 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) 
{
	std::string scavTrapName = "Obi-Wan";
	std::string clapTrapName = "Dark Vador";

	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	clapTrap.attack(scavTrapName);
	scavTrap.takeDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE);

	scavTrap.attack(clapTrapName);
	clapTrap.takeDamage(SCAVTRAP_DEFAULT_ATTACK_DAMAGE);

	clapTrap.beRepaired(5000);
	scavTrap.guardGate();

	scavTrap.takeDamage(5000);

	return (0);
}
