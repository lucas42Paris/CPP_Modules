/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:49:12 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:52:12 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

std::ostream	&operator<<(std::ostream &os, const Data &obj)
{
	os << "Data structure stored at address [" << &obj << "]"
		<< "\n\t- value : " << obj.value
		<< "\n\t- string: " << obj.string << std::endl;

	return (os);
}
