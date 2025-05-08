/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:59:42 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/07 13:59:44 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>

class Point
{
private:
	std::string	_name;
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(Fixed const x, Fixed const y);
	Point(std::string name, Fixed const x, Fixed const y);
	~Point();
	Point(Point const & src);
	Point & operator=(Point const & rhs);

	std::string	getName() const;
	Fixed const	getx() const;
	Fixed const	gety() const;
};
