/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:09:42 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/05 17:09:43 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
    setAllAttributes("default");
    std::cout << "ClapTrap " << getName() << " has been created with default name." << std::endl;
}

ClapTrap::ClapTrap( const std::string& name )
{
    setAllAttributes(name);
    std::cout << "ClapTrap " << getName() << " has been created" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap " << getName() << " has been destroyed." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
    *this = other;
    std::cout << "ClapTrap " << other.getName() << " has been copied with the copy constructor." << std::endl;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & rhs)
{
    if (this!= &rhs)
        setAllAttributes(rhs.getName());
    std::cout << "ClapTrap " << rhs.getName() << " has been assigned with the assignment operator." << std::endl;
    return *this;
}