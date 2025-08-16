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
		static char		toChar(int number, std::string literal);
		static int		toInt(std::string literal);
		static float	toFloat(std::string literal);
		//static double	toDouble(std::string literal);
		static void		printChar(char c);
		static void 	printInt(int number);
		static void		printFloat(float number);
		static void 	printDouble(double number);
	public:
		~ScalarConverter();
		static void convert(std::string literal);
};