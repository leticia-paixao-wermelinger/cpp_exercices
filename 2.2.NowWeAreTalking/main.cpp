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


int main( void ) { // subject main
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
}

/*
int main( void ) { // Subject main debug
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "Fixed::max( a, b ): " << Fixed::max( a, b ) << std::endl;
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

/*
int	main(void) // main operator!=
{
	Fixed a;
	Fixed b(5.05f);
	Fixed c(2);
	Fixed d(2);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	if (b != c)
		std::cout << "b != c" << std::endl;
	else
		std::cout << "b == c" << std::endl;
	if (c != d)
		std::cout << "c != d" << std::endl;
	else
		std::cout << "c == d" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	else
		std::cout << "a == b" << std::endl;
	return 0;
}*/

/*
int	main(void) // main operator+
{
	Fixed a;
	Fixed b(5.0564);
	Fixed c(2);
	Fixed d(2);
	Fixed e(3.5693);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "b + c = " << b + c <<  std::endl;
	std::cout << "c + d = " << c + d <<  std::endl;
	std::cout << "b + e = " << b + e <<  std::endl;
	return 0;
}*/

/*
int	main(void) // main operator-
{
	Fixed a;
	Fixed b(5.0564);
	Fixed c(2);
	Fixed d(2);
	Fixed e(3.5693);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "a - b = " << a - b << " ==> Resultado = -5.0564" << std::endl;
	std::cout << "b - a = " << b - a << " ==> Resultado = 5.0564" <<  std::endl;
	std::cout << "b - c = " << b - c << " ==> Resultado = 3.0564" <<  std::endl;
	std::cout << "c - d = " << c - d << " ==> Resultado = 0" <<  std::endl;
	std::cout << "b - e = " << b - e << " ==> Resultado = 1.4871" <<  std::endl;
	return 0;
}*/

/*
int	main(void) // main operator*
{
	Fixed a;
	Fixed b(5.0564);
	Fixed c(2);
	Fixed d(2);
	Fixed e(3.5693);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "a * b = " << a * b << " ==> Resultado = 0" << std::endl;
	std::cout << "b * c = " << b * c << " ==> Resultado = 10.1128" <<  std::endl;
	std::cout << "c * d = " << c * d << " ==> Resultado = 4" <<  std::endl;
	std::cout << "b * e = " << b * e << " ==> Resultado = 18.04780852" <<  std::endl;
	return 0;
}*/

/*
int	main(void) // main operator/
{
	Fixed a;
	Fixed b(5.0564);
	Fixed c(2);
	Fixed d(2);
	Fixed e(3.5693);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "a / b = " << a / b << " ==> Resultado = 0" << std::endl;
	std::cout << "b / a = " << b / a << " ==> Resultado = 0" << std::endl;
	std::cout << "b / c = " << b / c << " ==> Resultado = 2.5282" <<  std::endl;
	std::cout << "c / d = " << c / d << " ==> Resultado = 1" <<  std::endl;
	std::cout << "b / e = " << b / e << " ==> Resultado = 1.41663631524" <<  std::endl;
	return 0;
}*/

/*
int	main(void) // main operators ++ and --
{
	Fixed a;
	Fixed b(5.0564);
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "Int a:  = " << a.toInt() << std::endl;
	std::cout << "Float a:  = " << a.toFloat() << std::endl;
	std::cout << "Double a:  = " << a.toDouble() << std::endl;
	std::cout << std::endl;
	std::cout << " --------------------- " << std::endl;
	std::cout << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "Int b: " << b.toInt() << std::endl;
	std::cout << "Float b: " << b.toFloat() << std::endl;
	std::cout << "Double b: " << b.toDouble() << std::endl;
	std::cout << std::endl;
	std::cout << "b++ = " << b++ << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "Int b: " << b.toInt() << std::endl;
	std::cout << "Float b: " << b.toFloat() << std::endl;
	std::cout << "Double b: " << b.toDouble() << std::endl;
	std::cout << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "Int b: " << b.toInt() << std::endl;
	std::cout << "Float b: " << b.toFloat() << std::endl;
	std::cout << "Double b: " << b.toDouble() << std::endl;
	std::cout << std::endl;
	std::cout << "b-- = " << b-- << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "Int b: " << b.toInt() << std::endl;
	std::cout << "Float b: " << b.toFloat() << std::endl;
	std::cout << "Double b: " << b.toDouble() << std::endl;
	std::cout << std::endl;
	std::cout << "--b = " << --b << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "Int b: " << b.toInt() << std::endl;
	std::cout << "Float b: " << b.toFloat() << std::endl;
	std::cout << "Double b: " << b.toDouble() << std::endl;
	return 0;
}*/