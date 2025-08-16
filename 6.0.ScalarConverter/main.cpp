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

#include <iostream>

/*
int main()
{
    std::cout << "empty:" << std::endl;
    ScalarConverter::convert("");
    std::cout << "char:" << std::endl;
    ScalarConverter::convert("a");
    ScalarConverter::convert("c");
    std::cout << std::endl;
    std::cout << "int:" << std::endl;
    ScalarConverter::convert("0");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    std::cout << std::endl;
    std::cout << "float:" << std::endl;
    ScalarConverter::convert("0.0f");
    ScalarConverter::convert("-4.2f");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("nanf");
    std::cout << std::endl;
    std::cout << "double:" << std::endl;
    ScalarConverter::convert("42.42");
    ScalarConverter::convert("0.0");
    ScalarConverter::convert("-4.2");
    ScalarConverter::convert("4.2");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("nan");
    return 0;
}
*/
/*
// char
int main()
{
    std::cout << "empty:" << std::endl;
    ScalarConverter::convert("");
    std::cout << "char:" << std::endl;
    ScalarConverter::convert("a");
    ScalarConverter::convert("c");
    std::cout << std::endl;
    return 0;
}*/

int main()
{
    std::cout << "5:" << std::endl;
    ScalarConverter::convert("5");
    std::cout << "6548:" << std::endl;
    ScalarConverter::convert("6548");
    std::cout << "0:" << std::endl;
    ScalarConverter::convert("0");
    std::cout << "nan:" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << "42.0f:" << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << std::endl;
    return 0;
}