#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{}

Fwoosh::Fwoosh(const Fwoosh & src) : ASpell("Fwoosh", "fwooshed")
{
	*this = src;
}

Fwoosh & Fwoosh::operator=(const Fwoosh & src)
{
	if (&src != this){}
	return *this;
}

Fwoosh::~Fwoosh()
{}

Fwoosh *Fwoosh::clone()
{
	return new Fwoosh;
}