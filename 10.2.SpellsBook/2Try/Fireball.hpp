#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell
{
	private:
		Fireball(const Fireball & src);
		Fireball & operator=(const Fireball & src);
	public:
		Fireball();
		~Fireball();
		Fireball *clone();
};