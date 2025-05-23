/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:59:43 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/22 14:59:44 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*-------------------------- ORTHODOX CANONICAL FORM --------------------------*/

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice &src) : AMateria(src.getType())
{
    *this = src;
}

Ice & Ice::operator=( const Ice & src )// : AMateria(src.getType())
{
    (void)src;
    return *this;
}

Ice::~Ice()
{}

/*-------------------------- ADDITIONAL CONSTRUCTORS --------------------------*/



/*-------------------------- METHODS FROM AMATERIA --------------------------*/

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}