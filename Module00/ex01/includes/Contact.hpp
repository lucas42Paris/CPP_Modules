/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:30:55 by lsalin            #+#    #+#             */
/*   Updated: 2023/02/03 10:31:22 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact {

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

		int _containsOnlyAlpha(const std::string str);
		int _containsOnlyDigits(const std::string str);

	public:
		Contact(void);
		~Contact(void);

		int isEmpty(void) const;

		const std::string getFirstName(void) const;
		const std::string getLastName(void) const;
		const std::string getNickname(void) const;
		const std::string getPhoneNumber(void) const;
		const std::string getDarkestSecret(void) const;

		int	setFirstname(std::string str);
		int	setLastname(std::string str);
		int	setNickname(std::string str);
		int	setPhoneNumber(const std::string str);
		int	setDarkestSecret(const std::string str);

		int	printContactInfos(void) const;
};

#endif