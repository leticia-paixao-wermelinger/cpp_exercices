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
{}

Fixed::Fixed(int const raw)
{
	setRawBits(raw * (1 << _fractionalBits));
}

Fixed::Fixed(float const raw)
{
	float scaled = raw * (1 << _fractionalBits);
	
	if (raw >= 0)
	scaled += 0.5f;
	else
	scaled -= 0.5f;
	setRawBits(static_cast<int>(scaled));
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

	integerValue = this->_rawBits / (1 << _fractionalBits);
	return integerValue;
}

float	Fixed::toFloat(void) const
{
	float	floatValue;
	floatValue = static_cast<float>(this->_rawBits) / (1 << _fractionalBits);
	return floatValue;
}

std::ostream& operator<<( std::ostream& out, Fixed const & value )
{
	out << value.toFloat();
	return out;
}