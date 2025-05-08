/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedRelationalOps.cpp                             :+:      :+:    :+:   */
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
