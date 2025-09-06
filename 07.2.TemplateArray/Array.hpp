/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:23:59 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/04 23:24:01 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
	private:
		T	*_array;
		size_t _size;
	public:
		// Contructor with no parameter
		Array() : _array(new T[0]), _size(0) {};

		// Constructor with size parameter
		Array(unsigned int size) : _array(new T[size]), _size(size) {};

		// Constructor by copy
		Array(const Array & other) : _array(new T[other.size()]), _size(other.size()) {};

		// Copy assignment operator
		Array & operator=(const Array & other);

		// Destructor
		~Array() { delete[] _array; };

		// Getter
		unsigned int	size() const { return this->_size; };

		// Access operator
		T & operator[](unsigned int index);

		// Exception class for out of bounds access
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index out of bounds";
				}
		};
};

#include "Array.tpp"