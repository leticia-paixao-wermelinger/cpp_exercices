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
#include <stdlib.h>

// --------------- Orthodox canonical form ---------------

RPN::RPN()
{
	std::stack<int> nbr;
	this->numbers = nbr;
	this->result = 0;
}

RPN::RPN(std::string expression)
{
	std::stringstream	ss(expression);
	std::string token;
	int	nbr;
	int	nCount = 0;
	int n1, n2;

	this->result = 0;

	if (expression.size() < 3)
		throw(invalidExpression());
	while (ss >> token)
	{
		nbr = atoi(token.c_str());
		if (isNumber(token) == true)
		{
			nCount++;
			this->numbers.push(nbr);
		}
		else if (isOperator(token) == true)
		{
			if (nCount < 2)
				throw(invalidExpression());
			nCount = nCount - 2;
			n2 = this->numbers.top();
			this->numbers.pop();
			n1 = this->numbers.top();
			this->numbers.pop();
			nbr = this->makeOperation(n1, n2, token[0]);
			this->numbers.push(nbr);
			nCount++;
		}
	}
	if (nCount != 1)

		throw(invalidExpression());
	this->result = this->numbers.top();
}

RPN::RPN(RPN const &src)
{
	this->numbers = src.getNbrsStack();
	this->result = src.getResult();
}

RPN &RPN::operator=(RPN const &src)
{
	if (&src != this)
	{
		this->numbers = src.getNbrsStack();
		this->result = src.getResult();
	}
	return *this;
}

RPN::~RPN()
{}

// --------------- Validation ---------------

bool	RPN::isOperator(std::string opr)
{
	if (opr.length() != 1)
		return false;
	else if (opr[0] != '-' && opr[0] != '+' && opr[0] != '/' && opr[0] != '*')
		return false;
	return true;
}

bool	RPN::isNumber(std::string token)
{
	if (token[0] < '0' || token[0] > '9')
		return false;
	return true;
}

// --------------- Getters / Setters ---------------

std::stack<int>	RPN::getNbrsStack() const
{
	return this->numbers;
}

int	RPN::getResult() const
{
	return this->result;
}

// --------------- Operations ---------------

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
	if (n1 == 0)
		return 0;
	else if (n2 == 0)
		throw(invalidExpression());
	return n1 / n2;
}

int	RPN::operateMultiplication(int n1, int n2)
{
	return n1 * n2;
}

// --------------- Debug / Print ---------------

void	RPN::printStack() const
{
	std::stack<int> copy = this->numbers;
	std::cout << "Stack: ";
	while (!copy.empty())
	{
		std::cout << copy.top() << " ";
		copy.pop();
	}
	std::cout << std::endl;
}

// --------------- Exception message ---------------

const char* RPN::invalidExpression::what() const throw()
{
	return "Error";
}

// --------------- Overload operator << ---------------

std::ostream &operator<<(std::ostream& os, const RPN& obj)
{
	int ret = const_cast<RPN&>(obj).getResult();
	return os << ret;
}