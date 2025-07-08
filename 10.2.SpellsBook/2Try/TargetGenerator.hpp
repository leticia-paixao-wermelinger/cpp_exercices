#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map<std::string, ATarget*>	myTgts;
		TargetGenerator(const TargetGenerator & src);
		TargetGenerator & operator=(const TargetGenerator & src);
	public:
		TargetGenerator();
		~TargetGenerator();
		void	learnTargetType(ATarget *Tgt);
		void	forgetTargetType(std::string TgtName);
		ATarget	*createTarget(std::string const TgtName);
};