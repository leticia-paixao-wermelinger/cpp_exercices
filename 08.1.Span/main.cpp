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
// test small values with addRange()
int main()
{
	try {
        Span sp(10);

        // Criando um vector com 5 números
        std::vector<int> v;
        for (int i = 1; i <= 5; ++i)
            v.push_back(i);

		sp.printNumbers();
        std::cout << "Usando addRange" << std::endl;
        sp.addRange(v.begin(), v.end());
        std::cout << "Added 5 numbers using addRange." << std::endl;
		sp.printNumbers();

        //std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        //std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		
        // Teste com array C
        int arr[] = {50, 60, 70, 80, 90};
		sp.printNumbers();
		std::cout << "Usando addRange com array C" << std::endl;
        sp.addRange(arr, arr + 5);
        std::cout << "Added 5 numbers from array." << std::endl;
		sp.printNumbers();
        //std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        //std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		
        // Aqui deve lançar exceção (já está cheio)
		std::cout << "Deve lançar excessão de falta de espaço:" << std::endl;
        sp.addNumber(999);
    }
    catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    return 0;
}
*/

// test big values with addRange()
int main()
{
    try {
        Span sp(20000);

        // Preenche com vector
        std::vector<int> v;
        for (int i = 0; i < 10000; ++i)
            v.push_back(i * 2); // pares

		sp.printNumbersSize();
        sp.addRange(v.begin(), v.end());
        std::cout << "Added 10000 numbers from vector." << std::endl;
		sp.printNumbersSize();

        // Preenche com list
        std::list<int> l;
        for (int i = 0; i < 5000; ++i)
            l.push_back(i * 3); // múltiplos de 3

		sp.printNumbersSize();
        sp.addRange(l.begin(), l.end());
        std::cout << "Added 5000 numbers from list." << std::endl;
		sp.printNumbersSize();

        // Preenche com deque
        std::deque<int> d;
        for (int i = 0; i < 5000; ++i)
            d.push_back(i * 7); // múltiplos de 7

		sp.printNumbersSize();
        sp.addRange(d.begin(), d.end());
        std::cout << "Added 5000 numbers from deque." << std::endl;
        std::cout << "Total numbers stored: 20000" << std::endl;
		sp.printNumbersSize();
		
        //std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        //std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Tentando adicionar mais números → deve lançar exceção
        std::vector<int> overflow(10, 42);
        sp.addRange(overflow.begin(), overflow.end());
    }
    catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    return 0;
}

/*
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
*/
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