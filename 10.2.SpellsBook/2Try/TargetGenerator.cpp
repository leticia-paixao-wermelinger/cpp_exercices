#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget*>::iterator it = this->myTgts.begin(); it != this->myTgts.end(); ++it)
		delete it->second;
	this->myTgts.clear();
}

void	TargetGenerator::learnTargetType(ATarget *Tgt)
{
	std::map<std::string, ATarget*>::iterator it = this->myTgts.find(Tgt->getType());
	if (it == this->myTgts.end())
		this->myTgts[Tgt->getType()] = Tgt->clone();
}

void	TargetGenerator::forgetTargetType(std::string TgtName)
{
	std::map<std::string, ATarget*>::iterator it = this->myTgts.find(TgtName);
	if (it != this->myTgts.end())
	{
		delete it->second;
		this->myTgts.erase(TgtName);
	}
}

ATarget	*TargetGenerator::createTarget(std::string const TgtName)
{
	std::map<std::string, ATarget*>::iterator it = this->myTgts.find(TgtName);
	if (it != this->myTgts.end())
	{
		return it->second->clone();
	}
	return NULL;
}