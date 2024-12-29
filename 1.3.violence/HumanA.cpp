#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &newWeapon) : myWeapon(newWeapon)
{
	this->name = name;
	this->myWeapon = newWeapon;
	//std::cout << "Teste de degub: Human A no construtor: " << this->myWeapon.getType() << std::endl;
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->myWeapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weaponName)
{
	this->myWeapon = weaponName;
	//std::cout << "Teste de degub: Human A no setWeapon: " << this->myWeapon.getType() << std::endl;
}