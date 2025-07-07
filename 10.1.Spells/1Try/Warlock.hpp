#pragma once

#include <string>
#include "ASpell.hpp"
#include <map>

class Warlock
{
	private:
		std::map<std::string, ASpell*>	_spells;
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(const Warlock & src);
		Warlock & operator=(const Warlock & src);
	public:
		Warlock(std::string name, std::string title);
		~Warlock();
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle(std::string const & title);
		void introduce() const;
		void	learnSpell(ASpell const *spell);
		void	forgetSpell(std::string SpellName);
		void	launchSpell(std::string SpellName, ATarget const & target);
};
