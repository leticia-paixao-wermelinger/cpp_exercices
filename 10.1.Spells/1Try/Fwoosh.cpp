#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{}

Fwoosh::~Fwoosh()
{}

Fwoosh::Fwoosh(Fwoosh const & src) : ASpell(src.getName(), src.getEffects())
{}

Fwoosh & Fwoosh::operator=(Fwoosh const & src) // REVER AQUI
{
	if (this != &src)
	{}
	return *this;
}

void	Fwoosh::launch(const ATarget &target)
{
	target.getHitBySpell(*this);
}

ASpell *Fwoosh::clone() const
{
	return new Fwoosh(*this);
}