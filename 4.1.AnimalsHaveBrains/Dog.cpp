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

Dog::Dog( const Dog & src ) : Animal(src)
{
//	*this = src; // shadow copy
	this->_brain = new Brain();
	this->_brain = src._brain;
	setType(src.getType());
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog( void )
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::Dog::operator=( const Dog & src )
{
	if (&src != this)
	{
		setType(src.getType());
		this->_brain = new Brain();
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog barks" << std::endl;
}