/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:00:26 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:22:56 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(-1), _interrupt(0)
{
	return;
}

PhoneBook::~PhoneBook(void) 
{
	return;
}

void	PhoneBook::_incrementIndex(void)
{
	_index++;
	
	if (_index > 7)
		_index = 0;
}

std::string	PhoneBook::cleanBlank(std::string str)
{
	std::string	blank = " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(blank);
	end = str.find_last_not_of(blank);

	if (start == end)
		return (str);

	return (str.substr(start, end - start + 1));
}

std::string	PhoneBook::_getInput(const std::string prompt)
{
	std::string	userInput;

	std::cout << "Enter " << prompt << ": " << std::endl << "> ";

	if (!std::getline(std::cin, userInput) || std::cin.eof())
	{
		_interrupt = 1;
		std::cout << std::endl;
		return (std::string());
	}

	userInput = cleanBlank(userInput);
	return (userInput);
}

void	PhoneBook::_printTableString(std::string str) const
{
	if (str.length() > 10) 
	{
		str.resize(9);
		str += ".";
	}

	std::cout << std::setw(10) << str << "|";
	return;
}

int	PhoneBook::_printContactByIndex(const std::string input) const
{
	int	index;

	if (input.length() == 1 && std::isdigit(input[0])) 
	{
		index = input[0] - '0';

		if (index >= 0 && index <= 7) 
		{
			if (this->_contacts[index].printContactInfos())
				return (1);

			else
			{
				std::cout << "Error: add contact and try again" << std::endl;
				return (0);
			}
		}
	}

	std::cout << "Error: not a valid index" << std::endl;
	return (0);
}

void	PhoneBook::_printContactInfoToTable(const int index) const
{
	if (this->_contacts[index].isEmpty())
		return;

	std::cout << "|" << std::setw(10) << index << "|";

	_printTableString(this->_contacts[index].getFirstName());
	_printTableString(this->_contacts[index].getLastName());
	_printTableString(this->_contacts[index].getNickname());

	std::cout	<< std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	return;
}

void	PhoneBook::_printContactTable(void) const
{
	std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;

	for (int i = 0; i < 8; i++)
		_printContactInfoToTable(i);

	std::cout << std::endl;
	return;
}

int	PhoneBook::addContact(void)
{
	std::string	userInput;
	_incrementIndex();
	
	while (!_interrupt)
	{
		userInput = _getInput("first name");

		if (_interrupt || this->_contacts[_index].setFirstname(userInput))
			break;
	}

	while (!_interrupt)
	{
		userInput = _getInput("last name");

		if (_interrupt || this->_contacts[_index].setLastname(userInput))
			break;
	}

	while (!_interrupt)
	{
		userInput = _getInput("nickname");
		
		if (_interrupt || this->_contacts[_index].setNickname(userInput))
			break;
	}

	while (!_interrupt)
	{
		userInput = _getInput("phone number");
		if (_interrupt || this->_contacts[_index].setPhoneNumber(userInput))
			break ;
	}

	while (!_interrupt)
	{
		userInput = _getInput("darkest secret");
		
		if (_interrupt || this->_contacts[_index].setDarkestSecret(userInput))
			break;
	}
	
	if (_interrupt)
	{
		_interrupt = 0;
		return (0);
	}
	
	std::cout << "Contact registered" << std::endl;
	return (1);
}

void	PhoneBook::printContact(int index) const
{
	if (index >= 0 && index <= 7) 
	{
		if (this->_contacts[index].printContactInfos())
			return;
	}

	std::cout << "Error: No record for the requested contact." << std::endl;
}

int	PhoneBook::searchContact(void)
{
	std::string userInput;

	if (_index == -1) 
	{
		std::cout << "Empty directory, add a contact before claiming to display one" << std::endl;
		return (1);
	}

	this->_printContactTable();
	userInput = _getInput("the index of the contact to display");
	
	if (userInput.empty())
		return (0);

	this->_printContactByIndex((const std::string)userInput);
	return (1);
}
