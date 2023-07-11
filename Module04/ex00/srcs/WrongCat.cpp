/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:51:54 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/07 13:56:33 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
	return;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
	return;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat assignment overload operator called" << std::endl;

	if (this != &src)
		this->_type = src._type;

	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->_type << ": * Miaou *" << std::endl;
	return;
}
