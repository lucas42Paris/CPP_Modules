/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:50:28 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:56:37 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#define RED "\e[31m"
#define GREEN "\e[32m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define PURPLE "\e[35m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <list>
#include <deque>
#include <vector>

template<typename T>
typename T::const_iterator	easyfind(const T &container, const int element)
{
	typename T::const_iterator	it;
	it = std::find(container.begin(), container.end(), element); 

	if (it == container.end())
		throw (std::out_of_range("Element not found in container."));

	return (it);
}

#endif