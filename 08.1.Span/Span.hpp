/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:31:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/07 20:31:37 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;
		Span();
		void	validateSpan() const;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		void	addNumber(int number); // in case of error, throw an exception
		int		shortestSpan() const; // in case of error, throw an exception
		int		longestSpan() const; // in case of error, throw an exception
		void	printNumbers() const;
		void	printNumbersSize() const;
		template <typename T_Iterator>
		void	addRange(T_Iterator begin, T_Iterator end) // adds multiple numbers in a single call
		{
			//std::cout << "end == " << *(end - 1) << std::endl;
			//std::cout << "begin == " << *begin << std::endl;
			//std::cout << "Range size: " << *(end - 1) - *begin << std::endl;
			//std::cout << "Current size: " << this->_numbers.size() << " / " << this->_N << std::endl;
			if (std::distance(begin, end) > static_cast<int>(_N - this->_numbers.size()))
				throw std::runtime_error("Range too large to fit in the Span capacity");
			for (T_Iterator it = begin; it != end; it++)
			{
				_numbers.push_back(*it);
			}
		}
};