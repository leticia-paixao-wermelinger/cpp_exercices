#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball();
		~Fireball();
		Fireball(Fireball const & src);
		Fireball & operator=(Fireball const & src);
		void	launch(const ATarget & target);
		ASpell *clone() const;
};