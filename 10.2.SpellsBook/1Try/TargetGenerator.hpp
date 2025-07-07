#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map<std::string, ATarget*> tgtTypes;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *newTgt);
		void forgetTargetType(std::string const &tgtName);
		ATarget* createTarget(std::string const &tgtName);
};