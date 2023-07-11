/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:49:39 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/07 10:50:16 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) 
{
	std::string clapTrap1 = "Dark Vador";
	std::string clapTrap2 = "Obi-Wan";

	ClapTrap	trap1(clapTrap1);
	ClapTrap	trap2(clapTrap2);

	trap1.beRepaired(0);

	trap1.attack(clapTrap2);
	trap2.takeDamage(5);
	trap2.beRepaired(4);

	trap2.attack(clapTrap1);
	trap1.takeDamage(5);
	trap1.beRepaired(5000);
	trap2.beRepaired(5000);

	trap2.attack(clapTrap2);
	trap2.takeDamage(5000);
	trap2.beRepaired(5000);
	
	trap2.takeDamage(1);

	return (0);
}
