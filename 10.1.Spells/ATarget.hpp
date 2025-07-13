#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string _type;
	public:
		ATarget();
		ATarget(std::string type);
		ATarget(const ATarget & src);
		ATarget & operator=(const ATarget & src);
		virtual ~ATarget();
		std::string const & getType() const;
		void getHitBySpell(ASpell const & spell) const;
		virtual ATarget *clone()= 0;
};