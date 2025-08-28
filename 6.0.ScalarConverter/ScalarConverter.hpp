/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:41:03 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/08/03 21:41:05 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter & src);
		ScalarConverter & operator=(const ScalarConverter & src);
		static void		isChar(char character);
		static void		isInt(std::string literal);
		static void		isFloat(std::string literal);
		static void		isDouble(std::string literal);
		static void		printError();
		static int		checkType(std::string literal);
		static bool		isNumericException(std::string literal);
		static bool		strIsAllNumeric(std::string str);
		static void		printNumericException(std::string literal, int type);
	public:
		~ScalarConverter();
		static void convert(std::string literal);
};