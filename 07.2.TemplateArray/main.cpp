/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:23:40 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/04 23:23:43 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	//std::cout << "Creating an Array of integers:" << std::endl;
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i * 10;

	std::cout << "Integer Array:" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";

	std::cout << "String Array:" << std::endl;
	for (unsigned int i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << " ";
	std::cout << std::endl;

	// Testing out of bounds access
	try
	{
		std::cout << intArray[10] << std::endl; // This should throw an exception
	}
	catch (const Array<int>::OutOfBoundsException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

/*
// subject main
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}*/