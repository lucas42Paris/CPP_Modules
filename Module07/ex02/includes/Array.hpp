/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:13:24 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:54:46 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#define RED "\e[31m"
#define GREEN "\e[32m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define PURPLE "\e[35m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T = int>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}

		Array(const Array &src) : _array(new T[src._size]), _size(src._size) 
		{
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}

		~Array(void) {delete [] _array;}

		Array &operator=(const Array &src) 
		{
			if (this == &src)
				return (*this);

			if (this->_size != src._size) 
			{
				delete [] _array;
				this->_size = src._size;
				this->_array = new T[this->_size];
			}

			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
			return (*this);
		}

		class OutOfBoundsException : public std::exception 
		{
			public:
				virtual const char	*what(void) const throw() 
				{
					return ("Array out of bounds");
				}
		};

		T	&operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw(OutOfBoundsException());
			return (this->_array[index]);
		}

		unsigned int	size(void) const
		{
			return (this->_size);
		}
};

template<typename T>
std::ostream	&operator<<(std::ostream &os, Array<T> &obj)
{
	for (unsigned int i = 0; i < obj.size(); ++i) 
	{
		os << "[" << obj[i] << "] ";
	}
	return (os);
}

#endif