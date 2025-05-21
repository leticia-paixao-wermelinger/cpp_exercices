/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:10:31 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:10:32 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog (const Dog & src) : Animal(src)
{
	setType(src.getType());
	this->_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog & Dog::operator=( const Dog & src )
{
	if (this != &src)
	{
		setType(src.getType());
		this->_brain = new Brain(*src._brain);
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void	Dog::cpyIdeas( const Dog & src )
{
	int	total = src.getnIdeas();
	for (int i = 0; i < total; i++)
	{
		this->_brain->newIdea(src.getIdea(i));
	}
}

Dog::~Dog( void )
{
	if (this->_brain)
		delete (this->_brain);
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog meows" << std::endl;
}

void	Dog::setIdea(std::string idea)
{
	std::cout << "Em setIdea: " << std::endl;
	this->_brain->newIdea(idea);
}

int	Dog::getnIdeas() const
{
	return this->_brain->getnIdeas();
}

std::string	Dog::getIdea(int i) const
{
	return this->_brain->getIdea(i);
}

void	Dog::printIdea(int i)
{
	std::cout << "Idea " << i << ": " << this->_brain->getIdea(i) << std::endl;
}

void	Dog::printAllIdeas()
{
	for (int i = 0; i < this->_brain->getnIdeas(); i++)
		printIdea(i);
}

Brain *	Dog::getBrain() const
{
	return this->_brain;
}

void	Dog::changeIdea(int i, std::string modifiedIdea)
{
	this->_brain->changeIdea(i, modifiedIdea);
}