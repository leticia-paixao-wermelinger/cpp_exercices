/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:59:53 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/22 14:59:55 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*-------------------------- ORTHODOX CANONICAL FORM --------------------------*/

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure &src) : AMateria(src.getType())
{
    *this = src;
}

Cure & Cure::operator=( const Cure & src )
{
    (void)src;
    return *this;
}

Cure::~Cure()
{}

/*-------------------------- ADDITIONAL CONSTRUCTORS --------------------------*/



/*-------------------------- METHODS FROM Cure --------------------------*/

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}