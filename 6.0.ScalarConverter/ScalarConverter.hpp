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

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter & src);
		ScalarConverter & operator=(const ScalarConverter & src);
		void	toChar(std::string literal);
		void	toInt(std::string literal);
		void	toFloat(std::string literal);
		void	toDouble(std::string literal);
	public:
		~ScalarConverter();
		static void convert(std::string literal);
};