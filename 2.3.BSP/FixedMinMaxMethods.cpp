/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedMinMaxMethods.cpp                             :+:      :+:    :+:   */
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

Fixed & Fixed::min( Fixed & a, Fixed & b ) // static min
{
	if (a.toDouble() < b.toDouble())
		return a;
	else
		return b;
}

Fixed const & Fixed::min( Fixed const & a, Fixed const & b ) // static min
{
	if (a.toDouble() < b.toDouble())
		return a;
	else
		return b;
}

Fixed & Fixed::max( Fixed & a, Fixed & b ) // static max
{
	if (a.toDouble() < b.toDouble())
		return b;
	else
		return a;
}

Fixed const & Fixed::max( Fixed const & a, Fixed const & b ) // static max
{
	if (a.toDouble() < b.toDouble())
		return b;
	else
		return a;
}