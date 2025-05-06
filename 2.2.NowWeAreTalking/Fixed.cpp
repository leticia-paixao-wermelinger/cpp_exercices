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
	setRawBits(raw * (_smallFractionalBitsShift));
}

Fixed::Fixed(float const raw)
{
	setRawBits(static_cast<int>(roundf(raw * (_floatFractionalBitsShift))));
}

Fixed::Fixed(double const raw)
{
	setRawBits(roundf(raw * (_doubleFractionalBitsShift)));
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

	integerValue = this->_rawBits / (_smallFractionalBitsShift);
	return integerValue;
}

float	Fixed::toFloat(void) const
{
	float	floatValue;
	floatValue = static_cast<float>(this->_rawBits) / (_floatFractionalBitsShift);
	return floatValue;
}

double	Fixed::toDouble(void) const
{
	double	doubleValue;
	doubleValue = static_cast<double>(this->_rawBits) / (_doubleFractionalBitsShift);
	return doubleValue;
}

bool	Fixed::operator>( Fixed const & rhs) const // operator >
{
	if (this->toDouble() > rhs.toDouble())
		return true;
	else
		return false;
}

bool	Fixed::operator<( Fixed const & rhs) const // operator <
{
	if (this->toDouble() < rhs.toDouble())
		return true;
	else
		return false;
}

bool	Fixed::operator>=( Fixed const & rhs) const // operator >=
{
	if (this->toDouble() >= rhs.toDouble())
		return true;
	else
		return false;
}

bool	Fixed::operator<=( Fixed const & rhs) const // operator <=
{
	if (this->toDouble() <= rhs.toDouble())
		return true;
	else
		return false;
}

bool	Fixed::operator==( Fixed const & rhs) const // operator ==
{
	if (this->toDouble() == rhs.toDouble())
		return true;
	else
		return false;
}

bool	Fixed::operator!=( Fixed const & rhs) const // operator !=
{
	if (this->toDouble() != rhs.toDouble())
		return true;
	else
		return false;
}

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

std::ostream& operator<<( std::ostream& out, Fixed const & value )
{
	out << value.toFloat();
	return out;
}