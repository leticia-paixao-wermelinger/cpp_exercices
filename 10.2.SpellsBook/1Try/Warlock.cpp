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
	this->mySpellBook.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string SpellName)
{
	this->mySpellBook.forgetSpell(SpellName);
}

void	Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	ASpell *spell = this->mySpellBook.createSpell(SpellName);
	if (spell)
	{
		target.getHitBySpell(*spell);
		delete spell;
	}
}