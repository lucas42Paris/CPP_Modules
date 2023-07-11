/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:45:18 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/10 20:11:20 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	multiplyIntByTwo(int & i)
{
	i *= 2;
	return ;
}

void	roundDouble(double & d)
{
	d = ::round(d);
	return ;
}

void	capitalizeChar(char & c)
{
	c = std::toupper(c);
	return ;
}

int main(void)
{
	{
		std::cout << std::endl << CYAN "[EMPTY ARRAY TEST]" RESET<< std::endl;

		int		array[] = {};
		size_t	size = 0;

		::printArray<int>(array, size);
		::iter<int>(array, size, ::multiplyIntByTwo);
		::printArray<int>(array, size);
	}

	{
		std::cout << std::endl << CYAN "[INT ARRAY TEST]" RESET<< std::endl;

		int		array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		size_t	size = 10;

		::printArray<int>(array, size);
		::iter<int>(array, size, ::multiplyIntByTwo);
		::printArray<int>(array, size);
	}

	{
		std::cout << std::endl << CYAN "[DOUBLE ARRAY TEST]" RESET<< std::endl;
		
		double 	array[] = {0.8, 1.765, 17.6};
		size_t	size = 3;

		::printArray<double>(array, size);
		::iter<double>(array, size, ::roundDouble);
		::printArray<double>(array, size);
	}

	{
		std::cout << std::endl << CYAN "[CHAR ARRAY TEST]" RESET<< std::endl;
		
		char 	array[] = {'a', 'b', 'c'};
		size_t	size = 3;
		
		::printArray<char>(array, size);
		::iter<char>(array, size, ::capitalizeChar);
		::printArray<char>(array, size);
	}
}
