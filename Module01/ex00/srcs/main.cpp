/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:34:27 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/03 12:53:22 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie	*michaelJakson = newZombie("Michaël Jakson");
	Zombie	*marilynManson = newZombie("Marilyn Manson");

	randomChump("Joker");
	randomChump("Robin");

	michaelJakson->announce();
	delete michaelJakson;

	marilynManson->announce();
	delete marilynManson;

	return (0);
}
