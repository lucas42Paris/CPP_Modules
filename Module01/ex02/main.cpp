/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:27:25 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/04 11:56:59 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	const std::string	str = "HI THIS IS BRAIN";
	const std::string	*stringPTR = &str;
	const std::string	&stringREF = str;

	std::cout	<< "Address of string:\t\t" << &str << "\n"
				<< "Address of stringPTR:\t\t" << stringPTR << "\n"
				<< "Address of stringREF:\t\t" << &stringREF << std::endl;

	std::cout 	<< "\n"
				<< "Value of string:\t\t[" << str << "]\n"
				<< "Value pointed to by stringPTR:\t[" << *stringPTR << "]\n"
				<< "Value pointed to by stringREF:\t[" << stringREF << "]" << std::endl;

	return (0);
}
