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
    std::cout << std::endl << "----> char:" << std::endl;
    std::cout << "-> a:" << std::endl;
    ScalarConverter::convert("a");
    std::cout << "-> c:" << std::endl;
    ScalarConverter::convert("c");
    std::cout << std::endl;
    std::cout << std::endl << "----> int:" << std::endl;
    std::cout << "-> 0:" << std::endl;
    ScalarConverter::convert("0");
    std::cout << "-> 42:" << std::endl;
    ScalarConverter::convert("42");
    std::cout << "-> -42:" << std::endl;
    ScalarConverter::convert("-42");
    std::cout << std::endl;
    std::cout << std::endl << "----> float:" << std::endl;
    std::cout << "-> 0.0f:" << std::endl;
    ScalarConverter::convert("0.0f");
    std::cout << "-> 0.f:" << std::endl;
    ScalarConverter::convert("0.f");
    std::cout << "-> -4.2f:" << std::endl;
    ScalarConverter::convert("-4.2f");
    std::cout << "-> 4.2f:" << std::endl;
    ScalarConverter::convert("4.2f");
    std::cout << "-> -inff:" << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << "-> +inff:" << std::endl;
    ScalarConverter::convert("+inff");
    std::cout << "-> nanf:" << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << std::endl;
    std::cout << std::endl << "----> double:" << std::endl;
    std::cout << "-> 42.42:" << std::endl;
    ScalarConverter::convert("42.42");
    std::cout << "-> 0.0:" << std::endl;
    ScalarConverter::convert("0.0");
    std::cout << "-> -4.2:" << std::endl;
    ScalarConverter::convert("-4.2");
    std::cout << "-> 4.2:" << std::endl;
    ScalarConverter::convert("4.2");
    std::cout << "-> -inf:" << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << "-> +inf:" << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << "-> nan:" << std::endl;
    ScalarConverter::convert("nan");
    return 0;
}
*/

// subject
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: invalid number of arguments." << COLOR_END << std::endl;
        std::cerr << "Usage: ./convert <literal_value>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}