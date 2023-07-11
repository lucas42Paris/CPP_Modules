/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:27:20 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:22:14 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	getInput(PhoneBook *book)
{
	std::string	userInput;

	if (!std::getline(std::cin, userInput) || std::cin.eof())
	{
		std::cout << "EXIT" << std::endl;
		return ("EXIT");
	}

	userInput = book->cleanBlank(userInput);

	for (std::string::iterator iterator = userInput.begin(); iterator != userInput.end(); iterator++)
		*iterator = std::toupper(*iterator);

	return (userInput);
}

int	main(void)
{
	PhoneBook	book;
	std::string	userInput;

	while (true)
	{	
		std::cout 	<< std::endl
					<< "+---------------- Main Menu ----------------+" << std::endl
					<< std::endl
					<< "What would you like to do?" << std::endl << "> ";

		userInput = getInput(&book);

		if (userInput == "EXIT")
			break;

		else if (userInput == "ADD") 
		{
			if (!book.addContact())
				break ;
		}

		else if (userInput == "SEARCH") 
		{
			if (!book.searchContact())
				break;
		}

		else
		{
			std::cout << "Choose a command among the following:" << std::endl
					  << "\tADD\t: add a contact" << std::endl
					  << "\tSEARCH\t: search contact list" << std::endl
					  << "\tEXIT\t: quit the programm" << std::endl;
		}
	}
	return (0);
}
