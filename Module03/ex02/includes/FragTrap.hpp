/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:10:27 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/13 13:23:25 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

#define FRAGTRAP_DEFAULT_HIT_POINTS 100
#define FRAGTRAP_DEFAULT_ENERGY_POINTS 100
#define FRAGTRAP_DEFAULT_ATTACK_DAMAGE 30

class FragTrap : public ClapTrap 
{
	private:
		FragTrap(void);

	public:
		FragTrap(std::string &name);
		FragTrap(const FragTrap &src);
		~FragTrap(void);

		FragTrap	&operator=(const FragTrap &src);
	
		void		highFivesGuys(void);
};

#endif