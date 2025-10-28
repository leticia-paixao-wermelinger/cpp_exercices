/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:44:24 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/10/25 10:44:25 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <iostream>
#include <ostream>
#include <exception>

class RPN
{
	private:
		std::list<int>	numbers;
		std::list<char>	operators;
		int	makeOperation(int n1, int n2, char opr);
		int	operateSum(int n1, int n2);
		int	operateSubtraction(int n1, int n2);
		int	operateDivision(int n1, int n2);
		int	operateMultiplication(int n1, int n2);
		bool	isOperator(std::string opr);
		class invalidExpression : public std::exception
		{
			public:
				const char* what() const throw();
		};
	public:
		RPN();
		RPN(std::string expression);
		RPN(RPN const & src);
		RPN &operator=(RPN const &src);
		~RPN();
		std::list<int>	getNbrsList() const;
		std::list<char>	getOpsList() const;
		void	printExpression();
		void	addOperation(char newOperator, int newNumber);
		int	calculate();
};

std::ostream &operator<<(std::ostream& os, const RPN& obj);