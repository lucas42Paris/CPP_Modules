/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:50:25 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:56:47 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void	search(std::string containerType, T &container, int toFind)
{
	std::cout << std::endl << "- Searching for " BOLD CYAN "[" << toFind << "]" RESET << std::endl;

	bool	expectToFind = false;
	int		result = 0;

	std::cout << containerType << " container: ";
	
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == toFind && expectToFind == false)
			{
				expectToFind = true;
				std::cout << BOLD YELLOW;
			}
		std::cout << "[" << *it << "] " RESET;
	}
	std::cout << std::endl;

	try
	{
		result = *(::easyfind(container, toFind));

		if (expectToFind == false)
			std::cout << RED BOLD "KO. " RESET
				RED "Easyfind found " << result << ". (Expected exception!)" RESET << std::endl;
		else
			std::cout << GREEN BOLD "OK. " RESET GREEN << "Found " << result << ", as expected." RESET << std::endl;
	}
	catch (std::exception &e)
	{
		if (expectToFind == false)
			std::cout << GREEN BOLD "OK. " RESET GREEN "Easyfind threw exception: " << e.what()
				<< ". (Expected exception.)" RESET << std::endl;
		else
			std::cout << RED BOLD "KO. " RESET RED "Easyfind threw exception: " << e.what()
				<< ". (Expected to find element in container!)" RESET << std::endl;
	}
}

int main(void)
{
	{
		std::cout << std::endl << "[VECTOR CONTAINER TEST]" << std::endl;

		std::vector<int>	container;
		std::cout << "Vector container: ";

		for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
			std::cout << "[" << *it << "]";
		std::cout << std::endl;

		::search("Vector", container, 0);
		std::cout << std::endl;

		for (int i = -4; i < 10; i++)
			container.push_back(i * 2);

		std::cout << "Vector container: ";

		for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		::search("Vector", container, 0);
		::search("Vector", container, 10);
		::search("Vector", container, -1);
	}
}
