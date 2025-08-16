/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:50 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/23 14:45:51 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

int main()
{
    std::cout << "empty:" << endl;
    ScalarConverter::convert("");
    std::cout << "char:" << endl;
    ScalarConverter::convert("a");
    ScalarConverter::convert("c");
    std::cout << endl;
    std::cout << "int:" << endl;
    ScalarConverter::convert("0");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    std::cout << endl;
    std::cout << "float:" << endl;
    ScalarConverter::convert("0.0f");
    ScalarConverter::convert("-4.2f");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("nanf");
    std::cout << endl;
    std::cout << "double:" << endl;
    ScalarConverter::convert("42.42");
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("-4.2");
    ScalarConverter::convert("4.2");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("nan");
    return 0;
}