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

#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "--- Criando ScavTrap ---" << std::endl;
    ScavTrap scav("GateMaster");

    std::cout << std::endl;
    scav.printAllAttributes();

    std::cout << "\n--- Testando ataque ---" << std::endl;
    scav.attack("Intruder");

    std::cout << "\n--- Testando modo Gate Keeper ---" << std::endl;
    scav.guardGate();

    std::cout << "\n--- Testando dano e reparo ---" << std::endl;
    scav.takeDamage(30);
    scav.beRepaired(10);

    std::cout << std::endl;
    scav.printAllAttributes();

    std::cout << "\n--- Testando esgotar energia com ataques ---" << std::endl;
    for (int i = 0; i < 50; ++i)
    {
        std::cout << "Energy Points: ";
        scav.printEnergyPoints();
        scav.attack("Dummy");
    }

    std::cout << "\n--- Tentando atacar sem energia ---" << std::endl;
    scav.attack("Dummy");

    std::cout << "\n--- Testando modo Gate Keeper sem energia ---" << std::endl;
    scav.guardGate();  // Isso não depende da energia, então ainda deve funcionar

    std::cout << std::endl;
    scav.printAllAttributes();

    std::cout << "\n--- Destruindo ScavTrap ---" << std::endl;

    return 0;
}