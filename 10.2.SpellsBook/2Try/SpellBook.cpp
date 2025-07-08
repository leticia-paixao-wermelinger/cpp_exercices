#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = this->mySpells.begin(); it != this->mySpells.end(); ++it)
		delete it->second;
	this->mySpells.clear();
}

void	SpellBook::learnSpell(ASpell *spell)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpells.find(spell->getName());
	if (it == this->mySpells.end())
		this->mySpells[spell->getName()] = spell->clone();
}

void	SpellBook::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpells.find(spellName);
	if (it != this->mySpells.end())
	{
		delete it->second;
		this->mySpells.erase(spellName);
	}
}

ASpell	*SpellBook::createSpell(std::string const spellName)
{
	// receives a string corresponding to the name of a spell, creates it, and returns it.
	std::map<std::string, ASpell*>::iterator it = this->mySpells.find(spellName);
	if (it != this->mySpells.end())
	{
		return it->second->clone();
	}
	return NULL;
}