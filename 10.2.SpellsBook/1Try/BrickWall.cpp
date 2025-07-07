#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{}

BrickWall::~BrickWall()
{}

BrickWall::BrickWall(BrickWall const & src) : ATarget("Inconspicuous Red-brick Wall")
{
	(void)src;
}

BrickWall & BrickWall::operator=(BrickWall const & src) // ???
{
	if (this != &src){}
	return *this;
}

void	BrickWall::getHitBySpell(ASpell const & spell)
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}

ATarget *BrickWall::clone() const
{
	return new BrickWall(*this);
}