/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:09:47 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/05 17:09:48 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string _name;
    unsigned int _hitPoints; // iniciado em 10
    unsigned int _energyPoints; // iniciado em 10
    unsigned int _attackDamage; // iniciado em 0
    void        setName( const std::string& name );
    void        setHitPoints( void );
    void        setEnergyPoints( void );
    void        setAttackDamage( void );
    std::string getName( void ) const;
    int         getHitPoints( void ) const;
    int         getEnergyPoints( void ) const;
    int         getAttackDamage( void ) const;
    void        loseHitPoints(unsigned int damage);
public:
    ClapTrap(); // construtor padrão
    ClapTrap(const std::string& name); // construtor com nome
    ClapTrap(const ClapTrap& other); // construtor de cópia
    ClapTrap& operator=(const ClapTrap& other); // operador de atribuição
    ~ClapTrap(); // destrutor
    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    void    printName();
    void    printHitPoints();
    void    printEnergyPoints();
    void    printAttackDamage();
    void    printAllAttributes();
};
#endif