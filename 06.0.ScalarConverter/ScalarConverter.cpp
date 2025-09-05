/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:40:58 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/08/03 21:40:59 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <sstream>
#include <stdlib.h>
#include <limits>
#include <iomanip> // setprecision

enum	literalType
{
	CHAR_TYPE = 1,
	INT_TYPE = 2,
	FLOAT_TYPE = 3,
	DOUBLE_TYPE = 4
};

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter & src)
{
	(void)src;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string literal)
{
	if (isNumericException(literal))
		return ;
	// Verificar o tipo
	int	type = checkType(literal);
	// Dependendo do tipo, chamar uma função para lidar e imprimir tudo de acordo com o tipo inicial!
	switch (type)
	{
		case CHAR_TYPE:
			isChar(literal[0]);
			break;
		case INT_TYPE:
			isInt(literal);
			break;
		case FLOAT_TYPE:
			isFloat(literal);
			break;
		case DOUBLE_TYPE:
			isDouble(literal);
			break;
		default: // Se não for de nenhum dos tipos, imprime a função de erro (impossible em tudo)
			printError();
	}
}

int	ScalarConverter::checkType(std::string literal)
{
	int	type = 0;

	if (literal[literal.length()] == 'f' && literal.find('.') != std::string::npos && literal.length() > 2)
		type = FLOAT_TYPE;
	else if (literal.find('.') != std::string::npos && literal.length() > 1)
		type = DOUBLE_TYPE;
	else if (literal.length() == 1 && !std::isdigit(literal[0]))
		type = CHAR_TYPE;
	else if (literal.length() >= 1 && strIsAllNumeric(literal))
		type = INT_TYPE;
	//std::cout << "Detected type: " << type << std::endl;
	return type;
}

bool ScalarConverter::isNumericException(std::string literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		printNumericException(literal, FLOAT_TYPE);
		return true;
	}
	else if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		printNumericException(literal, DOUBLE_TYPE);
		return true;
	}
	return false;
}

bool ScalarConverter::strIsAllNumeric(std::string str)
{
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.length())
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool charIsDisplayable(int value)
{
	if (value < 33 || value > std::numeric_limits<char>::max())
		return false;
	return true;
}

void	ScalarConverter::isChar(char character)
{
	if (!isprint(character))
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: '" << character << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(character) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(character) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(character) << std::endl;
}

void	ScalarConverter::isInt(std::string literal)
{
	int	value = std::atoi(literal.c_str());
	if (charIsDisplayable(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	// validar mínimos e máximos
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void	ScalarConverter::isFloat(std::string literal)
{
	float value = std::atof(literal.c_str());
	if (charIsDisplayable(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	// validar mínimos e máximos
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void	ScalarConverter::isDouble(std::string literal)
{
	double value = std::atof(literal.c_str());
	if (charIsDisplayable(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	// validar mínimos e máximos
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void	ScalarConverter::printNumericException(std::string literal, int type)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal;
	if (type != FLOAT_TYPE)
		std::cout << "f" << std::endl;
	else
		std::cout << std::endl;
	std::cout << "double: ";
	if (type == DOUBLE_TYPE)
		std::cout << literal << std::endl;
	else
		std::cout << literal.substr(0, literal.length() - 1) << std::endl;
}

void	ScalarConverter::printError()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}