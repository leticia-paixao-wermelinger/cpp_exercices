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
	//std::cout << "Current size: " << this->_numbers.size() + 1 << " / " << this->_N << std::endl;
	if (this->_numbers.size() >= _N - 1)
		throw std::runtime_error("Cannot add more numbers, capacity reached");
	_numbers.push_back(number);
}

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

void	Span::printNumbers() const
{
	if (this->_numbers.size() == 0)
	{
		std::cout << "No numbers stored." << std::endl;
		return ;
	}
	std::cout << "Stored numbers: [";
	for (size_t i = 0; i < _numbers.size(); ++i)
	{
		std::cout << _numbers[i];
		if (i != _numbers.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void	Span::printNumbersSize() const
{
	std::cout << "Current size: " << this->_numbers.size() << " / " << this->_N << std::endl;
}