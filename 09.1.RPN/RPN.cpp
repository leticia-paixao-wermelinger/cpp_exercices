/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:44:19 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/10/25 10:44:21 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <sstream>

RPN::RPN()
{
	std::list<int> nbr;
	this->numbers = nbr;
	std::list<char> ops;
	this->operators = ops;
}

RPN::RPN(std::string expression)
{
	std::stringstream	ss(expression);
	
}

RPN::RPN(RPN & const src)
{
	this->numbers = src.getNbrsList();
	this->operators = src.getOpsList();
}

RPN &RPN::operator=(RPN & const src)
{
	if (&src != this)
	{
		this->numbers = src.getNbrsList();
		this->operators = src.getOpsList();
	}
	return *this;
}

RPN::~RPN()
{
	this->numbers.clear();
	this->operators.clear();
}

std::list<int>	RPN::getNbrsList() const
{
	return this->numbers;
}

std::list<char>	RPN::getOpsList() const
{
	return this->operators;
}

void	RPN::printExpression()
{
	std::list<char>::iterator itOps = operators.begin();
	for (std::list<int>::iterator itNumb = numbers.begin(); itNumb != numbers.end(); itNumb++)
	{
		std::cout << *itNumb << " ";
		if (itNumb != numbers.begin())
		{
			std::cout << *itOps << " ";
			itOps++;
		}
	}
	std::cout << std::endl;
}

int	RPN::makeOperation(int n1, int n2, char opr)
{
	switch (opr)
	{
		case '+':
			return operateSum(n1, n2);
		case '-':
			return operateSubtraction(n1, n2);
		case '/':
			return operateDivision(n1, n2);
		case '*':
			return operateMultiplication(n1, n2);
		default:
			return 0;
	}
}

int	RPN::operateSum(int n1, int n2)
{
	return n1 + n2;
}

int	RPN::operateSubtraction(int n1, int n2)
{
	return n1 - n2;
}

int	RPN::operateDivision(int n1, int n2)
{
	return n1 / n2;
}

int	RPN::operateMultiplication(int n1, int n2)
{
	return n1 * n2;
}

void	RPN::addOperation(char newOperator, int newNumber)
{
	this->numbers.push_back(newNumber);
	this->operators.push_back(newOperator);
}

int	RPN::calculate()
{
	int	n1;
	std::list<char>::iterator itOps = operators.begin();
	std::list<int>::iterator itNumb = numbers.begin();
	n1 = *itNumb;
	for (itNumb; itNumb != numbers.end(); itNumb++)
	{
		if (itNumb == numbers.begin())
			break;
		n1 = makeOperation(n1, *itNumb, *itOps);
		itOps++;
	}
}

std::ostream &operator<<(std::ostream& os, const RPN& obj)
{
	//int	ret = const_cast<int*>(&(obj.calculate()));
	int ret = const_cast<RPN&>(obj).calculate();
	return os << ret;
}