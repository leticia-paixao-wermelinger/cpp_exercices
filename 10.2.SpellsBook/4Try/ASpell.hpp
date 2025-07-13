#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string _name;
		std::string _effects;
	public:
		ASpell();
		ASpell(std::string name, std::string effect);
		ASpell(const ASpell & src);
		ASpell & operator=(const ASpell & src);
		virtual ~ASpell();
		std::string const & getName() const;
		std::string const & getEffect() const;
		void	launch(ATarget const & target) const;
		virtual ASpell *clone()= 0;
};
