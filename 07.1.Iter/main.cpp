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
#include "iter.hpp"

int	main( void )
{
	std::cout << "Testing with char array:" << std::endl;
	std::string str[] = {"Hello", "World", "from", "iter"};
	iter(str, 4, printItem);

	std::cout << "\nTesting with int array:" << std::endl;
	int numbers[] = {1, 2, 3, 4, 5};
	iter(numbers, 5, printItem);

	std::cout << "\nTesting with a simple string:" << std::endl;
	std::string simpleString = "Hello, World!";
	iter(simpleString.data(), simpleString.size(), printItem);

	/*
	Awesome wow;
	std::cout << "\nTesting with class:" << std::endl;
	iter(&wow, 1, printItem);
	*/
	return 0;
}