/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:49:02 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:40:38 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Unknown")
{
	std::cout << "Animal default constructor called" << std::endl;
	return;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
	return;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
	return;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return;
}

Animal	&Animal::operator=(const Animal &src)
{
	std::cout << "Animal assignment overload operator called" << std::endl;

	if (this != &src)
		this->_type = src._type;
	return (*this);
}

const std::string	&Animal::getType(void) const
{
	return(this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << this->_type << CYAN ": * Sound *" RESET << std::endl;
	return;
}
