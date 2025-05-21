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
	this->_nIdeas = 0;
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	int	totalIdeas = src.getnIdeas();
	for (int i = 0; i < totalIdeas; ++i)
		this->_ideas[i] = src._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &	Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; ++i)
			this->_ideas[i] = src._ideas[i];
		this->_nIdeas = src.getnIdeas();
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return *this;
}

void	Brain::newIdea(std::string idea)
{
	std::cout << "Índice da ideia: " << this->_nIdeas << std::endl;
	this->_ideas[this->_nIdeas] = idea;
	this->_nIdeas++;
}

int	Brain::getnIdeas() const
{
	return this->_nIdeas;
}

std::string	Brain::getIdea(int i)
{
	return this->_ideas[i];
}

void	Brain::changeIdea(int i, std::string modifiedIdea)
{
	this->_ideas[i] = modifiedIdea;
}