/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:49:04 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:42:07 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define NBR_ANIMALS 4

void	AnimalArrayTest(void)
{
	std::cout << YELLOW "[ANIMAL ARRAY TEST]" RESET << std::endl << std::endl;

	Animal	*animalArray[NBR_ANIMALS + 1]; 
	animalArray[NBR_ANIMALS] = NULL;

	std::cout << "4 Animals objects have been created : 2 Dogs and 2 Cats" 
			  << std::endl << std::endl;

	for (int i = 0; i < NBR_ANIMALS / 2; i++)
		animalArray[i] = new Cat();

	std::cout << std::endl;

	for (int i = NBR_ANIMALS / 2; i < NBR_ANIMALS; i++)
		animalArray[i] = new Dog();

	std::cout << std::endl;

	for (int i = 0; animalArray[i] != '\0'; i++)
		animalArray[i]->makeSound();

	std::cout << std::endl;

	for (int i = 0; animalArray[i] != '\0'; i++)
		delete animalArray[i];

	std::cout << std::endl << "Animals array have been destroyed !" << std::endl;
}

void	CatCopyTest(void)
{
	std::cout << std::endl << YELLOW "[CAT COPY TEST]" RESET << std::endl << std::endl;

	Cat	*garfield = new Cat();

	std::cout << std::endl;

	garfield->getBrain()->setIdea(0, "Cooking pastas");
	garfield->getBrain()->setIdea(1, "Ski");
	garfield->getBrain()->setIdea(2, "Fly");

	std::cout << "First idea of Garfield : " << garfield->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Garfield : " << garfield->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Garfield : " << garfield->getBrain()->getIdea(2)	<< std::endl
																					<< std::endl;

	Cat	*garfieldCopy = new Cat(*garfield);

	std::cout << std::endl;

	std::cout << RED "Garfield copy ideas must be identical to garfield" RESET << std::endl << std::endl;

	std::cout << "First idea of Garfield copy : " << garfieldCopy->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Garfield copy : " << garfieldCopy->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Garfield copy : " << garfieldCopy->getBrain()->getIdea(2)	<< std::endl
																							<< std::endl;

	std::cout << RED "Updating garfield's ideas" RESET << std::endl << std::endl;
	
	garfield->getBrain()->setIdea(0, "Cooking pizzas");
	garfield->getBrain()->setIdea(1, "Snow");
	garfield->getBrain()->setIdea(2, "Navigate");

	std::cout << "First idea of Garfield : " << garfield->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Garfield : " << garfield->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Garfield : " << garfield->getBrain()->getIdea(2)	<< std::endl 
			  																		<< std::endl;

	std::cout << RED "Garfield's copy ideas must not have changed!" RESET << std::endl << std::endl;

	std::cout << "First idea of Garfield copy : " << garfieldCopy->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Garfield copy : " << garfieldCopy->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Garfield copy : " << garfieldCopy->getBrain()->getIdea(2)	<< std::endl
			  																				<< std::endl;

	*garfieldCopy = *garfield;

	std::cout << std::endl;

	std::cout << RED "Garfield copy ideas must now have been refreshed" RESET << std::endl << std::endl;

	std::cout << "First idea of Garfield copy : " << garfieldCopy->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Garfield copy : " << garfieldCopy->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Garfield copy : " << garfieldCopy->getBrain()->getIdea(2)	<< std::endl
			  																				<< std::endl;
	delete garfield;
	delete garfieldCopy;
}

void	DogCopyTest(void)
{
	std::cout << std::endl << YELLOW "[DOG COPY TEST]" RESET << std::endl << std::endl;

	Dog	*idefix = new Dog();

	std::cout << std::endl;

	idefix->getBrain()->setIdea(0, "Cooking pastas");
	idefix->getBrain()->setIdea(1, "Ski");
	idefix->getBrain()->setIdea(2, "Fly");

	std::cout << "First idea of Idefix : " << idefix->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Idefix : " << idefix->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Idefix : " << idefix->getBrain()->getIdea(2)	<< std::endl
																				<< std::endl;

	Dog	*idefixCopy = new Dog(*idefix);

	std::cout << std::endl;

	std::cout << RED "Idefix copy ideas must be identical to Idefix" RESET << std::endl << std::endl;

	std::cout << "First idea of Idefix copy : " << idefixCopy->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Idefix copy : " << idefixCopy->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Idefix copy : " << idefixCopy->getBrain()->getIdea(2)	<< std::endl
																						<< std::endl;

	std::cout << RED "Updating Idefix's ideas" RESET << std::endl << std::endl;

	idefix->getBrain()->setIdea(0, "Cooking pizzas");
	idefix->getBrain()->setIdea(1, "Snow");
	idefix->getBrain()->setIdea(2, "Navigate");

	std::cout << "First idea of Idefix : " << idefix->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Idefix : " << idefix->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Idefix : " << idefix->getBrain()->getIdea(2)	<< std::endl 
			  																	<< std::endl;

	std::cout << RED "Idefix copy ideas must not have changed!" RESET << std::endl << std::endl;

	std::cout << "First idea of Idefix copy : " << idefixCopy->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Idefix copy : " << idefixCopy->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Idefix copy : " << idefixCopy->getBrain()->getIdea(2)	<< std::endl
			  																			<< std::endl;

	*idefixCopy = *idefix;

	std::cout << std::endl;

	std::cout << RED "Idefix copy ideas must now have been refreshed" RESET << std::endl << std::endl;

	std::cout << "First idea of Idefix copy : " << idefixCopy->getBrain()->getIdea(0)	<< std::endl;
	std::cout << "Second idea of Idefix copy : " << idefixCopy->getBrain()->getIdea(1)	<< std::endl;
	std::cout << "Third idea of Idefix copy : " << idefixCopy->getBrain()->getIdea(2)	<< std::endl
			  																			<< std::endl;
	delete idefix;
	delete idefixCopy;
}

// void	AnimalInstanceTest(void)
// {
// 	Animal	*tiger = new Animal();
// 	tiger->makeSound();
// 	delete tiger;
// }

int	main(void)
{
	AnimalArrayTest();
	CatCopyTest();
	DogCopyTest();

	// AnimalInstanceTest(); // --> NOT COMPILE !
}
