// d:)
#include "TagManager.h"
//#include "World.h"
#include "Entity.h"

namespace Genius
{

	TagManager::TagManager()
	{
		//this->world = &world;
	}

	Entity& TagManager::GetEntity(const std::string tag)
	{
		return *tagByEntity[tag];
	}

	bool TagManager::IsSubscribed(const std::string tag)
	{
		return (tagByEntity[tag] != nullptr);
	}

	void TagManager::Remove(Entity* pEntity)
	{
		if (nullptr == pEntity)
			return;

		//TODO find cleaner way to remove by value
		for (auto& it : tagByEntity)
		{
			if (it.second == pEntity)
			{
				tagByEntity.erase(it.first);
				return;
			}
		}

	}

	void TagManager::UnSubscribe(const std::string tag)
	{
		//tagByEntity[tag] = nullptr;
		tagByEntity.erase(tag);
	}

	void TagManager::Subscribe(std::string tag, Entity* e)
	{
		Remove(e);
		tagByEntity[tag] = e;
	}

}
