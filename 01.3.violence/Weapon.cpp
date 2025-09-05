#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

Weapon::~Weapon()
{
}

const std::string	Weapon::getType()
{
	std::string &refType = this->type;
	return (refType);
}

void	Weapon::setType(std::string type)
{
/*	if (this->type)
		delete(this->type);*/
	this->type = type;
	//std::cout << "Teste de debug em setType dentro de Weapon. type == " << this->type << std::endl;
}