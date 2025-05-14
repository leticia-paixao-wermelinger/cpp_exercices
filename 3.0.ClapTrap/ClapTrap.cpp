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
    setName("default");
    setHitPoints();
    setEnergyPoints();
    setAttackDamage();
}

ClapTrap::ClapTrap( const std::string& name )
{
    setName(name);
    setHitPoints();
    setEnergyPoints();
    setAttackDamage();
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
    *this = other;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & rhs)
{
    if (this!= &rhs)
    {
        setName(rhs.getName());
        setHitPoints();
        setEnergyPoints();
        setAttackDamage();
    }
    return *this;
}

void ClapTrap::setName( const std::string& name )
{
    this->_name = name;
}

void ClapTrap::setHitPoints( void )
{
    this->_hitPoints = 10;
}

void ClapTrap::setEnergyPoints( void )
{
    this->_energyPoints = 10;
}

void ClapTrap::setAttackDamage( void )
{
    this->_attackDamage = 0;
}

std::string ClapTrap::getName( void ) const
{
    return this->_name;
}

int ClapTrap::getHitPoints( void ) const
{
    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints( void ) const
{
    return this->_energyPoints;
}

int ClapTrap::getAttackDamage( void ) const
{
    return this->_attackDamage;
}

void    ClapTrap::attack(const std::string& target)
{
    (void)target;
    std::cout << "Fazer a função attack" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    (void)amount;
    std::cout << "Fazer a função takeDamage" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    (void)amount;
    std::cout << "Fazer a função beRepaired" << std::endl;
}