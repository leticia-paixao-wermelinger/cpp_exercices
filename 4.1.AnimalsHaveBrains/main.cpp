/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:07:26 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/05/15 22:08:28 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	print(std::string str)
{
	std::cout << str << std::endl;
}

int	main()
{
	print("=== Construção de array de Animals: ===");
	Animal *meta[100];

	print("=== Construções das classes Cats e Dogs: ===");
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Construindo i = " << i << std::endl;
		if (i < 50)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		print("");
	}

	print("");
	print("=== Testando hard copies: ===");

	print("");
	print("=== Limpeza: ===");
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Destruindo i = " << i << std::endl;
		delete meta[i];
	}

	print("");
	print("=== Destrução finalizada ===");
	return 0;
}
