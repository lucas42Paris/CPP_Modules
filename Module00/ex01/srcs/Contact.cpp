/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:43:51 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:22:05 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("")
{
	return;
}

Contact::~Contact(void) 
{
	return;
}

int	Contact::_containsOnlyAlpha(const std::string str)
{
	for (std::string::const_iterator iterator = str.begin(); iterator != str.end(); iterator++)
	{
		if (std::isalpha(*iterator) == 0 && *iterator != ' ' && *iterator != '-')
			return (0);
	}
	return (1);
}

int	Contact::_containsOnlyDigits(const std::string str)
{
	for (std::string::const_iterator iterator = str.begin(); iterator != str.end(); iterator++)
	{
		if (std::isdigit(*iterator) == 0 && *iterator != ' ' && *iterator != '-')
			return (0);
	}
	return (1);
}

int	Contact::isEmpty(void) const
{
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty() 
								 || this->_phoneNumber.empty() || this->_darkestSecret.empty())
		return (1);
	return (0);
}

const std::string Contact::getFirstName(void) const
{
	return (_firstName);
}

const std::string Contact::getLastName(void) const
{
	return (_lastName);
}

const std::string Contact::getNickname(void) const
{
	return (_nickname);
}

const std::string Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

const std::string Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

int	Contact::setFirstname(std::string str)
{
	if (str.empty())
		return (0);

	else if (!_containsOnlyAlpha(str))
	{
		std::cout << "Format error" << std::endl;
		return (0);
	}

	str[0] = std::toupper(str[0]);
	this->_firstName = str;
	return (1);
}

int	Contact::setLastname(std::string str)
{
	if (str.empty())
		return (0);

	else if (!_containsOnlyAlpha(str))
	{
		std::cout << "Format error" << std::endl;
		return (0);
	}

	for (std::string::iterator iterator = str.begin(); iterator != str.end(); iterator++)
		*iterator = std::toupper(*iterator);
	
	this->_lastName = str;
	return (1);
}

int	Contact::setNickname(std::string str)
{
	if (str.empty())
		return (0);

	else if (!_containsOnlyAlpha(str))
	{
		std::cout << "Format error" << std::endl;
		return (0);
	}

	str[0] = std::toupper(str[0]);
	this->_nickname = str;
	return (1);
}

int	Contact::setPhoneNumber(const std::string str)
{
	if (str.empty())
		return (0);

	else if (!_containsOnlyDigits(str))
	{
		std::cout << "Format error" << std::endl;
		return (0);
	}

	this->_phoneNumber = str;
	return (1);
}

int	Contact::setDarkestSecret(const std::string str)
{
	if (str.empty())
		return (0);

	this->_darkestSecret = str;
	return (1);
}

int	Contact::printContactInfos(void) const
{
	if (this->isEmpty())
		return (0);
	
	std::cout << "First name\t: "	<< this->getFirstName()		<< std::endl
			  << "Last name\t: "	<< this->getLastName()		<< std::endl
			  << "Nickname\t: "		<< this->getNickname()		<< std::endl
			  << "Phone number\t: "	<< this->getPhoneNumber()	<< std::endl
			  << "Darkest secret\t: "	<< this->getDarkestSecret()	<< std::endl;

	return (1);
}
