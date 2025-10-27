/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:44:08 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/10/25 10:44:09 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <iomanip>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

void	ReversePolishNotation(std::string expression)
{
	RPN	notation(expression);
	notation.printExpression();
	std::cout << notation << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: could not open file." << COLOR_END << std::endl;
        std::cerr << "Usage: ./btc <file.txt>" << std::endl;
		return 0;
	}
	ReversePolishNotation(argv[1]);
	return 0;
}