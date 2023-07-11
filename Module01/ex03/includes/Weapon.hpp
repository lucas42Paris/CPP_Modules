/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:45:38 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/04 12:09:32 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {

	private:
		std::string _type;

	public:
		Weapon(const std::string type);
		~Weapon(void);

		const std::string	&getType(void) const;
		void				setType(const std::string newType);
};

#endif