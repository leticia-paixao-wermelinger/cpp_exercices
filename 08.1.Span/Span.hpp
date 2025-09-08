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
		void	addRange(/*...*/); // adds multiple numbers in a single call
		int		shortestSpan() const; // in case of error, throw an exception
		int		longestSpan() const; // in case of error, throw an exception
};