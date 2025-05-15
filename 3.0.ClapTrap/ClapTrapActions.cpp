/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrapActions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:03:54 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/14 11:03:55 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void    ClapTrap::loseHitPoints(unsigned int damage)
{
    int newHitPoints = getHitPoints() - damage;
    if (newHitPoints < 0)
        newHitPoints = 0;
    this->_hitPoints = newHitPoints;
}

void    ClapTrap::attack(const std::string& target)
{
    if (getEnergyPoints() == 0)
    {
        std::cout << "ClapTrap " << getName() << " can not attack, for it is out of energy points!" << std::endl;
        return;
    }
    else if (getHitPoints() == 0)
    {
        std::cout << "ClapTrap " << getName() << " can not attack, for it has no more life (HP)!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() == 0)
    {
        std::cout << "ClapTrap " << getName() << " can not be damaged, for it has no more life (HP)." << std::endl;
        return;
    }
    loseHitPoints(amount);
    std::cout << "ClapTrap " << getName() << " has suffered an attack of " << amount << ". Remaining HP: " << getHitPoints() << "." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (getEnergyPoints() == 0)
    {
        std::cout << "ClapTrap " << getName() << " can not be repaired, for it is out of energy points!" << std::endl;
        return;
    }
    else if (getHitPoints() == 0)
    {
        std::cout << "ClapTrap " << getName() << " can not attack, for it has no more life (HP)!" << std::endl;
        return;
    }
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << "ClapTrap " << getName() << " repaired itself, gaining " << amount << " hit points. Remaining HP: " << getHitPoints() << "." << std::endl;
}