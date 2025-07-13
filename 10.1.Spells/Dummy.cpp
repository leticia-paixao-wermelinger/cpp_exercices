#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{}

Dummy::Dummy(const Dummy & src) : ATarget("Target Practice Dummy")
{
	*this = src;
}

Dummy & Dummy::operator=(const Dummy & src)
{
	if (&src != this){}
	return *this;
}

Dummy::~Dummy()
{}

Dummy *Dummy::clone()
{
	return new Dummy;
}