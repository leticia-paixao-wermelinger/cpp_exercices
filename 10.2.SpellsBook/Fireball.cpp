#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{}

Fireball::Fireball(const Fireball & src) : ASpell("Fireball", "burnt to a crisp")
{
	*this = src;
}

Fireball & Fireball::operator=(const Fireball & src)
{
	if (&src != this){}
	return *this;
}

Fireball::~Fireball()
{}

Fireball *Fireball::clone()
{
	return new Fireball;
}