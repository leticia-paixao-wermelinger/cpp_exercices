#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
private:
	std::string _type;
public:
	ATarget();
	ATarget(std::string type);
	~ATarget();
	ATarget(ATarget const & src);
	ATarget & operator=(ATarget const & src);
	std::string const & getType() const;
	void	getHitBySpell(ASpell const & spell) const;
	virtual ATarget *clone() const = 0;
};