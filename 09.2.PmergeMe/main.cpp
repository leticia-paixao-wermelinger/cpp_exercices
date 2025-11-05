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

enum e_validSortedContent
{
	SORTED,
	UNSORTED,
	MISMATCH
};

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
		//std::cout << num << " ";
	}
	//std::cout << std::endl;
	return vec;
}

std::deque<int> createDeque(int argc, char *str[], std::deque<int> &deq)
{
	for (int i = 1; i < argc; i++)
	{
		char *token = str[i];
		int num = atoi(token);
		if (num > 0)
			deq.push_back(num);
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return deq;
}

e_validSortedContent checkSortedContents(std::vector<int> vec, std::deque<int> deq)
{
	if (vec.size() != deq.size())
		return MISMATCH;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] != deq[i])
			return MISMATCH;
		if (i > 0 && vec[i] < vec[i - 1])
			return UNSORTED;
	}
	return SORTED;
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
	vec = createVector(argc, argv, vec);
	std::deque<int> deq;
	std::cout << "Before:	";
	deq = createDeque(argc, argv, deq);
	try
	{
		PmergeMe pmergeVec(vec);
		PmergeMe pmergeDeq(deq);
		// Check if vector and deque are sorted correctly and have the same content
		// std::cout << "Vector:	";
		// pmergeVec.printVector();
		// std::cout << "Deque:	";
		// pmergeDeq.printDeque();
		int	validSortedContent = checkSortedContents(pmergeVec.getVector(), pmergeDeq.getDeque());
		if (validSortedContent == UNSORTED)
			errorHandler("Error: sorting failed");
		else if (validSortedContent == MISMATCH)
			errorHandler("Error: sorting mismatch between vector and deque");
		std::cout << "After:	";
		pmergeVec.printVector();
		pmergeVec.printVecTime();
		pmergeDeq.printDeqTime();
	}
	catch(const std::exception& e)
	{
//		errorHandler(e.what());
		std::cerr << RED << e.what() << COLOR_END << '\n';
	}
	return 0;
}