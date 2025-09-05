/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:38:02 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/22 16:38:06 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#define MAX_INVENTORY 4

class Character : public ICharacter
{
    private:
        AMateria* inventory[MAX_INVENTORY];
        std::string _name;
        void    initInventory();
        void    cpyInventory( const Character & src );
        void    deleteMaterials();
    public:
        Character();
        Character(const Character &src);
        Character &operator=(const Character &src);
        ~Character();
        Character(std::string name);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria*    getInventory(int idx) const;
        void    printInventory();
};