/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:49:52 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:40:21 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(const Dog &src) : Animal(src._type)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignment overload operator called" << std::endl;

	if (this != &src)
		this->_type = src._type;

	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << ": * Ouaf *" << std::endl;
	return;
}
