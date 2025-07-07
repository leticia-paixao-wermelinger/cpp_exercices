#pragma once

#include "ASpell.hpp"

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();
		Dummy(Dummy const & src);
		Dummy & operator=(Dummy const & src);
		void	getHitBySpell(ASpell const & spell);
		ATarget *clone() const;
};