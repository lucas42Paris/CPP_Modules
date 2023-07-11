/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <lsalin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:12:19 by lsalin            #+#    #+#             */
/*   Updated: 2023/07/11 12:51:18 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

#define PRINT_MSG 0

const int	Convert::intMax = std::numeric_limits<int>::max();
const int	Convert::intMin = std::numeric_limits<int>::min();
const float	Convert::floatMax = std::numeric_limits<float>::max();
const float	Convert::floatMin = std::numeric_limits<float>::min();
const char	Convert::charMax = std::numeric_limits<char>::max();
const char	Convert::charMin = std::numeric_limits<char>::min();

Convert::Convert(void) : _type(DEFAULT),
						 _charType(0),
						 _intType(0),
						 _floatType(0),
						 _doubleType(0),
						 _errorFlags(OK)
{
	if (PRINT_MSG == 1)
		std::cout << "Convert default constructor called" << std::endl;
	return;
}

Convert::Convert(Convert const &src) : _type(src._type),
									   _charType(src._charType),
									   _intType(src._intType),
									   _floatType(src._floatType),
									   _doubleType(src._doubleType),
									   _errorFlags(src._errorFlags)
{
	if (PRINT_MSG == 1)
		std::cout << "Convert copy constructor called" << std::endl;
	return;
}

Convert::Convert(const std::string &input) : _type(DEFAULT),
											 _charType(0),
											 _intType(0),
											 _floatType(0),
											 _doubleType(0),
											 _errorFlags(OK)
{
	if (PRINT_MSG == 1)
		std::cout << "Convert input constructor called" << std::endl;

	this->_convertScalar(input);
	return;
}

Convert::~Convert(void)
{
	if (PRINT_MSG == 1)
		std::cout << "Convert destructor called" << std::endl;
	return;
}

Convert	&Convert::operator=(const Convert &src)
{
	if (PRINT_MSG == 1)
		std::cout << "Convert assignment operator overload called" << std::endl;

	this->_charType = src._charType;
	this->_intType = src._intType;
	this->_floatType = src._floatType;
	this->_doubleType = src._doubleType;
	this->_errorFlags = src._errorFlags;

	return (*this);
}

int	Convert::getIntType(void) const
{
	return (this->_intType);
}

float	Convert::getFloatType(void) const
{
	return (this->_floatType);
}

double	Convert::getDoubleType(void) const
{
	return (this->_doubleType);
}

char	Convert::getCharType(void) const
{
	return (this->_charType);
}

bool	Convert::_convertInputToInt(std::string const &input)
{
	char	*end;
	long	nb = std::strtol(input.c_str(), &end, 10);
	
	if (end == input.c_str() || *end != '\0')
		return (false);

	if (nb > intMax || nb < intMin)
	{
		_errorFlags += INT_OVERFLOW;
		return (false);
	}

	this->_intType = static_cast<int>(nb);
	return (true);
}

bool	Convert::_convertInputToFloat(std::string const &input)
{
	char	*end;
	float	nb = std::strtof(input.c_str(), &end);

	if (end == input.c_str() || *end != 'f')
		return (false);

	if (*end == 'f' && (end + 1 && *(end + 1) != '\0'))
		return (false);

	this->_floatType = nb;
	return (true);
}

bool	Convert::_convertInputToDouble(std::string const &input)
{
	char	*end;
	double	nb;
	size_t	pos;
	
	pos = input.find('.');

	if (pos == std::string::npos)
		return (false);

	nb = std::strtod(input.c_str(), &end);

	if (end == input.c_str() || *end != '\0')
		return (false);

	this->_doubleType = nb;
	return (true);
}

bool	Convert::_convertInputToChar(std::string const &input)
{
	if (input.length() == 1)
	{
		this->_charType = input[0];

		if (!std::isprint(input[0]))
			_errorFlags += CHAR_UNPRINTABLE;
		return (true);
	}
	return (false);
}

bool	Convert::_convertInputToNonNumeric(std::string const &input)
{
	if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff")
	{
		_errorFlags += INT_OVERFLOW;
		_errorFlags += CHAR_OVERFLOW;
		_floatType = std::numeric_limits<float>::infinity();
		_doubleType = std::numeric_limits<double>::infinity();

		return (true);
	}

	if (input == "-inf" || input == "-inff")
	{
		_errorFlags += INT_OVERFLOW;
		_errorFlags += CHAR_OVERFLOW;
		_floatType = (-1) * std::numeric_limits<float>::infinity();
		_doubleType = (-1) * std::numeric_limits<double>::infinity();

		return (true);
	}

	if (input == "nan" || input == "nanf")
	{
		_errorFlags += INT_OVERFLOW;
		_errorFlags += CHAR_OVERFLOW;
		_floatType = std::numeric_limits<float>::quiet_NaN();
		_doubleType = std::numeric_limits<double>::quiet_NaN();

		return (true);
	}

	return (false);
}

void	Convert::_extractType(std::string const &input)
{
	if (_convertInputToInt(input))
		this->_type = INTEGER;

	else if (_convertInputToFloat(input))
		this->_type = FLOAT;

	else if (_convertInputToDouble(input))
		this->_type = DOUBLE;

	else if (_convertInputToChar(input))
		this->_type = CHARACTER;

	else if (_convertInputToNonNumeric(input))
		this->_type = NOT_NUMBER;
}

void	Convert::_setConversionErrorFlags(void)
{
	switch (_type)
	{
		case INTEGER:
			if (this->_intType > charMax || this->_intType < charMin)
				this->_errorFlags += CHAR_OVERFLOW;
			break;

		case FLOAT:
			if (this->_floatType > charMax || this->_floatType < charMin)
				this->_errorFlags += CHAR_OVERFLOW;

			if (this->_floatType > intMax || this->_floatType < intMin)
				this->_errorFlags += INT_OVERFLOW;
			break;

		case DOUBLE:
			if (this->_doubleType > charMax || this->_doubleType < charMin)
				this->_errorFlags += CHAR_OVERFLOW;

			if (this->_doubleType > intMax || this->_doubleType < intMin)
				this->_errorFlags += INT_OVERFLOW;
			break;

		default:
			return;
	}
}

void	Convert::_convertIntToScalars(void)
{
	_setConversionErrorFlags();

	this->_floatType = static_cast<float>(this->_intType);
	this->_doubleType = static_cast<double>(this->_intType);
	this->_charType = static_cast<char>(this->_intType);
	
	if (!std::isprint(this->_charType))
		_errorFlags += CHAR_UNPRINTABLE;
}

void	Convert::_convertFloatToScalars(void)
{
	_setConversionErrorFlags();

	this->_intType = static_cast<int>(this->_floatType);
	this->_doubleType = static_cast<double>(this->_floatType);
	this->_charType = static_cast<char>(this->_floatType);
	
	if (!std::isprint(this->_charType))
		_errorFlags += CHAR_UNPRINTABLE;
}

void	Convert::_convertDoubleToScalars(void)
{
	_setConversionErrorFlags();

	this->_intType = static_cast<int>(this->_doubleType);
	this->_floatType = static_cast<float>(this->_doubleType);
	this->_charType = static_cast<char>(this->_doubleType);
	
	if (!std::isprint(this->_charType))
		_errorFlags += CHAR_UNPRINTABLE;
}

void	Convert::_convertCharToScalars(void)
{
	_setConversionErrorFlags();

	this->_intType = static_cast<int>(this->_charType);
	this->_floatType = static_cast<float>(this->_charType);
	this->_doubleType = static_cast<double>(this->_charType);
}

void	Convert::_convertScalar(std::string const &input)
{
	_extractType(input);

	switch (this->_type)
	{
		case INTEGER:
			_convertIntToScalars();
			break;

		case FLOAT:
			_convertFloatToScalars();
			break;

		case DOUBLE:
			_convertDoubleToScalars();
			break;

		case CHARACTER:
			_convertCharToScalars();
			break;

		case NOT_NUMBER:
			break;
	
		default:
			throw(Convert::NotAliteralException());			
	}
}

bool	Convert::isCharConversionOk(void) const
{
	if (this->_errorFlags & CHAR_OVERFLOW || this->_errorFlags & CHAR_UNPRINTABLE)
		return (false);
	return (true);
}

bool	Convert::isIntConversionOk(void) const
{
	if (this->_errorFlags & INT_OVERFLOW || this->_errorFlags & INT_OVERFLOW)
		return (false);
	return (true);
}

std::string	Convert::getCharConversionMessage(void) const
{
	if (this->_errorFlags & CHAR_OVERFLOW)
		return ("impossible");

	if (this->_errorFlags & CHAR_UNPRINTABLE)
		return ("not displayable");

	return ("unknown error");
}

std::string Convert::getIntConversionMessage(void) const
{
	if (this->_errorFlags & INT_OVERFLOW)
		return ("impossible");
	return ("unknown error");
}

const char *Convert::NotAliteralException::what(void) const throw()
{
	return (RED "Input is not a literal scalar type (char, int, float or double)" RESET);
}

std::ostream	&operator<<(std::ostream &os, const Convert &convert)
{
	os << "char\t: ";

	if (convert.isCharConversionOk() == true)
		os << "'" << convert.getCharType() << "'";
	else
		os << convert.getCharConversionMessage();

	os << "\nint\t: ";

	if (convert.isIntConversionOk() == true)
		os << convert.getIntType();
	else
		os << convert.getIntConversionMessage();

	os << "\nfloat\t: ";

	if (convert.getFloatType() == static_cast<int>(convert.getFloatType()))
		os << std::fixed << std::setprecision(1) << convert.getFloatType() << "f";
	else
		os << convert.getFloatType() << "f";

	os << "\ndouble\t: "
		<< convert.getFloatType();

	return (os);
}
