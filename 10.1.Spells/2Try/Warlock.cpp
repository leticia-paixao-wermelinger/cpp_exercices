#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title)
{
	this->_name = name;
	this->_title = title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = this->mySpells.begin(); it != this->mySpells.end(); ++it)
		delete it->second;
	this->mySpells.clear();
}

std::string const & Warlock::getName() const
{
	return this->_name;
}

std::string const & Warlock::getTitle() const
{
	return this->_title;
}

void Warlock::setTitle(std::string const & title)
{
	this->_title = title;
}

void Warlock::introduce() const
{
	std::string myName = getName();
	std::cout << myName << ": I am " << myName << ", " << getTitle() << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpells.find(spell->getName());
	if (it == this->mySpells.end())
		this->mySpells[spell->getName()] = spell->clone();
}

void	Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpells.find(spellName);
	if (it != this->mySpells.end())
	{
		delete it->second;
		this->mySpells.erase(spellName);
	}
}

void	Warlock::launchSpell(std::string spellName, ATarget & target)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpells.find(spellName);
	if (it != this->mySpells.end())
		target.getHitBySpell(*this->mySpells[spellName]);
}