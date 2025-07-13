#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell*> mySpells;
	public:
		SpellBook();
		~SpellBook();
		SpellBook(SpellBook const & src);
		SpellBook & operator=(SpellBook const & src);
		void learnSpell(ASpell * spell);
		void forgetSpell(std::string const & spellName);
		ASpell* createSpell(std::string const & spellName);
};