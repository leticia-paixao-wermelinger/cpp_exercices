/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 00:26:33 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 00:26:34 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
//	this->_name = "Default";
//	ClapTrap::_name = "Default_clap_name";
	this->setAllAttributes("Default");
	std::cout << "The standard DiamondTrap has been initiated" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : FragTrap(name), ScavTrap(name)
{
//	this->_name = name;
//	ClapTrap::_name = name + "_clap_name";
	this->setAllAttributes(name);
	std::cout << "DiamondTrap " << name << " has been initiated" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " has been destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap " << this->_name << " has been copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
		this->setAllAttributes(other.getName());
	std::cout << "DiamondTrap " << this->_name << " has been assigned" << std::endl;
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Who am I?" << std::endl;
	std::cout << "I'm " << this->_name << " in my DiamondTrap form..." << std::endl;
	std::cout << "And I'm " << ClapTrap::_name << " in my ClapTrap form." << std::endl;
}

void	DiamondTrap::setAllAttributes(const std::string& name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	setHitPoints();
	setEnergyPoints();
	setAttackDamage();
}

void	DiamondTrap::setAllAttributes()
{
	this->setHitPoints();
	this->setEnergyPoints();
	this->setAttackDamage();
}

void	DiamondTrap::setHitPoints() // FragTrap
{
	this->_hitPoints = 100;
}

void	DiamondTrap::setEnergyPoints() // ScavTrap
{
	this->_energyPoints = 50;
}

void	DiamondTrap::setAttackDamage() // FragTrap
{
	this->_attackDamage = 30;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

std::string	DiamondTrap::getName() const
{
	return this->_name;
}