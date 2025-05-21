/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:09:00 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:09:01 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	setType(type);
	std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::Animal(const Animal &src)
{
//	*this = src;
	this->_type = src._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
//	delete
	std::cout << "Animal destructor called" << std::endl;
}

Animal & Animal::operator=(const Animal & src)
{
	if (&src != this)
		setType(src.getType());
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}

void	Animal::setType(std::string type)
{
	this->_type = type;
}

std::string	Animal::getType() const
{
	return this->_type;
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes a sound" << std::endl;
}