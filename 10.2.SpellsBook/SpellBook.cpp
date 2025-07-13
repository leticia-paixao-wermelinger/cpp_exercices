#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	// Essa limpeza estava dando erro na prova e tive que retirar... Não compilava...
/*	for (std::map<std::string, ASpell*>::iterator it = this->mySpells.begin(); it != this->mySpells.end(); ++it)
		delete it->second;*/
	this->mySpells.clear();
}

SpellBook::SpellBook(SpellBook const & src)
{
	*this = src;
}

SpellBook & SpellBook::operator=(SpellBook const & src)
{
	(void)src;
	return *this;
}

void SpellBook::learnSpell(ASpell * spell)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpells.find(spell->getName());
	if (it == this->mySpells.end())
		this->mySpells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const & spellName)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpells.find(spellName);
	if (it != this->mySpells.end())
	{
		delete it->second;
		this->mySpells.erase(spellName);
	}
}

ASpell* SpellBook::createSpell(std::string const & spellName)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpells.find(spellName);
	if (it != this->mySpells.end())
		return this->mySpells[spellName]->clone();
	return NULL;
}