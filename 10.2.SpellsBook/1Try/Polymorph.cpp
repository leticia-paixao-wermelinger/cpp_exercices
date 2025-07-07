#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{}

Polymorph::~Polymorph()
{}

Polymorph::Polymorph(Polymorph const & src) : ASpell(src.getName(), src.getEffects())
{}

Polymorph & Polymorph::operator=(Polymorph const & src) // REVER AQUI
{
	if (this != &src)
	{}
	return *this;
}

void	Polymorph::launch(const ATarget &target)
{
	target.getHitBySpell(*this);
}

ASpell *Polymorph::clone() const
{
	return new Polymorph(*this);
}