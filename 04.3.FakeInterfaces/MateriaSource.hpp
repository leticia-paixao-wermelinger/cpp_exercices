/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:06:26 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/22 17:06:27 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

#define MAX_MEMORY 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*   memory[MAX_MEMORY];
        void    initMemory();
        void    deleteMaterials();
        void    cpyMemory(const MateriaSource &src);
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &src);
        ~MateriaSource();
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
        AMateria*    getMemory(int idx) const;
        void    printMemory();
};