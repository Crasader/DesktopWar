
#include "TagManager.h"
#include "Entity.h"

namespace Genius
{

	TagManager::TagManager()
	{
	}

	entity_map& TagManager::GetEntitys(const std::string& tag)
	{
		return tagMap[tag];
	}

	bool TagManager::IsSubscribed(const std::string& tag, Entity* entity)
	{
		if (nullptr == entity)
			return false;
		auto it = tagMap.find(tag);
		if (it != tagMap.end())
		{
			if (it->second.find(entity->GetId()) != it->second.end())
				return true;
		}
		return false;
	}

	void TagManager::Remove(Entity* entity)
	{
		if (nullptr == entity)
			return;

		for (auto& it : tagMap)
		{
			auto& it2 = it.second.find(entity->GetId());
			if (it2 != it.second.end())
			{
				it.second.erase(it2);
				return;
			}
		}

	}

	void TagManager::UnSubscribe(const std::string& tag, Entity* entity)
	{
		if (nullptr == entity)
			return;
		auto it = tagMap.find(tag);
		if (it != tagMap.end())
		{
			auto it2 = it->second.find(entity->GetId());
			if (it2 != it->second.end())
				it->second.erase(it2);
		}
	}

	void TagManager::Subscribe(const std::string& tag, Entity* entity)
	{
		if (nullptr == entity)
			return;
		tagMap[tag][entity->GetId()] = entity;
	}

}
