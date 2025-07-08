#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell*>	mySpells;
		SpellBook(const SpellBook & src);
		SpellBook & operator=(const SpellBook & src);
	public:
		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spellName);
		ASpell	*createSpell(std::string const spellName);
};