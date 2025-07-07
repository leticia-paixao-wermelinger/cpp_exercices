#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string	_effect;
	public:
		ASpell();
		ASpell(std::string name, std::string effect);
		~ASpell();
		ASpell(ASpell const & src);
		ASpell & operator=(ASpell const & src);
		std::string	getName() const;
		std::string getEffects() const;
		void	launch(const ATarget & target) const;
		virtual ASpell *clone() const = 0;
};