#pragma once

#include "ATarget.hpp"

class Dummy : public ATarget
{
	private:
		Dummy(const Dummy & src);
		Dummy & operator=(const Dummy & src);
	public:
		Dummy();
		~Dummy();
		Dummy *clone();
};