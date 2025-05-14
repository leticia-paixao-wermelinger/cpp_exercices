/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:09:32 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/05 17:09:34 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap robot("Robozinho");

    std::cout << "\n--- Ação: Ataque ---" << std::endl;
    robot.attack("Inimigo1");

    std::cout << "\n--- Ação: Tomando dano ---" << std::endl;
    robot.takeDamage(4);

    std::cout << "\n--- Ação: Reparo ---" << std::endl;
    robot.beRepaired(3);

    std::cout << "\n--- Ação: Tomando muito dano (destruição) ---" << std::endl;
    robot.takeDamage(15);

    //std::cout << std::endl;
    //robot.printAllAttributes();

    std::cout << "\n--- Tentando atacar sem vida ---" << std::endl;
    robot.attack("Inimigo2");

    std::cout << "\n--- Tentando reparar sem vida ---" << std::endl;
    robot.beRepaired(5);

    std::cout << std::endl;

    return 0;
}