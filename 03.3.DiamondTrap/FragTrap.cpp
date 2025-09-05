/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:38:09 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/14 23:38:10 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->setAllAttributes();
	std::cout << "The standard FragTrap has been initiated" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->setAllAttributes();
	std::cout << "FragTrap " << getName() << " has been initiated" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " has been destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << getName() << " has been copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		this->setAllAttributes(other.getName());
	std::cout << "FragTrap " << getName() << " has been assigned" << std::endl;
	return *this;
}

void	FragTrap::setAllAttributes(const std::string& name)
{
	setName(name);
	this->setHitPoints();
	this->setEnergyPoints();
	this->setAttackDamage();
}

void	FragTrap::setAllAttributes()
{
	this->setHitPoints();
	this->setEnergyPoints();
	this->setAttackDamage();
}

void FragTrap::setHitPoints()
{
	this->_hitPoints = 100;
}

void	FragTrap::setEnergyPoints()
{
	this->_energyPoints = 100;
}

void	FragTrap::setAttackDamage()
{
	this->_attackDamage = 30;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " is requesting a high five!" << std::endl;
}