#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string _name;
		std::string _effects;
		ASpell(const ASpell & src);
		ASpell & operator=(const ASpell & src);
	public:
		ASpell();
		ASpell(std::string name, std::string title);
		virtual ~ASpell();
		std::string const & getName() const;
		std::string const & getEffects() const;
		void	launch(ATarget const & tgt);
		virtual ASpell *clone() = 0;
};