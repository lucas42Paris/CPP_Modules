/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:49:55 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:40:43 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), _brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	return;
}

Cat::Cat(const Cat &src) : Animal(), _brain(NULL)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignment overload operator called" << std::endl;

	if (this != &src)
	{
		this->_type = src._type;
		
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << CYAN << this->_type << ": * Miaou *" RESET << std::endl;
	return;
}
