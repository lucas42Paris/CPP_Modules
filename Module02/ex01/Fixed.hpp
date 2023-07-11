/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:07:32 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/06 11:04:50 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed 
{
	private:
		int					_raw;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed(void);

		Fixed	&operator=(const Fixed &src);

		int 	getRawBits(void) const;
		void 	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &nb);

#endif