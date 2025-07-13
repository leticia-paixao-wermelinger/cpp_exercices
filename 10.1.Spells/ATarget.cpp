#include "ATarget.hpp"

ATarget::ATarget()
{
	this->_type = "default";
}

ATarget::ATarget(std::string type)
{
	this->_type = type;
}

ATarget::ATarget(const ATarget & src)
{
	*this = src;
}

ATarget & ATarget::operator=(const ATarget & src)
{
	if (&src != this){}
	return *this;
}

ATarget::~ATarget()
{}

std::string const & ATarget::getType() const
{
	return this->_type;
}

void ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << this->_type << " has been " << spell.getEffect() << "!" << std::endl;
}