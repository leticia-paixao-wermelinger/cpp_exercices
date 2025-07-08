#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget*>::iterator it = this->myTgts.begin(); it != this->myTgts.end(); ++it)
		delete it->second;
	this->myTgts.clear();
}

void	TargetGenerator::learnTargetType(ATarget *tgt)
{
	std::map<std::string, ATarget*>::iterator it = this->myTgts.find(tgt->getType());
	if (it == this->myTgts.end())
		this->myTgts[tgt->getType()] = tgt->clone();
}

void	TargetGenerator::forgetTargetType(std::string const & TargetType)
{
	std::map<std::string, ATarget*>::iterator it = this->myTgts.find(TargetType);
	if (it != this->myTgts.end())
	{
		delete it->second;
		this->myTgts.erase(TargetType);
	}
}

ATarget	*TargetGenerator::createTarget(std::string const & TargetType)
{
	std::map<std::string, ATarget*>::iterator it = this->myTgts.find(TargetType);
	if (it != this->myTgts.end())
		return it->second->clone();
	return NULL;
}