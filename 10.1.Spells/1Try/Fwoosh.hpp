#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		Fwoosh(Fwoosh const & src);
		Fwoosh & operator=(Fwoosh const & src);
		void	launch(const ATarget & target);
		ASpell *clone() const;
};