/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:07:24 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:28:58 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
	return;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
	return;
}

Fixed::Fixed(const int i) : _raw(i << _fractionalBits)
{
	return;
}

Fixed::Fixed(const float f) : _raw(roundf(f * (1 << _fractionalBits)))
{
	return;
}

Fixed::~Fixed(void)
{
	return;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
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

bool	Fixed::operator>(const Fixed &rhs) const
{	
	return (this->_raw > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_raw < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_raw >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_raw <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_raw == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_raw != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->_raw += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++(*this);
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->_raw -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--(*this);
	return (temp);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
  	return (os);
}
