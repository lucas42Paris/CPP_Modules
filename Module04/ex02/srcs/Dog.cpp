/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:49:55 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:41:29 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(const Dog &src) : Animal(), _brain(NULL)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignment overload operator called" << std::endl;

	if (this != &src)
	{
		this->_type = src._type;
		
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << CYAN << this->_type << ": * Ouaf *" RESET << std::endl;
	return;
}
