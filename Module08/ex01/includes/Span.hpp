/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:09:36 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:56:54 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#define RED "\e[31m"
#define GREEN "\e[32m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define PURPLE "\e[35m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <numeric>

class Span
{
	private:
		std::vector<int>	_range;
		unsigned int		_maxSize;

	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &src);
		~Span(void);

		Span &	operator=(const Span &src);

		void			addNumber(int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		const std::vector<int>	&getRange(void) const;

		template<typename T>
		void	addNumberRange(typename T::iterator &begin, typename T::iterator &end)
		{
			unsigned int	distance = std::distance(begin, end);

			if (distance > (this->_maxSize - this->_range.size()))
				throw (Span::FullRangeException());
			else if (distance != 0)
				this->_range.insert(this->_range.end(), begin, end);
			return ;
		}
		
		class	FullRangeException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
		class	RangeTooSmallException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
};

std::ostream &	operator<<(std::ostream &os, Span &obj);

#endif