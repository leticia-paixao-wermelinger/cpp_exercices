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
