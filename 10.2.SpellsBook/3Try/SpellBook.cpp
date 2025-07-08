#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = this->mySpels.begin(); it != this->mySpels.end(); ++it)
		delete it->second;
	this->mySpels.clear();
}

void	SpellBook::learnSpell(ASpell *sp)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpels.find(sp->getName());
	if (it == this->mySpels.end())
		this->mySpels[sp->getName()] = sp->clone();
}

void	SpellBook::forgetSpell(std::string const & SpellName)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpels.find(SpellName);
	if (it != this->mySpels.end())
	{
		delete it->second;
		this->mySpels.erase(SpellName);
	}
}

ASpell	*SpellBook::createSpell(std::string const & SpellName)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpels.find(SpellName);
	if (it != this->mySpels.end())
		return it->second->clone();
	return NULL;
}