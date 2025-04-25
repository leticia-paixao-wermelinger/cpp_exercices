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
/*
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}*/

/*
int	main(void) // main operator>
{
	Fixed a;
	Fixed b(5.05f);
	Fixed c(2);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	if (b > c)
		std::cout << "b > c" << std::endl;
	else
		std::cout << "b <= c" << std::endl;
	std::cout << "";
	return 0;
}*/

/*
int	main(void) // main operator<
{
	Fixed a;
	Fixed b(5.05f);
	Fixed c(2);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	if (b < c)
		std::cout << "b < c" << std::endl;
	else
		std::cout << "b >= c" << std::endl;
	std::cout << "";
	return 0;
}*/

/*
int	main(void) // main operator>=
{
	Fixed a;
	Fixed b(5.05f);
	Fixed c(2);
	Fixed d(2);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	if (b >= c)
		std::cout << "b >= c" << std::endl;
	else
		std::cout << "b < c" << std::endl;
	if (c >= d)
		std::cout << "c >= d" << std::endl;
	else
		std::cout << "c < d" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	else
		std::cout << "a < b" << std::endl;
	return 0;
}*/

/*
int	main(void) // main operator<=
{
	Fixed a;
	Fixed b(5.05f);
	Fixed c(2);
	Fixed d(2);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	if (b <= c)
		std::cout << "b <= c" << std::endl;
	else
		std::cout << "b > c" << std::endl;
	if (c <= d)
		std::cout << "c <= d" << std::endl;
	else
		std::cout << "c > d" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	else
		std::cout << "a > b" << std::endl;
	return 0;
}*/

/*
int	main(void) // main operator==
{
	Fixed a;
	Fixed b(5.05f);
	Fixed c(2);
	Fixed d(2);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	if (b == c)
		std::cout << "b == c" << std::endl;
	else
		std::cout << "b != c" << std::endl;
	if (c == d)
		std::cout << "c == d" << std::endl;
	else
		std::cout << "c != d" << std::endl;
	if (a == b)
		std::cout << "a == b" << std::endl;
	else
		std::cout << "a != b" << std::endl;
	return 0;
}*/


int	main(void) // main operator!=
{
	Fixed a;
	Fixed b(5.05f);
	Fixed c(2);
	Fixed d(2);
	Fixed e(3.569f);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "a + b = " << a + b << " ==> Resultado = 5.05078" << std::endl;
	std::cout << "b + c = " << b + c << " ==> Resultado = 7.05078" <<  std::endl;
	std::cout << "c + d = " << c + d << " ==> Resultado = 4" <<  std::endl;
	std::cout << "b + e = " << b + e << " ==> Resultado = 8.62109" <<  std::endl;
	return 0;
}