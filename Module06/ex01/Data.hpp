/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:48:47 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/10 16:08:20 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#define RED "\e[31m"
#define GREEN "\e[32m"
#define RESET "\e[0m"

#include <string>
#include <stdint.h>
#include <iostream>

struct	Data
{
	unsigned int	value;
	std::string		string;	
};

uintptr_t		serialize(Data *ptr);
Data			*deserialize(uintptr_t raw);
std::ostream	&operator<<(std::ostream &os, const Data &obj);

#endif