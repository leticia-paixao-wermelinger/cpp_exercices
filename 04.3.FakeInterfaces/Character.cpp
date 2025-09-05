/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:38:10 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/22 16:38:11 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*-------------------------- ORTHODOX CANONICAL FORM --------------------------*/

Character::Character()
{
    this->_name = "default";
    initInventory();
}

Character::Character(const Character &src)
{
    *this = src; // Como ta chamando o operator=, se ele for profundo aqui fica profundo tb...
}

Character & Character::operator=( const Character & src )
{
    if (this != &src)
    {
        initInventory();
        cpyInventory(src);
        this->_name = src.getName();
    }
    return *this;
}

Character::~Character()
{
    deleteMaterials();
}

/*-------------------------- ADDITIONAL CONSTRUCTORS --------------------------*/

Character::Character(std::string name)
{
    this->_name = name;
    initInventory();
}

/*-------------------------- METHODS FROM ICHARACTER --------------------------*/

std::string const & Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        if (this->inventory[i] == 0)
        {
            this->inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < MAX_INVENTORY && this->inventory[idx])
    {
        this->inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
        std::cerr << "Impossible idx " << idx << std::endl;
    else if (this->inventory[idx] == 0)
        std::cerr << "Idx " << idx << " is empty." << std::endl;
    else if (this->inventory[idx])
        this->inventory[idx]->use(target);
    else
        std::cerr << "Unidentified error" << std::endl;
}

/*-------------------------- EXTRA METHODS --------------------------*/

void    Character::initInventory()
{
    for (int i = 0; i < MAX_INVENTORY; i++)
        this->inventory[i] = 0;
}

AMateria*    Character::getInventory(int idx) const
{
    if (inventory[idx] == 0)
        return this->inventory[idx];
    return 0;
}

void    Character::cpyInventory( const Character & src )
{
    deleteMaterials();
    initInventory();
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        if (src.getInventory(i))
            equip(src.getInventory(i));
    }
}

void    Character::deleteMaterials()
{
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        if (this->inventory[i] && this->inventory[i] != 0)
        {
            delete this->inventory[i];
            this->inventory[i] = 0;
        }
    }
}

void    Character::printInventory()
{
    for (int i = 0; i < MAX_INVENTORY; i++)
        if (this->inventory[i] && this->inventory[i] != 0)
            std::cout << "inventory[" << i << "] = " << this->inventory[i]->getType() << " at address " << &this->inventory[i] << std::endl;
        else if (this->inventory[i] == 0)
            std::cout << "inventory[" << i << "] = (empty) at address " << &this->inventory[i] << std::endl;
        else
            std::cout << "inventory[" << i << "] = (unidentified)" << std::endl;
}