/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:48:08 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/14 20:48:09 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
		Fixed();
		Fixed( Fixed const & src );
		~Fixed();
		Fixed &	operator=( Fixed const & rhs );
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};
#endif
