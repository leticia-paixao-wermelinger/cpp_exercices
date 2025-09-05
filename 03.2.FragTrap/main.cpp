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

#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "--- Criando FragTrap ---" << std::endl;
    FragTrap Frag("Marvin");

    std::cout << std::endl;
    Frag.printAllAttributes();

    std::cout << "\n--- Testando ataque ---" << std::endl;
    Frag.attack("Intruder");

    std::cout << "\n--- Testando pedido de high five ---" << std::endl;
    Frag.highFivesGuys();

    std::cout << "\n--- Testando dano e reparo ---" << std::endl;
    Frag.takeDamage(30);
    Frag.beRepaired(10);

    std::cout << std::endl;
    Frag.printAllAttributes();

    std::cout << "\n--- Testando esgotar energia com ataques ---" << std::endl;
    for (int i = 0; i < 50; ++i)
    {
        std::cout << "Energy Points: ";
        Frag.printEnergyPoints();
        Frag.attack("Dummy");
    }

    std::cout << "\n--- Tentando atacar sem energia ---" << std::endl;
    Frag.attack("Dummy");

    std::cout << "\n--- Testando pedido de high five sem energia ---" << std::endl;
    Frag.highFivesGuys();  // Isso não depende da energia, então ainda deve funcionar

    std::cout << std::endl;
    Frag.printAllAttributes();

    std::cout << "\n--- Destruindo FragTrap ---" << std::endl;

    return 0;
}