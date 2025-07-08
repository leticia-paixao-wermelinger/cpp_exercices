#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string _type;
		ATarget(const ATarget & src);
		ATarget & operator=(const ATarget & src);
	public:
		ATarget();
		ATarget(std::string type);
		virtual ~ATarget();
		std::string const & getType() const;
		void	getHitBySpell(const ASpell & spell) const;
		virtual ATarget *clone() = 0;
};