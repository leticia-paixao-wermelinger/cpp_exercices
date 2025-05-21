/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:10:48 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:10:49 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : AAnimal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat (const Cat & src) : AAnimal(src)
{
	setType(src.getType());
	this->_brain = new Brain(*src._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat & Cat::operator=( const Cat & src )
{
	if (this != &src)
	{
		setType(src.getType());
		this->_brain = new Brain(*src._brain);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void	Cat::cpyIdeas( const Cat & src )
{
	int	total = src.getnIdeas();
	for (int i = 0; i < total; i++)
	{
		this->_brain->newIdea(src.getIdea(i));
	}
}

Cat::~Cat( void )
{
	if (this->_brain)
		delete (this->_brain);
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat meows" << std::endl;
}

void	Cat::setIdea(std::string idea)
{
	std::cout << "Em setIdea: " << std::endl;
	this->_brain->newIdea(idea);
}

int	Cat::getnIdeas() const
{
	return this->_brain->getnIdeas();
}

std::string	Cat::getIdea(int i) const
{
	return this->_brain->getIdea(i);
}

void	Cat::printIdea(int i)
{
	std::cout << "Idea " << i << ": " << this->_brain->getIdea(i) << std::endl;
}

void	Cat::printAllIdeas()
{
	for (int i = 0; i < this->_brain->getnIdeas(); i++)
		printIdea(i);
}

Brain *	Cat::getBrain() const
{
	return this->_brain;
}

void	Cat::changeIdea(int i, std::string modifiedIdea)
{
	this->_brain->changeIdea(i, modifiedIdea);
}