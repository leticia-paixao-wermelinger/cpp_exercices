/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:59:55 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/09/08 21:59:57 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iterator>
#include <iostream>

/*
A stack always has a deque (double-ended queue) as its underlying container.
This means that it is possible to access easily the first and last elements
of the stack using the deque's member functions. The same applies to the
iterator of the deque.
*/

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack &other) : std::stack<T>(other) {};
		MutantStack &operator=(MutantStack const &rhs)
		{
			std::stack<T>::operator=(rhs);
			return *this;
		}
		~MutantStack() {};

		// acessando o iterator de dentro do container deque que está dentro da stack. Agr, para chamar ele, basta digitar "iterator" e pronto.
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(); // Primeiro inserido = fundo da pilha
		iterator end(); // último inserido = topo da pilha
};

#include "MutantStack.tpp"