#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <ostream>

class HumanB
{
private:
	Weapon	*myWeapon;
	std::string	name;
public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon& weaponName);
};
#endif