/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:14:49 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/08 10:33:31 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain 
{
	public:
		Brain(void);
		Brain(const Brain &src);
		~Brain(void);

		Brain	&operator=(const Brain &src);

		const std::string	&getIdea(int index) const;
		void				setIdea(int index, const std::string &idea);
	
		static const int	nbr_ideas = 100;
	
	protected:
		std::string	_ideas[nbr_ideas];
};

#endif
