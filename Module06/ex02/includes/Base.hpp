/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:38:01 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/02 15:01:45 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

#define RED		"\e[31m"
#define YELLOW	"\e[33m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"
#define RESET	"\e[0m"

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
	public:
		virtual ~Base(void);	
};

#endif