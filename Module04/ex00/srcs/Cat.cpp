/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:49:55 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:40:15 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	return;
}

Cat::Cat(const Cat &src) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignment overload operator called" << std::endl;

	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type << ": * Miaou *" << std::endl;
	return;
}
