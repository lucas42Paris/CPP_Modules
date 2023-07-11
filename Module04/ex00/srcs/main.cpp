/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:49:04 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:40:25 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	main_correct(void)
{
	std::cout << YELLOW "[RIGHT ANIMAL & CAT TESTS]" RESET << std::endl << std::endl;

	const Animal	*animal = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();

	std::cout << std::endl;

	delete dog;
	delete cat;
	delete animal;
}

void	main_wrong(void)
{
	std::cout << std::endl << YELLOW "[WRONG ANIMAL & CAT TESTS]" RESET << std::endl 
			  << std::endl;

	const WrongAnimal	*animal = new WrongAnimal();
	const WrongAnimal	*cat = new WrongCat();

	std::cout << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << std::endl;

	cat->makeSound();
	animal->makeSound();

	std::cout << std::endl;

	delete cat;
	delete animal;
}

int main(void)
{
	main_correct();
	main_wrong();

	return (0);
}
