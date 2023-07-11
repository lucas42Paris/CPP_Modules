/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:41:36 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:52:36 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	random = std::rand() % 3;

	switch(random)
	{
		case 0:
			std::cout << "Generated: " CYAN "A" RESET;
			return (new A);
		case 1:
			std::cout << "Generated: " YELLOW "B" RESET;
			return (new B);
		case 2:
			std::cout << "Generated: " PURPLE "C" RESET;
			return (new C);
	}
	return (NULL);
}

void	identify(Base *p)
{
	std::cout << "Identified as pointer: ";

	if (dynamic_cast<A *>(p))
		std::cout << CYAN "A" RESET;

	else if (dynamic_cast<B *>(p))
		std::cout << YELLOW "B" RESET;

	else if (dynamic_cast<C *>(p))
		std::cout << PURPLE "C" RESET;

	else
		std::cout << RED "Unknown" RESET;
}

void	identify(Base &p)
{
	std::cout << "Identified as reference: ";

	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << CYAN "A" RESET;
	}
	catch (std::exception &e) { }

	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << YELLOW "B" RESET;
	}
	catch (std::exception &e) { }

	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << PURPLE "C" RESET;
	}
	catch (std::exception &e) { }
}

int	main(void)
{
	Base	*p;
	std::srand(std::time(NULL));

	for (int i = 0; i < 8; i++)
	{
		std::cout << "Test [" << i << "]:\t";

		p = generate();
		std::cout << ", ";

		identify(p);
		std::cout << ", ";

		identify(*p);
		delete (p);

		std::cout << std::endl;
	}
	return (0);
}
