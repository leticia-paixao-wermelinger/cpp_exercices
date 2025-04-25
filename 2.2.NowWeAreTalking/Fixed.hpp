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
		bool	operator>( Fixed const & rhs) const; // operator >
		bool	operator<( Fixed const & rhs) const; // operator <
		bool	operator>=( Fixed const & rhs) const; // operator >=
		bool	operator<=( Fixed const & rhs) const; // operator <=
		bool	operator==( Fixed const & rhs) const; // operator ==
		bool	operator!=( Fixed const & rhs) const; // operator !=
		Fixed	operator+( Fixed const & rhs) const; // operator +
		// operator -
		// operator *
		// operator /
		// operator ++
		// operator --
		// operator ++(int)
		// operator --(int)
		// (Falta algo de incremento? São 4 mesmo mas é preciso confirmar se são assim realmente. Jogar o texto disso do pdf no gpt)
		// static Fixed & min( Fixed & a, Fixed & b ); // static min
		// static Fixed const & min( Fixed const & a, Fixed const & b ); // static min
		// static Fixed & max( Fixed & a, Fixed & b ); // static max
		// static Fixed const & max( Fixed const & a, Fixed const & b ); // static max
		friend std::ostream& operator<<( std::ostream& out, Fixed const & value ); // operator<< overload
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
		int		toInt( void ) const;
		float	toFloat( void ) const;
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};
