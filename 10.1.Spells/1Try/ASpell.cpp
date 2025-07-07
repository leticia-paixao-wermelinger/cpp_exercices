#include "ASpell.hpp"

ASpell::ASpell()
{
	this->_name = "default";
	this->_effect = "default";
}

ASpell::ASpell(std::string name, std::string effect)
{
	this->_name = name;
	this->_effect = effect;
}

ASpell::~ASpell()
{}

ASpell::ASpell(ASpell const & src)
{
	*this = src;
}

ASpell & ASpell::operator=(ASpell const & src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_effect = src.getEffects();
	}
	return *this;
}

std::string	ASpell::getName() const
{
	return this->_name;
}

std::string ASpell::getEffects() const
{
	return this->_effect;
}