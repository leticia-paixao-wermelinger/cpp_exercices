#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell
{
	private:
	public:
		Fireball();
		Fireball(const Fireball & src);
		Fireball & operator=(const Fireball & src);
		~Fireball();
		Fireball *clone();
};