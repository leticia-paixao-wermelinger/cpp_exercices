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

RPN::RPN()
{}

RPN::RPN(std::string expression)
{}

RPN::RPN(RPN & const src)
{}

RPN &RPN::operator=(RPN & const src)
{}

RPN::~RPN()
{
	this->numbers.clear();
	this->operators.clear();
}

void	RPN::printExpression()
{
	
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

std::ostream &operator<<(std::ostream& os, const RPN& obj)
{}