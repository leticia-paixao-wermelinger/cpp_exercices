/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:30:18 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/06 10:30:24 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Copy assignment operator
template <typename T>
Array<T> & Array<T>::operator=(const Array & other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other.size();
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

// Access operator
template <typename T>
T & Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}