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

Fixed::Fixed(int const raw)
{
	(void)raw;
	std::cout << "Int constructor called" << std::endl;
	std::cout << "Falta fazer a conversão" << std::endl;
}

Fixed::Fixed(float const raw)
{
	(void)raw;
	std::cout << "Float constructor called" << std::endl;
	std::cout << "Falta fazer a conversão" << std::endl;
}

Fixed::Fixed(Fixed const & src)// : _rawBits( src.getRawBits() )
{
	std::cout << "Copy constructor called" << std::endl;
//	this->_rawBits = src.getRawBits();
	*this = src;
}

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

int	Fixed::toInt(void) const
{
	std::cout << "toInt member function called" << std::endl;
	std::cout << "Falta fazer a conversão" << std::endl;
	return 0;
}

float	Fixed::toFloat(void) const
{
	std::cout << "toFloat member function called" << std::endl;
	std::cout << "Falta fazer a conversão" << std::endl;
	return 0.0f;
}

std::ostream& operator<<( std::ostream& out, Fixed const value )
{
	out << value.toFloat();
	return out;
}