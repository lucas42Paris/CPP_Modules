/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationAForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:17:41 by lsalin            #+#    #+#             */
/*   Updated: 2023/01/31 15:23:12 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string					_target;
		static const std::string	_shrubbery;
		static const std::string	_shrubberyAlt;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		static const int	gradeToSign = 145;
		static const int	gradeToExecute = 137;

		const std::string	&getTarget(void) const;
		void				beExecuted(void) const;
};

#endif