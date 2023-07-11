/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:06:31 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/25 12:35:23 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	return;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return;
}

Brain	&Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignment overload operator called" << std::endl;
	
	for (int i = 0; i < this->nbr_ideas; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}

const std::string	&Brain::getIdea(int index) const
{
	if (index < 0)
		index = 0;
	return (this->_ideas[index % (nbr_ideas - 1)]);
}

void	Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0)
		return;
	this->_ideas[index % (nbr_ideas - 1)] = idea;
	return;
}