#include "ATarget.hpp"

ATarget::ATarget()
{
	this->_type = "default";
}

ATarget::ATarget(std::string type)
{
	this->_type = type;
}

ATarget::~ATarget()
{}

std::string const & ATarget::getType() const
{
	return this->_type;
}

void	ATarget::getHitBySpell(const ASpell & spell) const
{
	std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}