/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:45:21 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/10 19:59:25 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_H
#define ITER_H

#define CYAN "\e[36m"
#define RESET "\e[0m"

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

template<typename A, typename F>
void	iter(A *array, size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template<typename T>
void	printArray(T *array, size_t length)
{
	for (size_t i = 0; i < length; i++)
		std::cout << "[" << array[i] << "] ";
	std::cout << std::endl;
}

#endif