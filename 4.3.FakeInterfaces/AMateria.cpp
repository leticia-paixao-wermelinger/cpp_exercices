/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:32:15 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/22 14:32:16 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

/*-------------------------- ORTHODOX CANONICAL FORM --------------------------*/

AMateria::AMateria() : _type(default_type)
{}

AMateria::AMateria(const AMateria &src) : _type(src.getType())
{
    *this = src;
}

AMateria & AMateria::operator=( const AMateria & src )
{
    (void)src;
    return *this;
}

AMateria::~AMateria()
{}

/*-------------------------- ADDITIONAL CONSTRUCTORS --------------------------*/

AMateria::AMateria(std::string const & type) : _type(type)
{}

/*-------------------------- GETTERS --------------------------*/

std::string const & AMateria::getType() const
{
    return this->_type;
}

/*-------------------------- METHODS FROM AMATERIA --------------------------*/

AMateria* AMateria::clone() const // O que faezr aqui?
{
    return 0;
}

void AMateria::use(ICharacter& target) // O que fazer aqui?
{
    std::cout << "Nothing to be used with " << target.getName() << std::endl;
}