/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:46 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/04/23 16:13:47 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// subject main

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}


// my test main
/*
int main (void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	c.setRawBits( 42 );
	b.setRawBits( 24 );
	std::cout << "Initial a: " << a.getRawBits() << std::endl;
	std::cout << "Initial b: " << b.getRawBits() << std::endl;
	std::cout << "Initial c: " << c.getRawBits() << std::endl;
	a = b;
	b = c;
	c.setRawBits( 69 );
	std::cout << "Final a: " << a.getRawBits() << std::endl;
	std::cout << "Final b: " << b.getRawBits() << std::endl;
	std::cout << "Final c: " << c.getRawBits() << std::endl;
	return 0;
}
*/