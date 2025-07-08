#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	private:
	public:
		BrickWall();
		BrickWall(const BrickWall & src);
		BrickWall & operator=(const BrickWall & src);
		~BrickWall();
		BrickWall *clone();
};