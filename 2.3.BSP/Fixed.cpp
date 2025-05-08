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
#include <cmath>

Fixed::Fixed( void ) : _rawBits( 0 )
{}

Fixed::Fixed(int const raw)
{
	setRawBits(raw * _FractionalBitsShift);
}

Fixed::Fixed(float const raw)
{
	setRawBits(roundf(raw * (float)_FractionalBitsShift));
}

Fixed::Fixed(double const raw)
{
	setRawBits(roundf(raw * (double)_FractionalBitsShift));
}

Fixed::Fixed(Fixed const & src)// : _rawBits( src.getRawBits() )
{
	*this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed( void )
{}

void	Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

int	Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

int	Fixed::toInt(void) const
{
	int	integerValue;

	integerValue = this->_rawBits / _FractionalBitsShift;
	return integerValue;
}

float	Fixed::toFloat(void) const
{
	float	floatValue;
	floatValue = (float)(this->_rawBits / (float)_FractionalBitsShift);
	return floatValue;
}

double	Fixed::toDouble(void) const
{
	double	doubleValue;
	doubleValue = (double)(this->_rawBits / (double)_FractionalBitsShift);
	return doubleValue;
}

std::ostream& operator<<( std::ostream& out, Fixed const & value )
{
	out << value.toFloat();
	return out;
}
