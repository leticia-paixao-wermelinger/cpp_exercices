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

Cat::Cat( void ) : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat (const Cat & src) : Animal(src)
{
//	*this = src; // shadow copy
	this->_brain = new Brain();
	this->_brain = src._brain;
	setType(src.getType());
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat( void )
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=( const Cat &  src)
{
	if (this != &src)
	{
		setType(src.getType());
		this->_brain = new Brain();
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat meows" << std::endl;
}