#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map<std::string, ATarget*>	tgtTypes;
		TargetGenerator(const TargetGenerator & src);
		TargetGenerator & operator=(const TargetGenerator & src);
	public:
		TargetGenerator();
		~TargetGenerator();
		void	learnTargetType(ATarget *tgt);
		void	forgetTargetType(std::string const & TargetType);
		ATarget	*createTarget(std::string const & TargetType);
};
