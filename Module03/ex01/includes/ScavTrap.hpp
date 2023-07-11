/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:02:45 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/07 11:18:38 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

#define SCAVTRAP_DEFAULT_HIT_POINTS 100
#define SCAVTRAP_DEFAULT_ENERGY_POINTS 50
#define SCAVTRAP_DEFAULT_ATTACK_DAMAGE 20

class ScavTrap : public ClapTrap 
{
	private:
		ScavTrap(void);

	public:
		ScavTrap(std::string &name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap(void);

		ScavTrap	&operator=(const ScavTrap &src);
	
		void		attack(std::string &target);
		void		guardGate(void);
		
};

#endif