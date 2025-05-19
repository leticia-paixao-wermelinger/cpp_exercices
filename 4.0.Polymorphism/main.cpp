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

/*
int main() // subject main
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();
	return 0;
}*/

void	print(std::string str)
{
	std::cout << str << std::endl;
}

int	main()
{
	print("=== Construções das classes: ===");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* notAnimal = new WrongAnimal();
	const WrongAnimal* notCat = new WrongCat();

	print("meta = " + meta->getType());
	print("j = " + j->getType());
	print("i = " + i->getType());
	print("notAnimal = " + notAnimal->getType());
	print("notCat = " + notCat->getType());
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();
	notAnimal->makeSound();
	notCat->makeSound();
	delete(meta);
	delete(j);
	delete(i);
	delete(notAnimal);
	delete(notCat);
	return 0;
}
