#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <ostream>

class HumanA
{
private:
	Weapon	&myWeapon;
	std::string	name;
public:
	HumanA(std::string name, Weapon &newWeapon);
	~HumanA();
	void	attack();
	void	setWeapon(Weapon &weaponName);
};
#endif