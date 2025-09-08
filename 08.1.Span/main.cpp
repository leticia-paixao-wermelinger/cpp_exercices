/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:32:48 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/06 19:32:50 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

/*
// test code with addRange()
int main()
{}
*/


// test adding more than the N capacity
int main()
{
	Span sp = Span(5);
	try {
		for (int i = 0; i < 7; ++i)
		{
			std::cout << "Adding number: " << i * 10 << std::endl;
			sp.addNumber(i * 10);
		}
	} catch (const std::runtime_error &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	return 0;
}

/*
// test code with more than 10000 numbers
int main()
{
	Span sp = Span(20000);
	for (int i = 0; i < 10000; ++i)
		sp.addNumber(i * 5); // Adding multiples of 5

	try {
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Should be 5
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Should be 49995
	} catch (const std::runtime_error &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	return 0;
}
*/
/*
// test code with at least 10000 numbers (preferably more)
int main()
{
	Span sp = Span(10000);
	for (int i = 0; i < 10000; ++i)
		sp.addNumber(i * 2); // Adding even numbers

	try {
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Should be 2
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;   // Should be 19998
	} catch (const std::runtime_error &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	return 0;
}*/

/*
// subject main
int	main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}*/