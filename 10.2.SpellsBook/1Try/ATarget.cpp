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

ATarget::ATarget(ATarget const & src)
{
	*this = src;
}

ATarget & ATarget::operator=(ATarget const & src)
{
	if (this != &src)
	{
		this->_type = src.getType();
	}
	return *this;
}

std::string const & ATarget::getType() const
{
	return this->_type;
}

void	ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}