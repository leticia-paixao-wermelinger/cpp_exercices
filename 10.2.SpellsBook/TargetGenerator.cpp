#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget*>::iterator it = this->tgtTypes.begin(); it != tgtTypes.end(); ++it)
		delete it->second;
	this->tgtTypes.clear();
}

void TargetGenerator::learnTargetType(ATarget *newTgt)
{
	if (newTgt)
	{
		std::map<std::string, ATarget*>::iterator it = this->tgtTypes.find(newTgt->getType());
		if (it == this->tgtTypes.end())
			this->tgtTypes[newTgt->getType()] = newTgt->clone();
	}
}

void TargetGenerator::forgetTargetType(std::string const &tgtName)
{
	std::map<std::string, ATarget*>::iterator it = this->tgtTypes.find(tgtName);
	if (it != this->tgtTypes.end())
	{
		delete it->second;
		this->tgtTypes.erase(tgtName);
	}
}

ATarget* TargetGenerator::createTarget(std::string const &tgtName)
{
	std::map<std::string, ATarget*>::iterator it = this->tgtTypes.find(tgtName);
	if (it != this->tgtTypes.end())
		return it->second->clone();
	return NULL;
}