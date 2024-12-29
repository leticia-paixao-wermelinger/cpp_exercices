#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->myWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weaponName)
{
	this->myWeapon = &weaponName; 
	//std::cout << "Teste de degub: Human B no setWeapon: " << this->myWeapon->getType() << std::endl;
}