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
	this->book.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spellName)
{
	this->book.forgetSpell(spellName);
}

void	Warlock::launchSpell(std::string spellName, ATarget & target)
{
	ASpell *spell = this->book.createSpell(spellName);
	if (spell)
	{
		target.getHitBySpell(*spell);
		delete spell;
	}
}