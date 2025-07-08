#include "ASpell.hpp"

ASpell::ASpell()
{
	this->_name = "default";
	this->_effects = "default";
}

ASpell::ASpell(std::string name, std::string effect)
{
	this->_name = name;
	this->_effects = effect;
}

ASpell::~ASpell()
{}

std::string const & ASpell::getName() const
{
	return this->_name;
}

std::string const & ASpell::getEffects() const
{
	return this->_effects;
}

void	ASpell::launch(ATarget const & tgt)
{
	tgt.getHitBySpell(*this);
}