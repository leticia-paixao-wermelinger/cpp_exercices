#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	private:
		BrickWall(const BrickWall & src);
		BrickWall & operator=(const BrickWall & src);
	public:
		BrickWall();
		~BrickWall();
		BrickWall *clone();
};