/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:12:17 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:52:04 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
#define CONVERT_H

#define RED "\e[31m"
#define RESET "\e[0m"

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class Convert
{
	private:
		enum	e_flags
		{
			OK = 0x00,
			INT_OVERFLOW = 0x01,
			CHAR_OVERFLOW = 0x02,
			CHAR_UNPRINTABLE = 0x04
		};

		enum	e_types
		{
			DEFAULT = 0,
			INTEGER,
			FLOAT,
			DOUBLE,
			CHARACTER,
			NOT_NUMBER
		};

		int		_type;
		char	_charType;
		int		_intType;
		float	_floatType;
		double	_doubleType;
		int		_errorFlags;

		void	_extractType(std::string const &input);
		bool	_convertInputToInt(std::string const &input);
		bool	_convertInputToFloat(std::string const &input);
		bool	_convertInputToDouble(std::string const &input);
		bool	_convertInputToChar(std::string const &input);
		bool	_convertInputToNonNumeric(std::string const &input);
		void	_convertIntToScalars(void);
		void	_convertFloatToScalars(void);
		void	_convertDoubleToScalars(void);
		void	_convertCharToScalars(void);
		void	_convertScalar(std::string const &input);
		void	_setConversionErrorFlags(void);

	public:
		Convert(void);
		Convert(Convert const &src);
		Convert(const std::string &input);
		~Convert(void);

		Convert	&operator=(const Convert &src);

		class NotAliteralException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		static const int	intMin;
		static const int	intMax;
		static const float	floatMin;
		static const float	floatMax;
		static const char	charMin;
		static const char	charMax;

		int			getIntType(void) const;
		float		getFloatType(void) const;
		double		getDoubleType(void) const;
		char		getCharType(void) const;

		bool		isCharConversionOk(void) const;
		bool		isIntConversionOk(void) const;

		std::string	getCharConversionMessage(void) const;
		std::string getIntConversionMessage(void) const;
};

std::ostream &operator<<(std::ostream &os, const Convert &converter);

#endif