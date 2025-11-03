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

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

void	errorHandler(const char *message)
{
	std::cerr << RED << message << COLOR_END << std::endl;
	exit(1);
}

std::vector<int> createVector(int argc, char *str[], std::vector<int> &vec)
{
	for (int i = 1; i < argc; i++)
	{
		char *token = str[i];
		if (!token)
			errorHandler("Error: invalid entry");
		else if (token[0] == '-')
			errorHandler("Error: negative numbers are not allowed");
		int num = atoi(token);
		if (num > 0)
			vec.push_back(num);
		else if (num == 0 && strcmp(token, "0") != 0)
			errorHandler("Error: invalid entry");
		else if (num == 0 && strcmp(token, "0") == 0)
			errorHandler("Error: zero is not allowed");
		std::cerr << num << " ";
	}
	std::cerr << std::endl;
	return vec;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << RED << "Error: not enough numbers to sort" << COLOR_END << std::endl;
		std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
		return 1;
	}
	std::vector<int> vec;
	std::cout << "Before:	";
	vec = createVector(argc, argv, vec);
	try
	{
		PmergeMe pmergeMe(vec);
		//std::vector<int> sortedVec = pmergeMe.sortVector(pmergeMe.getVector());
		std::cout << "After:	";
		//pmergeMe.printVector(sortedVec);
		pmergeMe.printVector();
		pmergeMe.printVecTime();
	}
	catch(const std::exception& e)
	{
//		errorHandler(e.what());
		std::cerr << RED << e.what() << COLOR_END << '\n';
	}
	return 0;
}