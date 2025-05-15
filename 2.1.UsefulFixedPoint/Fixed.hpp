/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:36 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/04/23 16:13:38 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class	Fixed
{
	public:
		Fixed(); // default constructor
		Fixed( int const raw ); // constructor with int
		Fixed( float const raw ); // constructor with float
		Fixed( Fixed const & src ); // copy constructor
		~Fixed(); // destructor
		Fixed &	operator=( Fixed const & rhs ); // copy assignment operator
		friend std::ostream& operator<<( std::ostream& out, Fixed const & value ); // operator<< overload
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
		int		toInt( void ) const;
		float	toFloat( void ) const;
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};
#endif