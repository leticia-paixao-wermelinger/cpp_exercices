#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph();
		~Polymorph();
		Polymorph(Polymorph const & src);
		Polymorph & operator=(Polymorph const & src);
		void	launch(const ATarget & target);
		ASpell *clone() const;
};