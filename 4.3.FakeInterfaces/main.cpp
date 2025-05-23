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

#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

/*
void	print(std::string str)
{
	std::cout << str << std::endl;
}*/
/*
int main() // subject
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	return 0;
}*/

int main() {
	std::cout<< "----------CREATION AND CLONING MATERIAS------------" << std::endl << std::endl;
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	AMateria* iceD = new Ice();
	AMateria* cureD = new Cure();

	std::cout << "Original Ice type: " << ice->getType() << ", Address: " << ice << std::endl;
	std::cout << "Original Cure type: " << cure->getType() << ", Address: " << cure << std::endl;
	std::cout << "Original IceD type: " << iceD->getType() << ", Address: " << iceD << std::endl;
	std::cout << "Original CureD type: " << cureD->getType() << ", Address: " << cureD << std::endl;
	
	AMateria* iceClone = ice->clone();
	AMateria* cureClone = cure->clone();
	AMateria* iceCloneD = iceD->clone();
	AMateria* cureCloneD = cureD->clone();

	std::cout << "Cloned Ice type: " << iceClone->getType() << ", Address: " << iceClone << std::endl;
	std::cout << "Cloned Cure type: " << cureClone->getType() << ", Address: " << cureClone << std::endl;
	std::cout << "Cloned IceD type: " << iceCloneD->getType() << ", Address: " << iceCloneD << std::endl;
	std::cout << "Cloned CureD type: " << cureCloneD->getType() << ", Address: " << cureCloneD << std::endl;

	std::cout << std::endl << "----------CHARCTERS CREATION------------" << std::endl << std::endl;
	Character character("Hero");
	Character character1("Dragon");

	std::cout << std::endl << "----------EQUIP FUNCTION------------" << std::endl << std::endl;
	character.equip(ice);
	character.equip(cure);
	character1.equip(iceD);
	character1.equip(cureD);
	
	std::cout << std::endl << "----------USE FUNCTION------------" << std::endl << std::endl;
	ice->use(character1);
	cureCloneD->use(character);
	character.use(0, character1);
	character1.use(1, character);

	std::cout << std::endl << "----------UNEQUIP FUNCTION------------" << std::endl << std::endl;
	character.unequip(1);
	character1.unequip(1);
	
	std::cout << std::endl << "----------EQUIP CLONED MATERIA FUNCTION------------" << std::endl << std::endl;
	character.equip(iceClone);
	character.equip(cureClone);
	character1.equip(iceCloneD);
	character1.equip(cureCloneD);

	std::cout << std::endl << "----------IMATERIA CREATION - NEW MATERIAS------------" << std::endl << std::endl;
	IMateriaSource* source = new MateriaSource();
	AMateria* iceTest = new Ice();
	AMateria* cureTest = new Cure();
	AMateria* iceTest1 = new Ice();
	AMateria* cureTest1 = new Cure();
	AMateria* cureTest2 = new Cure();
	
	std::cout << std::endl << "----------LEARN FUNCTION------------" << std::endl << std::endl;
	source->learnMateria(iceTest);
	source->learnMateria(cureTest);
	source->learnMateria(iceTest1);
	source->learnMateria(cureTest1);
	source->learnMateria(cureTest2);
	
	std::cout << std::endl << "----------CREATE FUNCTION------------" << std::endl << std::endl;
	AMateria* newIce = source->createMateria("ice 🧊");
	if (newIce) {
		std::cout << "Created Materia: " << newIce->getType() << std::endl;
		delete newIce;
	}

	AMateria* newCure = source->createMateria("cure 💊");
	if (newCure) {
		std::cout << "Created Materia: " << newCure->getType() << std::endl;
		delete newCure;
	}

	AMateria* random = source->createMateria("fire");
	if (random) {
		std::cout << "Created Materia: " << random->getType() << std::endl;
		delete random;
	}
	
	delete iceTest;
	delete cureTest;
	delete iceTest1;
	delete cureTest1;
	delete cureTest2;
	delete source;

	return 0;
}