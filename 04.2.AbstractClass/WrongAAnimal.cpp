/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:11:03 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:11:05 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal() : _type("Wrong AAnimal")
{
	std::cout << "WrongAAnimal default constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAAnimal " << type << " constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal &src)
{
//	*this = src;
	this->_type = src._type;
	std::cout << "WrongAAnimal copy constructor called" << std::endl;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "WrongAAnimal destructor called" << std::endl;
}

WrongAAnimal &WrongAAnimal::operator=(const WrongAAnimal &src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void WrongAAnimal::makeSound() const
{
	std::cout << "WrongAAnimal's sound" << std::endl;
}

std::string	WrongAAnimal::getType() const
{
	return this->_type;
}

void WrongAAnimal::setType(std::string type)
{
	this->_type = type;
}