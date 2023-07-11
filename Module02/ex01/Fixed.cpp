/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:07:24 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:28:21 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::Fixed(const int i) : _raw(i << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(const float f) : _raw(roundf(f * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src)
		this->_raw = src.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_raw);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
	return;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_raw / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_raw >> Fixed::_fractionalBits);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &nb)
{
	os << nb.toFloat();
  	return (os);
}
