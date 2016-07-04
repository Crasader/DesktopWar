
#include "BehaviorLoader.h"
#include "Behavior.h"
#include "Precondition.h"
#include "Log.h"

AI_NS_BEGIN
BHTREE_NS_BEGIN


bool BehaviorLoader::Init(BehaviorCreatorMap bevArray[], PreconditionCreatorMap preArray[])
{
	int i = 0;
	while (bevArray[i].name != "")
	{
		RegisterBehavior(bevArray[i].name, bevArray[i].creator);
		i++;
	}

	i = 0;
	while (preArray[i].name != "")
	{
		RegisterPrecondition(preArray[i].name, preArray[i].creator);
		i++;
	}

	return true;
}

bool BehaviorLoader::Destroy()
{
	m_preconditionFactoryList.clear();
	m_behaviorFactoryList.clear();
	return true;
}

void BehaviorLoader::RegisterBehavior(std::string typeName, BehaviorCreator factory)
{
	auto iterFind = m_behaviorFactoryList.find(typeName);
	if (iterFind == m_behaviorFactoryList.end())
	{
		m_behaviorFactoryList.insert(std::make_pair(typeName, factory));
	}
	else
		Log::Warning("register behavior repeated : %s", typeName.c_str());
}

void BehaviorLoader::RegisterPrecondition(std::string typeName, PreconditionCreator factory)
{
	auto iterFind = m_preconditionFactoryList.find(typeName);
	if (iterFind == m_preconditionFactoryList.end())
	{
		m_preconditionFactoryList.insert(std::make_pair(typeName, factory));
	}
	else
		Log::Warning("register precondition repeated : %s", typeName.c_str());
}

Behavior* BehaviorLoader::LoadFromXml(std::string filePath)
{
	Behavior* root = nullptr;
	XMLDocument* doc = nullptr;
	do 
	{
		doc = new XMLDocument();
		if (!doc->LoadFile(filePath.c_str()))
			break;
		XMLElement* xmlRoot = doc->RootElement();
		root = ParseXml(xmlRoot->FirstChildElement());

	} while (0);

	delete doc;
	return root;
}

Behavior* BehaviorLoader::ParseXml(XMLElement* xmlNode)
{
	Behavior* root = nullptr;
	Precondition* precondition = nullptr;
	std::string behaviorTypeName = xmlNode->Value();
	
	auto iterBevFind = m_behaviorFactoryList.find(behaviorTypeName);
	if (iterBevFind != m_behaviorFactoryList.end())
	{
		root = iterBevFind->second(xmlNode);
	}
	else if (behaviorTypeName != "Precondition")
	{
		Log::Warning("unknown behavior type : %s", behaviorTypeName.c_str());
	}
	if (nullptr == root)
		return root;

	XMLElement* preconditionXml = xmlNode->FirstChildElement("Precondition");
	if (preconditionXml)
	{
		precondition = ParsePrecondition(preconditionXml);
		root->SetPrecondition(precondition);
	}

	for (XMLElement* node = xmlNode->FirstChildElement(); node; node = node->NextSiblingElement())
	{
		Behavior* child = ParseXml(node);
		if (child)
			root->AddChild(child);
	}

	return root;
}

Precondition* BehaviorLoader::ParsePrecondition(XMLElement* xmlNode)
{
	Precondition* precondition = nullptr;

	std::string preconditionTypeName = xmlNode->Attribute("type");
	auto iterPreFind = m_preconditionFactoryList.find(preconditionTypeName);
	if (iterPreFind != m_preconditionFactoryList.end())
	{
		precondition = iterPreFind->second(xmlNode);
	}
	else
	{
		Log::Warning("unknown precondition type %s", preconditionTypeName.c_str());
	}

	for (XMLElement* node = xmlNode->FirstChildElement(); node; node = node->NextSiblingElement())
	{
		std::string typeName1 = node->Attribute("type");
		auto iterPreFind = m_preconditionFactoryList.find(typeName1);
		if (iterPreFind != m_preconditionFactoryList.end())
		{
			precondition->AddChild(iterPreFind->second(node));
		}
		else
		{
			Log::Error("unknown precondition type %s", typeName1.c_str());
		}
	}

	return precondition;
}

BH_TREE_NS_END
AI_NS_END