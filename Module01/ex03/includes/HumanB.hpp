/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:45:35 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/11 13:58:50 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"

class HumanB {

	private:
		const std::string	_name;
        Weapon				*_weapon;

	public:
        HumanB(const std::string newName);
		~HumanB(void);

		void	attack(void) const;
        void	setWeapon(Weapon &newWeapon);
};

#endif