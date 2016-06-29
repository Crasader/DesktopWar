#pragma once

#include "../AIBaseDef.h"
#include <string>
#include <map>
#include "tinyxml.h"

class TiXmlElement;

AI_NS_BEGIN
BHTREE_NS_BEGIN

class Behavior;
class Precondition;

typedef Behavior*(*BehaviorCreator)(TiXmlElement*);
typedef Precondition*(*PreconditionCreator)(TiXmlElement*);

struct BehaviorCreatorMap
{
	BehaviorCreator	creator;
	std::string				name;

	BehaviorCreatorMap(std::string _name, BehaviorCreator _creator) :
		creator(_creator),
		name(_name)
	{}
};

struct PreconditionCreatorMap
{
	PreconditionCreator	creator;
	std::string				name;
	PreconditionCreatorMap(std::string _name, PreconditionCreator _creator) :
		creator(_creator),
		name(_name)
	{}
};


class BehaviorLoader
{
public:
	static BehaviorLoader&	GetInstance();
	bool					Init(BehaviorCreatorMap bevArray[], PreconditionCreatorMap preArray[]);
	bool					Destroy();
	Behavior*			LoadFromXml(std::string filePath);

protected:
	Behavior*			ParseXml(TiXmlElement* xmlNode);
	Precondition*	ParsePrecondition(TiXmlElement* xmlNode);
	Precondition*	CreatePrecondition(std::string typeName);

private:
	void					RegisterBehavior(std::string typeName, BehaviorCreator factory);
	void					RegisterPrecondition(std::string typeName, PreconditionCreator factory);

private:
	std::map<std::string, BehaviorCreator>		m_behaviorFactoryList;
	std::map<std::string, PreconditionCreator>		m_preconditionFactoryList;
};

BH_TREE_NS_END
AI_NS_END