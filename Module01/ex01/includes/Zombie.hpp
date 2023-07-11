/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:32:50 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/04 11:22:59 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>
#include <limits>

#define	MIN -50000
#define MAX 50000

class Zombie {

	private: 
		std::string	_name;
		std::string	_getName(void) const;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	setName(const std::string name);
		void	announce(void);
};

#endif