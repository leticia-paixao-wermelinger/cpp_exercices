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

ASpell::ASpell(const ASpell & src)
{
	*this = src;
}

ASpell & ASpell::operator=(const ASpell & src)
{
	if (&src != this)
	{
		this->_name = src.getName();
		this->_effects = src.getEffect();
	}
	return *this;
}

ASpell::~ASpell()
{}

std::string const & ASpell::getName() const
{
	return this->_name;
}

std::string const & ASpell::getEffect() const
{
	return this->_effects;
}

void	ASpell::launch(ATarget const & target) const
{
	target.getHitBySpell(*this);
}