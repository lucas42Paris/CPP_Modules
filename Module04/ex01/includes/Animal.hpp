/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:58:27 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/25 12:37:54 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#define YELLOW "\e[33m"
#define RED "\e[31m"
#define CYAN "\e[36m"
#define RESET "\e[0m"

#include <string>

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
