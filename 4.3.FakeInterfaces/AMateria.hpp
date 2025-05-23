/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:32:19 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/22 14:32:20 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//#include "ICharacter.hpp"
#include <iostream>

#define default_type "default"

class ICharacter;

class AMateria
{
    protected:
        const std::string _type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &src);
        AMateria &operator=(const AMateria &src);
        virtual ~AMateria();
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};