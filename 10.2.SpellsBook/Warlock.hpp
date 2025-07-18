#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		SpellBook	mySpels;
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
		void	learnSpell(ASpell *sp);
		void	forgetSpell(std::string SpellName);
		void	launchSpell(std::string SpellName, ATarget & target);
};
