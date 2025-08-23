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
		static void		toChar(std::string literal);
		static void		toInt(std::string literal);
		static void		toFloat(std::string literal);
		static void		toDouble(std::string literal);
		static void		printEmpty();
	public:
		~ScalarConverter();
		static void convert(std::string literal);
};