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

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter & src)
{}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & src)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string literal)
{
	toChar(literal);
	toInt(literal);
	toFloat(literal);
	toDouble(literal);
}

void	ScalarConverter::toChar(std::string literal)
{
	if literal.size() != 1
		std::cout << "" << endl;
}