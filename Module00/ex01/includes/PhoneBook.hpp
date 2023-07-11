/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:30:58 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/03 10:55:17 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {

	private:
		int		_index;
		int		_interrupt;
		Contact	_contacts[8];

		std::string	_getInput(const std::string prompt);
		void		_incrementIndex(void);
		int			_printContactByIndex(const std::string input) const;
		void		_printContactTable(void) const;
		void		_printContactInfoToTable(const int index) const;
		void		_printTableString(std::string str) const;

	public:

		PhoneBook(void);
		~PhoneBook(void);

		std::string	cleanBlank(std::string str);
		int			addContact(void);
		void		printContact(int index) const;
		int			searchContact(void);
};

#endif