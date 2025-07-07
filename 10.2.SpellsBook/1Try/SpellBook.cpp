#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = this->book.begin(); it != this->book.end(); ++it)
		delete it->second;
	this->book.clear();
}

void SpellBook::learnSpell(ASpell *sp)
{
	if (sp)
	{
		std::map<std::string, ASpell*>::iterator it = this->book.find(sp->getName());
		if (it == this->book.end())
			this->book[sp->getName()] = sp->clone();
	}
}

void SpellBook::forgetSpell(std::string const & sp)
{
	std::map<std::string, ASpell*>::iterator it = this->book.find(sp);
	if (it != this->book.end())
	{
		delete it->second;
		this->book.erase(sp);
	}
}

ASpell* SpellBook::createSpell(std::string const & sp)
{
	std::map<std::string, ASpell*>::iterator it = this->book.find(sp);
	if (it != this->book.end())
		return it->second->clone();
	return NULL;
}