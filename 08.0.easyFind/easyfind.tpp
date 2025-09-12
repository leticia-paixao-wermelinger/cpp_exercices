/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:33:01 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/06 19:33:03 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define COLOR_END "\033[0m"

template <typename T>
void printContainer(const T &container);

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return it;
}

template <typename T>
void testEasyFind(T &container, int value)
{
	std::cout << "Searching for: " << value << " in ";
	printContainer(container);
	std::cout << std::endl;
	try {
		typename T::iterator it = easyfind(container, value);
		std::cout << GREEN << "Found: " << *it << COLOR_END << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << RED << "ERROR: " << e.what() << COLOR_END << std::endl;
	}
}

template <typename T>
void printContainer(const T &container)
{
	typename T::const_iterator it = container.begin();
	std::cout << "[ ";
	while (it != container.end())
	{
		std::cout << *it;
		++it;
		if (it != container.end())
			std::cout << ", ";
	}
	std::cout << " ]";
}