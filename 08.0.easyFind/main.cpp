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

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int	main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + 5);

	std::cout << "----- Test with std::vector -----" << std::endl;
	testEasyFind(vec, 3);

	std::cout << std::endl << "----- Test with std::vector (not found) -----" << std::endl;
	testEasyFind(vec, 9);

	std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

	std::cout << std::endl << "----- Test with std::list -----" << std::endl;
	testEasyFind(l, 10);

	std::cout << std::endl << "----- Test with std::list (not found) -----" << std::endl;
	testEasyFind(l, -42);

	std::deque<int> d;
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);

    std::cout << std::endl << "----- Test with std::deque -----" << std::endl;
    testEasyFind(d, 300);

    std::cout << std::endl << "----- Test with std::deque (not found) -----" << std::endl;
    testEasyFind(d, 0);
	return 0;
}