/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:49:39 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/07 13:23:54 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) 
{
	std::string	fragTrapPersonnage = "Luke Skywalker";
	std::string scavTrapName = "Obi-Wan";
	std::string clapTrapName = "Dark Vador";

	FragTrap	fragTrap(fragTrapPersonnage);
	ScavTrap	scavTrap(scavTrapName);
	ClapTrap	clapTrap(clapTrapName);

	fragTrap.highFivesGuys();

	clapTrap.attack(scavTrapName);
	scavTrap.takeDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE);
	
	scavTrap.attack(fragTrapPersonnage);
	fragTrap.takeDamage(SCAVTRAP_DEFAULT_ATTACK_DAMAGE);
	
	fragTrap.beRepaired(5);
	scavTrap.guardGate();
	
	scavTrap.beRepaired(20);
	fragTrap.highFivesGuys();
	
	fragTrap.takeDamage(5000);
	fragTrap.highFivesGuys();
	
	return (0);
}
