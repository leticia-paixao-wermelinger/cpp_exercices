#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	private:
	public:
		Polymorph();
		Polymorph(const Polymorph & src);
		Polymorph & operator=(const Polymorph & src);
		~Polymorph();
		Polymorph *clone();
};