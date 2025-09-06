/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:23:59 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/04 23:24:01 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T>
void	iter(T *address, std::size_t length, void (*f)(T &item))
{
	while (length--)
		f(*address++);
}

template <typename T>
void	printItem(T &item)
{
	std::cout << item << std::endl;
}
/*
class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};*/