#pragma once

#include "ImmutableBag.h"
#include <unordered_map>
#include <string>

namespace Genius
{
	
	class Entity;
	
	class GroupManager
	{
	private:
		Bag<Entity*>			m_emptyBag;
		std::string					m_emptyString;
		Bag<std::string*>		m_groupByEntity;
		std::unordered_map<std::string, Bag<Entity*>*> m_entitiesByGroup;

	public:
		GroupManager();
		~GroupManager();

		void					Set(std::string group, Entity* e);
		void					Remove(Entity* e);
		std::string			GetGroupOf(Entity* e);
		bool					IsGrouped(Entity* e);
		bool					IsInGroup(std::string group, Entity* e);

		ImmutableBag<Entity*>* GetEntities(std::string group);
	};
};