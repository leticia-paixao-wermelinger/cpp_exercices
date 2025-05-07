/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedArithmeticOps.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:25:08 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/06 22:25:10 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed	Fixed::operator+( Fixed const & rhs) const // operator +
{
	Fixed result(this->toDouble() + rhs.toDouble());
	return result;
}

Fixed	Fixed::operator-( Fixed const & rhs) const // operator -
{
	Fixed result(this->toDouble() - rhs.toDouble());
	return result.toDouble();
}

Fixed	Fixed::operator*( Fixed const & rhs) const // operator *
{
	std::cout << "this->toDouble() = " << this->toDouble() << std::endl;
	std::cout << "rhs.toDouble() = " << rhs.toDouble() << std::endl;
	std::cout << "this->toDouble() * rhs.toDouble() = " << this->toDouble() * rhs.toDouble() << std::endl;
	double result(this->toDouble() * rhs.toDouble());
	std::cout << "result = " << result << std::endl;
	return result;
}

Fixed	Fixed::operator/( Fixed const & rhs) const // operator /
{
	Fixed result(this->toDouble() / rhs.toDouble());
	return result;
}

/*
The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1:
*/

Fixed	Fixed::operator++( void ) // operator ++
{
	std::cout << "operator++" << std::endl;
	this->_rawBits += 1;
	return *this;
}

Fixed	Fixed::operator--( void ) // operator --
{
	std::cout << "operator--" << std::endl;
	this->_rawBits -= 1;
	return *this;
}

		// operator ++(int)
		// operator --(int)

Fixed	Fixed::operator++( int ) // operator ++
{
	std::cout << "operator++(int)" << std::endl;
	this->_rawBits += 1;
	return *this;
}
		
Fixed	Fixed::operator--( int ) // operator --
{
	std::cout << "operator--(int)" << std::endl;
	this->_rawBits -= 1;
	return *this;
}