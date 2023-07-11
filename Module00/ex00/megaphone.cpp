/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:42:20 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/03 10:30:07 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>

int	main(int argc, char **argv) 
{
	if (argc == 1) 
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++) 
	{
		for (unsigned int j = 0; j < strlen(argv[i]); j++) 
		{
			char c = argv[i][j];

			if (c >= 'a' && c <= 'z') 
				c -= 'a' - 'A';
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return (0);
}
