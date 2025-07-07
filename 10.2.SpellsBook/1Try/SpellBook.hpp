#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
		std::map<std::string, ASpell*>	book;
		SpellBook(SpellBook const & src);
		SpellBook & operator=(SpellBook const & src);
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *sp);
		void forgetSpell(std::string const & sp);
		ASpell* createSpell(std::string const & sp);
};