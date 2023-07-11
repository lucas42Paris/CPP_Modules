/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:36:04 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/08 09:56:28 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#define RED "\e[31m"
#define GREEN "\e[32m"
#define CYAN "\e[36m"
#define YELLOW "\e[33m"
#define RESET "\e[0m"

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(const Animal &src);
		Animal(const std::string &type);
		virtual ~Animal(void);

		Animal &operator=(const Animal &src);

		const std::string	&getType(void) const;
		virtual void		makeSound(void) const;
};

#endif
