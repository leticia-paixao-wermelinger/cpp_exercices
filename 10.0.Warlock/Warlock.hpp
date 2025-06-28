#pragma once

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string name;
		std::string title;
	public:
		Warlock();
		~Warlock();
		Warlock(const Warlock & src);
		Warlock & operator=(const Warlock & src);
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle(std::string const & title);
};
