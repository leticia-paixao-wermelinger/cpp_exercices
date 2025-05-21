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

void	testCatHardCopy();

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
		std::cout << "Construindo i = " << i + 1 << std::endl;
		if (i < 50)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		print("");
	}

	testCatHardCopy();

	print("");
	print("=== Limpeza: ===");
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Destruindo i = " << i + 1 << std::endl;
		delete meta[i];
	}

	print("");
	print("=== Destrução finalizada ===");
	return 0;
}

void	testCatHardCopy()
{
	print("");
	print("=== Testando hard copies: ===");
	
	Cat originalCat;
	print("Vai chamar originalCat.setType(Original Cat):");
	originalCat.setType("Original Cat");

	// Atribui uma ideia para o original
	print("Va setar a ideia comer peixe");
	originalCat.setIdea("Comer peixe");

	// Construtor de cópia
	print("Vai chamar o construtr de cópia");
	Cat copiedCat(originalCat);

	// Verifica se são diferentes objetos
	std::cout << "Endereço do Brain do original: " << originalCat.getBrain() << std::endl;
	std::cout << "Endereço do Brain da cópia:    " << copiedCat.getBrain() << std::endl;

	// Verifica se as ideias foram copiadas corretamente
	std::cout << "Ideia original: ";
	originalCat.printIdea(0);
	print("");
	std::cout << "Ideia na cópia: ";
	copiedCat.printIdea(0);
	print("");

	// Modifica a cópia
	copiedCat.changeIdea(0, "Dormir no sol");

	// Verifica se o original não mudou
	std::cout << "Após modificação:\n";
	std::cout << "Ideia original: ";
	originalCat.printIdea(0);
	print("");
	std::cout << "Ideia na cópia: ";
	copiedCat.printIdea(0);
	print("");
}

void	testDogHardCopy()
{
	print("");
	print("=== Testando hard copies: ===");
	
	Dog originalDog;
	print("Vai chamar originalDog.setType(Original Dog):");
	originalDog.setType("Original Dog");

	// Atribui uma ideia para o original
	print("Va setar a ideia correr");
	originalDog.setIdea("Correr");

	// Construtor de cópia
	print("Vai chamar o construtr de cópia");
	Dog copiedDog(originalDog);

	// Verifica se são diferentes objetos
	std::cout << "Endereço do Brain do original: " << originalDog.getBrain() << std::endl;
	std::cout << "Endereço do Brain da cópia:    " << copiedDog.getBrain() << std::endl;

	// Verifica se as ideias foram copiadas corretamente
	std::cout << "Ideia original: ";
	originalDog.printIdea(0);
	print("");
	std::cout << "Ideia na cópia: ";
	copiedDog.printIdea(0);
	print("");

	// Modifica a cópia
	copiedDog.changeIdea(0, "Dormir no sol");

	// Verifica se o original não mudou
	std::cout << "Após modificação:\n";
	std::cout << "Ideia original: ";
	originalDog.printIdea(0);
	print("");
	std::cout << "Ideia na cópia: ";
	copiedDog.printIdea(0);
	print("");
}
/*
int	main()
{
	testDogHardCopy();
	return 0;
}*/