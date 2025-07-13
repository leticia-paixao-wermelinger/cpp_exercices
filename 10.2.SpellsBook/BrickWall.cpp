#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{}

BrickWall::BrickWall(const BrickWall & src) : ATarget("Inconspicuous Red-brick Wall")
{
	*this = src;
}

BrickWall & BrickWall::operator=(const BrickWall & src)
{
	if (&src != this){}
	return *this;
}

BrickWall::~BrickWall()
{}

BrickWall *BrickWall::clone()
{
	return new BrickWall;
}