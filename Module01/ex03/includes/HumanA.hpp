/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:45:30 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/04 12:10:05 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

# include "Weapon.hpp"

class HumanA {

	private:
		const std::string 	_name;
		const Weapon		&_weapon;

	public:
		HumanA(const std::string newName, const Weapon &newWeapon);
		~HumanA(void);

		void	attack(void) const;
};

#endif