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
	for (std::map<std::string, ASpell*>::iterator it = this->mySpels.begin(); it != this->mySpels.end(); ++it)
		delete it->second;
	this->mySpels.clear();
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

void	Warlock::learnSpell(ASpell *sp)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpels.find(sp->getName());
	if (it == this->mySpels.end())
		this->mySpels[sp->getName()] = sp->clone();
}

void	Warlock::forgetSpell(std::string SpellName)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpels.find(SpellName);
	if (it == this->mySpels.end())
	{
		delete it->second;
		this->mySpels.erase(SpellName);
	}
}

void	Warlock::launchSpell(std::string SpellName, ATarget & target)
{
	std::map<std::string, ASpell*>::iterator it = this->mySpels.find(SpellName);
	if (it == this->mySpels.end())
		target.getHitBySpell(*this->mySpels[SpellName]);
}