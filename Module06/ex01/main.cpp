/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:52:49 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/10 16:16:53 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data		data = {.value = 42, .string = "Hello World"};
	uintptr_t	pointerSerialiazed = serialize(&data);
	Data		*pointerDeserialized = deserialize(pointerSerialiazed);

	if (pointerDeserialized == &data)
		std::cout << GREEN "Serialization and deserialization completed successfully" RESET 
				  << std::endl << std::endl;

	else
		std::cout << RED "Serialization and deserialization failed" RESET 
				  << std::endl << std::endl;

	std::cout << "Original " << data << std::endl;
	std::cout << "Pointer to data structure serialized as int: " << pointerSerialiazed 
			  << std::endl << std::endl;

	std::cout << "Deserialized " << *pointerDeserialized << std::endl;

	return (0);
}
