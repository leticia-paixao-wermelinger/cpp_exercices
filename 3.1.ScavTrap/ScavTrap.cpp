/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:43:05 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/14 11:43:07 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->setHitPoints();
	this->setEnergyPoints();
	this->setAttackDamage();
	std::cout << "The standard ScavTrap has been initiated" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->setHitPoints();
	this->setEnergyPoints();
	this->setAttackDamage();
	std::cout << "ScavTrap " << getName() << " has been initiated" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " has been destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap " << getName() << " has been copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << getName() << " has been assigned" << std::endl;
	return *this;
}

void ScavTrap::setHitPoints()
{
	this->_hitPoints = 100;
}

void	ScavTrap::setEnergyPoints()
{
	this->_energyPoints = 50;
}

void	ScavTrap::setAttackDamage()
{
	this->_attackDamage = 20;
}

void	ScavTrap::attack(const std::string& target)
{
	if (baseAttack() == false)
        return;
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}