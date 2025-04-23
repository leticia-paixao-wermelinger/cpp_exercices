/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:28 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/04/23 16:13:29 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : _rawBits( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)// : _rawBits( src.getRawBits() )
{
	std::cout << "Copy constructor called" << std::endl;
//	this->_rawBits = src.getRawBits();
	*this = src;
}

/*
The copy assignment operator is used to copy the value of one object to another.
rhs = right-hand side
          Meaning:
Fixed a;
Fixed b;
b = a;
a is argument to operator= and b is the object that will be assigned the value of a.
*/
Fixed & Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}
