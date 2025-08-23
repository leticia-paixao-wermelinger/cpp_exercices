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
	if (literal.size() == 0)
	{
		printEmpty();
		return ;
	}
	toChar(literal);
	toInt(literal);
	toFloat(literal);
	toDouble(literal);
}

void	ScalarConverter::toChar(std::string literal)
{
	int number;
	std::stringstream ss(literal);
	ss >> number;
	
	//std::cout << "ss.fail() = ", ss.fail();
	char	converted = static_cast<char>(number);
	std::cout << "char: ";
	if ((number <= 32) || (number >= 127))
	{
		
		if (literal == "nan")
		std::cout << "impossible" << std::endl;
		else
		std::cout << "Non displayable" << std::endl;
		
		return ;
	}
	std::cout << converted << std::endl;
}

void	ScalarConverter::toInt(std::string literal)
{
	std::stringstream ss(literal);
	long long number;
	ss >> number;
	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
	{
		std::cout << "int: nan" << std::endl;
		return ;
	}
	/*
	if (ss.fail()) {
		std::cout << "Conversão para int inválida\n";
	}
	*/
	std::cout << "int: ";
	std::cout << number << std::endl;
}

void	ScalarConverter::toFloat(std::string literal)
{
	std::stringstream ss(literal);
	long double floatNbr;
	ss >> floatNbr;
	if (floatNbr < std::numeric_limits<float>::min() || floatNbr > std::numeric_limits<float>::max())
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	/*
	if (ss.fail()) {
		std::cout << "Conversão para float inválida\n";
	}*/

	// VALIDAR nanf
	std::cout << "float: ";
	std::cout << floatNbr << "f" << std::endl;
}

void	ScalarConverter::toDouble(std::string literal)
{
	std::stringstream ss(literal);
	long double doubleNbr;
	ss >> doubleNbr;
	if (doubleNbr < std::numeric_limits<double>::min() || doubleNbr > std::numeric_limits<double>::max())
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	/*if (ss.fail()) {
		std::cout << "Conversão para double inválida\n";
	}*/
	std::cout << "double: ";
	std::cout << doubleNbr << std::endl;
}

void	ScalarConverter::printEmpty()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}