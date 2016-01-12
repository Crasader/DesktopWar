// d:)
#include "GroupManager.h"
#include "Entity.h"

namespace Genius
{
	GroupManager::GroupManager() : m_emptyBag(1)
	{
		m_emptyString.clear();
	}

	ImmutableBag<Entity*> * GroupManager::GetEntities(std::string group)
	{
		Bag<Entity*> * bag = m_entitiesByGroup[group];
		if (bag == nullptr)
			return nullptr;
		return bag;
	}

	std::string GroupManager::GetGroupOf(Entity* pEntity)
	{
		if (pEntity->GetId() < m_groupByEntity.getCapacity())
		{
			std::string * group = m_groupByEntity.get(pEntity->GetId());
			if (group == nullptr)
				return m_emptyString;
			return  *group;
		}
		return m_emptyString;
	}

	bool GroupManager::IsGrouped(Entity* e)
	{
		return !GetGroupOf(e).empty();
	}

	bool GroupManager::IsInGroup(std::string group, Entity* e)
	{
		//TODO ignore case
		//return strncasecmp(group, getGroupOf(e)) == 0;
		return group.compare(GetGroupOf(e)) == 0;
	}

	void GroupManager::Remove(Entity* pEntity)
	{
		if (nullptr == pEntity)
			return;

		if (pEntity->GetId() < m_groupByEntity.getCapacity())
		{
			std::string * groupId = m_groupByEntity.get(pEntity->GetId());
			if (groupId != nullptr){
				m_groupByEntity.set(pEntity->GetId(), nullptr);

				Bag<Entity*> * entities = m_entitiesByGroup[*groupId];
				if (entities != nullptr)
				{
					entities->remove(pEntity);
				}
				entities = nullptr;
				delete groupId;
				groupId = nullptr;
			}
			groupId = nullptr;
		}
	}

	void GroupManager::Set(std::string group, Entity* e)
	{
		Remove(e);

		Bag<Entity*> * entities = m_entitiesByGroup[group];
		if (entities == nullptr)
		{
			entities = new Bag<Entity*>(32);
			m_entitiesByGroup[group] = entities;
		}
		entities->add(e);
		entities = nullptr;
		m_groupByEntity.set(e->GetId(), new std::string(group));

	}

	GroupManager::~GroupManager()
	{

		m_groupByEntity.deleteData();

		//groupByEntity.clear();

		std::unordered_map<std::string, Bag<Entity*>*>::iterator it;

		for (it = m_entitiesByGroup.begin(); it != m_entitiesByGroup.end(); it++)
		{
			delete it->second;
		}

		m_entitiesByGroup.clear();
	}

};
