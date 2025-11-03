/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:20:03 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/10/28 21:20:04 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <stdexcept>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		long double _sortVectime;
		long double _sortDeqtime;
		void	startVector(std::vector<int> vec);
		void	startDeque(std::deque<int> deq);
		long int setTime() const;
		std::vector<int> mergeVector(std::vector<int> leftVec, std::vector<int> rightVec);
		std::deque<int>	 mergeDeque(std::deque<int> leftDeq, std::deque<int> rightDeq);
		class noDuplicatesAlllowedException : public std::exception
		{
			public:
			const char* what() const throw();
		};
	public:
		PmergeMe();
		PmergeMe(std::vector<int> vec);
		PmergeMe(std::deque<int> deq);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		std::vector<int> getVector() const;
		std::deque<int> getDeque() const;
		void	printVector() const;
		std::vector<int>	sortVector(std::vector<int> vec);
		std::deque<int>		sortDeque(std::deque<int> deq);
		void	printVector(std::vector<int> vec) const;
		void	printVecTime() const;
		void	printDeqTime() const;
		long double	getVecTime() const;
		long double	getDeqTime() const;
};