#pragma once

#include "ATarget.hpp"

class Dummy : public ATarget
{
	private:
	public:
		Dummy();
		Dummy(const Dummy & src);
		Dummy & operator=(const Dummy & src);
		~Dummy();
		Dummy *clone();
};