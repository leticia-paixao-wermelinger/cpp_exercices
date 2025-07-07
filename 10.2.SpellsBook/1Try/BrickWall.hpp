#pragma once

#include "ASpell.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall();
		~BrickWall();
		BrickWall(BrickWall const & src);
		BrickWall & operator=(BrickWall const & src);
		void	getHitBySpell(ASpell const & spell);
		ATarget *clone() const;
};