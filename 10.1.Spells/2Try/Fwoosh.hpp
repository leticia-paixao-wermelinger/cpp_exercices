#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	private:
		Fwoosh(const Fwoosh & src);
		Fwoosh & operator=(const Fwoosh & src);
	public:
		Fwoosh();
		~Fwoosh();
		Fwoosh *clone();
};