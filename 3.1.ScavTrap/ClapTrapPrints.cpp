/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrapPrints.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:04:37 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/14 11:04:38 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::printAllAttributes()
{
	std::cout << "Current values of ";
	printName();
	std::cout << "Hit Points = ";
	printHitPoints();
	std::cout << "Energy Points = ";
	printEnergyPoints();
	std::cout << "Attack Damage = ";
	printAttackDamage();
}

void	ClapTrap::printName()
{
	std::cout << getName() << std::endl;
}

void	ClapTrap::printHitPoints()
{
	std::cout << getHitPoints() << std::endl;
}

void	ClapTrap::printEnergyPoints()
{
	std::cout << getEnergyPoints() << std::endl;
}

void	ClapTrap::printAttackDamage()
{
	std::cout << getAttackDamage() << std::endl;
}