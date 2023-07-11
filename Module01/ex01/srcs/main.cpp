/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:39:05 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:25:12 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	getNumberZombies(void)
{
	int	nbr;

	std::cout << "Choose a number of zombies for your horde" << std::endl << "> ";

	while (!(std::cin >> nbr) || nbr > MAX || nbr < MIN)
	{
		if (std::cin.eof())
			return (0);

		std::cout << "The number entered is invalid, it must be between " << MIN << " and " << MAX 
				  << std::endl << "> ";

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (nbr);
}

std::string getHordeName(void)
{
	std::string	name;

	std::cin.ignore();

	std::cout << "Choose a name for your horde" << std::endl << "> ";
	std::getline(std::cin, name);
	
	if (std::cin.eof())
		return (std::string());

	return (name);
}

int	main(void)
{
	int			nbr;
	std::string	name;

	nbr = getNumberZombies();
	name = getHordeName();

	Zombie	*horde = zombieHorde(nbr, name);

	if (!horde)
	{
		std::cout << "Error: horde creation failed"	<< std::endl;
		return (1);
	}

	for (int i = 0; i < nbr; i++)
		horde[i].announce();

	delete [] horde;
	return (0);
}
