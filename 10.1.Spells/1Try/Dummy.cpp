#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{}

Dummy::~Dummy()
{}

Dummy::Dummy(Dummy const & src) : ATarget("Target Practice Dummy")
{
	(void)src;
}

Dummy & Dummy::operator=(Dummy const & src) // ???
{
	if (this != &src){}
	return *this;
}

void	Dummy::getHitBySpell(ASpell const & spell)
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}

ATarget *Dummy::clone() const
{
	return new Dummy(*this);
}