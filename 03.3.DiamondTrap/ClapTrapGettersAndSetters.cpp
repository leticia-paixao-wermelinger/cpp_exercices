/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrapGettersAndSetters.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:04:16 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/14 11:04:17 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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

void ClapTrap::setAllAttributes(const std::string& name)
{
    this->setName(name);
    this->setHitPoints();
    this->setEnergyPoints();
    this->setAttackDamage();
}

void ClapTrap::setAllAttributes()
{
    this->setHitPoints();
    this->setEnergyPoints();
    this->setAttackDamage();
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