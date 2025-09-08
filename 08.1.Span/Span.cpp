/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:31:44 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/07 20:31:46 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _numbers()
{}

Span::Span(unsigned int N) : _N(N), _numbers()
{}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers)
{}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{}

void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= _N)
		throw std::runtime_error("Cannot add more numbers, capacity reached");
	_numbers.push_back(number);
}

void	Span::addRange(/*...*/)
{}

int		Span::shortestSpan() const
{
	validateSpan();
	std::vector<int> sortedNumbers = this->_numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (long unsigned int i = 0; i < sortedNumbers.size() - 1; ++i)
	{
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int		Span::longestSpan() const
{
	validateSpan();
	std::vector<int> sortedNumbers = this->_numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return sortedNumbers.back() - sortedNumbers.front();
}

void	Span::validateSpan() const
{
	if (this->_numbers.size() == 0)
		throw std::runtime_error("No numbers stored");
	if (this->_numbers.size() == 1)
		throw std::runtime_error("Only one number stored. Impossible to find a span");
}
