#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	private:
		Polymorph(const Polymorph & src);
		Polymorph & operator=(const Polymorph & src);
	public:
		Polymorph();
		~Polymorph();
		Polymorph *clone();
};