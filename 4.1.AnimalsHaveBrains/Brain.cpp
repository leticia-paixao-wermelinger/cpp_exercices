/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:30:20 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/20 17:30:21 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = src._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &	Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; ++i)
			this->_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return *this;
}