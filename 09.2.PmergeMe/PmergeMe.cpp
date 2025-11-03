/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:19:58 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/10/28 21:19:59 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <iomanip>

PmergeMe::PmergeMe()
{
	long double	timeStart = this->setTime();
	this->_vector = std::vector<int>();
	this->_vector = this->sortVector(this->_vector);
	long double	timeEnd = this->setTime();
	this->_sortVectime = timeEnd - timeStart;
}

PmergeMe::PmergeMe(std::vector<int> vec)
{
	long double	timeStart = this->setTime();
	//std::cout << "timeStart = " << timeStart << std::endl;
	this->_vector = vec;
	//std::cout << "New object created, with vector: ";
	//this->printVector();
	long double	timeEnd = this->setTime();
	//std::cout << "timeEnd = " << timeEnd << std::endl;
	this->_sortVectime = timeEnd - timeStart;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_vector = other.getVector();
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vector = other.getVector();
		this->_sortVectime = other._sortVectime;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

std::vector<int> PmergeMe::getVector() const
{
	return this->_vector;
}

long int PmergeMe::setTime() const
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

std::vector<int>	PmergeMe::sortVector(std::vector<int> vec)
{
	std::vector<int> subVec1;
	std::vector<int> subVec2;

	if (vec.size() <= 1)
		return vec;
	size_t	mid = vec.size() / 2;

	subVec1.insert(subVec1.end(), vec.begin(), vec.begin() + mid);
	subVec2.insert(subVec2.end(), vec.begin() + mid, vec.end());
	subVec1 = this->sortVector(subVec1);
	subVec2 = this->sortVector(subVec2);
	return mergeVector(subVec1, subVec2);
}

std::vector<int> PmergeMe::mergeVector(std::vector<int> leftVec, std::vector<int> rightVec)
{
	//std::cout << "In mergeVector with leftVec: ";
	//printVector(leftVec);
	//std::cout << " and rightVec: ";
	//printVector(rightVec);
	std::vector<int>	sortedVec;
	size_t	i = 0, j = 0;
	while (i < leftVec.size() && j < rightVec.size())
	{
		if (leftVec[i] == rightVec[j])
			throw noDuplicatesAlllowedException();
		else if (leftVec[i] < rightVec[j])
		{
			sortedVec.push_back(leftVec[i]);
			i++;
		}
		else
		{
			sortedVec.push_back(rightVec[j]);
			j++;
		}
	}
	sortedVec.insert(sortedVec.end(), leftVec.begin() + i, leftVec.end());
	sortedVec.insert(sortedVec.end(), rightVec.begin() + j, rightVec.end());
	//std::cout << "Merged vector: ";
	//printVector(sortedVec);
	return sortedVec;
}

void	PmergeMe::printVector() const
{
	for (size_t i = 0; i < this->_vector.size(); i++)
	{
		std::cout << this->_vector[i];
		if (i < this->_vector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printVector(std::vector<int> vec) const
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printVecTime() const
{
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " << this->_sortVectime << " us" << std::endl;
	//std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(10) << this->_sortVectime << " us" << std::endl;
}

const char* PmergeMe::noDuplicatesAlllowedException::what() const throw()
{
    return "Error: duplicate numbers are not allowed";
}