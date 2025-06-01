/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:06:13 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/22 17:06:14 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*-------------------------- ORTHODOX CANONICAL FORM --------------------------*/

MateriaSource::MateriaSource()
{
    initMemory();
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    *this = src; // Como ta chamando o operator=, se ele for profundo aqui fica profundo tb...

}

MateriaSource & MateriaSource::operator=( const MateriaSource & src )
{
    if (this != &src)
        cpyMemory(src);
    return *this;
}

MateriaSource::~MateriaSource()
{
    deleteMaterials();
}

/*-------------------------- METHODS FROM IMATERIALSOURCE --------------------------*/

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < MAX_MEMORY; i++)
    {
        if (this->memory[i] == 0)
        {
            this->memory[i] = m;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < MAX_MEMORY; i++)
    {
        if (this->memory[i] && this->memory[i]->getType() == type)
            return this->memory[i]->clone();
    }
    return NULL;
}

/*-------------------------- EXTRA METHODS --------------------------*/

void    MateriaSource::initMemory()
{
    for (int i = 0; i < MAX_MEMORY; i++)
        this->memory[i] = 0;
}

void    MateriaSource::cpyMemory(const MateriaSource &src)
{
    initMemory();
    for (int i = 0; i < MAX_MEMORY; i++)
    {
        if (src.getMemory(i))
            learnMateria(src.getMemory(i)->clone());
    }
}

AMateria*   MateriaSource::getMemory(int idx) const
{
    if (idx >= 0 && idx < MAX_MEMORY)
        return this->memory[idx];
    return 0;
}

void    MateriaSource::deleteMaterials()
{
    for (int i = 0; i < MAX_MEMORY; i++)
    {
        if (this->memory[i])
        {
            delete this->memory[i];
            this->memory[i] = 0;
        }
    }
}

void    MateriaSource::printMemory()
{
    for (int i = 0; i < MAX_MEMORY; i++)
    {
        if (this->memory[i] && ((this->memory[i]->getType() == "ice") || (this->memory[i]->getType() == "cure")))
        {
            std::cout << "memory[" << i << "] = " << this->memory[i]->getType() << " at address " << &this->memory[i] << std::endl;
        }
        else if (this->memory[i] && this->memory[i]->getType() == "cure")
        {
            std::cout << "memory[" << i << "] = " << this->memory[i]->getType() << " at address " << &this->memory[i] << std::endl;
        }
        else
            std::cout << "memory[" << i << "] = (empty)" << std::endl;
    }
}