#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	private:
	public:
		Fwoosh();
		Fwoosh(const Fwoosh & src);
		Fwoosh & operator=(const Fwoosh & src);
		~Fwoosh();
		Fwoosh *clone();
};