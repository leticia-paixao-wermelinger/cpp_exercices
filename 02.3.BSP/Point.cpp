/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:59:25 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/07 13:59:27 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <string>

Point::Point( void ) : _x(Fixed()), _y(Fixed())
{
	this->_name = "unamed";
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
	this->_name = "unamed";
}

Point::Point(std::string name, Fixed const x, Fixed const y) : _x(x), _y(y)
{
	this->_name = name;
}

Point::~Point()
{}

Point::Point(Point const & src)
{
	*this = src;
}

Point & Point::operator=(Point const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		// _x and _y are const, so they cannot be reassigned here
	}
	return *this;
}

std::string	Point::getName() const
{
	return (this->_name);
}

Fixed const	Point::getx() const
{
	return this->_x;
}

Fixed const	Point::gety() const
{
	return this->_y;
}