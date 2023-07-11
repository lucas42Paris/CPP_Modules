/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:01:12 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/07 13:19:15 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#define RED "\e[31m"
#define GREEN "\e[32m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define RESET "\e[0m"

#include <iostream>
#include <string>

#define CLAPTRAP_DEFAULT_HIT_POINTS 10
#define CLAPTRAP_DEFAULT_ENERGY_POINTS 10
#define CLAPTRAP_DEFAULT_ATTACK_DAMAGE 0

class ClapTrap {

	protected:
		ClapTrap(void);

		std::string 	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		unsigned int	_maxHitPoints;
		unsigned int	_maxEnergyPoints;
		unsigned int	_maxAttackDamage;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap(void);

		ClapTrap		&operator=(const ClapTrap &src);

		void			attack(std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
};

#endif