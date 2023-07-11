/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:55:25 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:58:56 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#define RED "\e[31m"
#define GREEN "\e[32m"
#define BLUE "\e[34m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define PURPLE "\e[35m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

#include <iostream>
#include <ostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template < typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		typedef typename std::stack<T, C>::container_type::iterator					iterator;
		typedef typename std::stack<T, C>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T, C>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T, C>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack<T, C>(void) : std::stack<T, C>() {};
		MutantStack<T, C>(MutantStack<T, C> const & src) : std::stack<T, C>(src) {};
		~MutantStack<T, C>(void) {};

		MutantStack<T, C> &operator=(const MutantStack<T, C> &src) 
		{
			if (this != &src)
				this->c = src.c;
			return (*this);
		}

		MutantStack<T, C>::iterator	begin(void) {
			return (this->c.begin());
		}

		MutantStack<T, C>::iterator	end(void) {
			return (this->c.end());
		}

		MutantStack<T, C>::const_iterator	begin(void) const {
			return (this->c.begin());
		}

		MutantStack<T, C>::const_iterator	end(void) const {
			return (this->c.end());
		}

		MutantStack<T, C>::reverse_iterator	rbegin(void) {
			return (this->c.rbegin());
		}

		MutantStack<T, C>::reverse_iterator	rend(void) {
			return (this->c.rend());
		}

		MutantStack<T, C>::const_reverse_iterator	rbegin(void) const {
			return (this->c.rbegin());
		}

		MutantStack<T, C>::const_reverse_iterator	rend(void) const {
			return (this->c.rend());
		}
};

#endif