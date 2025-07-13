#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{}

Polymorph::Polymorph(const Polymorph & src) : ASpell("Polymorph", "turned into a critter")
{
	*this = src;
}

Polymorph & Polymorph::operator=(const Polymorph & src)
{
	if (&src != this){}
	return *this;
}

Polymorph::~Polymorph()
{}

Polymorph *Polymorph::clone()
{
	return new Polymorph;
}