/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:09:00 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:09:01 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	setType(type);
	std::cout << "AAnimal constructor called for " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Entrou no construtor de cópia de AAnimal" << std::endl;
//	*this = src;
	this->_type = src._type;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
//	delete
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal & src)
{
	if (&src != this)
		setType(src.getType());
	std::cout << "AAnimal assignment operator called" << std::endl;
	return *this;
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
}

std::string	AAnimal::getType() const
{
	return this->_type;
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal makes a sound" << std::endl;
}