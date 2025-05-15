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

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== Construção de DiamondTrap ===" << std::endl;
	DiamondTrap dt1("Ruby");

	std::cout << "\n=== Teste de ataque ===" << std::endl;
	dt1.attack("an Evil Target");

	std::cout << "\n=== Teste do whoAmI ===" << std::endl;
	dt1.whoAmI();

    std::cout << std::endl;
	dt1.printAllAttributes();

	std::cout << "\n=== Teste de cópia (copy constructor) ===" << std::endl;
	DiamondTrap dt2(dt1);

	std::cout << "\n=== Teste de atribuição (operator=) ===" << std::endl;
	DiamondTrap dt3;
	dt3 = dt1;

	std::cout << "\n=== Teste de destrutores no final ===" << std::endl;

    return 0;
}