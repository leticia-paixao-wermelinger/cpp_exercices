#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell*>	mySpels;
		SpellBook(const SpellBook & src);
		SpellBook & operator=(const SpellBook & src);
	public:
		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell *sp);
		void	forgetSpell(std::string const & SpellName);
		ASpell	*createSpell(std::string const & SpellName);
};
