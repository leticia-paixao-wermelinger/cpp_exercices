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
	int integer = toInt(literal);
	char character = toChar(integer, literal);
	printChar(character);
	printInt(integer);
	float floatNbr = toFloat(literal);
	printFloat(floatNbr);
	double doubleNbr = toDouble(literal);
	printDouble(floatNbr);
}

char	ScalarConverter::toChar(int number, std::string literal)
{
	char	converted = static_cast<char>(number);
	if ((number >= 0 && number <= 32) || (number >= 127))
	{
		if (literal == "nan")
			std::cout << "impossible" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		return 0;
	}
	return converted;
}

int	ScalarConverter::toInt(std::string literal)
{
	std::stringstream ss(literal);
	int number;
	ss >> number;
	return number;
}

float	ScalarConverter::toFloat(std:string literal)
{
	float floatNbr;

	std::cout << floatNbr << std::endl;
}

double	ScalarConverter::toDouble(std:string literal)
{
	double number;

	return number;
}

void	ScalarConverter::printChar(char character)
{
	std::cout << "char: ";
	std::cout << character << std::endl;
}

void	ScalarConverter::printInt(int number)
{
	std::cout << "int: ";
	std::cout << number << std::endl;
}

void	ScalarConverter::printFloat(float number)
{
	std::cout << "float: ";
	std::cout << number << std::endl;
}

void	ScalarConverter::printDouble(double number)
{
	std::cout << "double: ";
	std::cout << number << std::endl;
}