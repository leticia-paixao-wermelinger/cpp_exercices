#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{}

Fireball::~Fireball()
{}

Fireball::Fireball(Fireball const & src) : ASpell(src.getName(), src.getEffects())
{}

Fireball & Fireball::operator=(Fireball const & src) // REVER AQUI
{
	if (this != &src)
	{}
	return *this;
}

void	Fireball::launch(const ATarget &target)
{
	target.getHitBySpell(*this);
}

ASpell *Fireball::clone() const
{
	return new Fireball(*this);
}