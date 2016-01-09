// d:)
#include "EntitySystem.h"
#include "ECSWorld.h"
#include "Entity.h"

using namespace std;

namespace Genius
{

	EntitySystem::~EntitySystem()
	{
		world = nullptr;
	}

	int EntitySystem::GetEntityCount()
	{
		return m_activities.getCount();
	}

	void EntitySystem::Change(Entity* pEntity)
	{
		bool contains = (m_systemBit & pEntity->GetSystemBits()) == m_systemBit;
		bool interest = (m_typeFlags & pEntity->GetTypeBits()) == m_typeFlags;
		bool excluded = (m_excludedTypeFlags & pEntity->GetTypeBits()).any();

		if ((interest && !excluded) && !contains && m_typeFlags.any())
		{
			m_activities.add(pEntity);
			pEntity->AddSystemBit(m_systemBit);
			Added(pEntity);
		}
		else if ((!interest || excluded) && contains && m_typeFlags.any())
		{
			this->remove(pEntity);
		}
	}

	void EntitySystem::Process()
	{
		if (CheckProcessing())
		{
			Begin();
			ProcessEntities(m_activities);
			End();
		}
	};

	void EntitySystem::SetWorld(ECSWorld *world)
	{
		this->world = world;
	};

	void EntitySystem::remove(Entity* e)
	{
		m_activities.remove(e);
		e->RemoveSystemBit(m_systemBit);
		Removed(e);
	};

	void  EntitySystem::SetSystemBit(bitset<BITSIZE> bit)
	{
		m_systemBit = bit;
	}

	bool EntitySystem::IsMyEntity(Entity* e)
	{
		if (e == nullptr)
			return false;

		for (int i = 0; i < m_activities.getCount(); i++)
		{
			Entity* eneEntity = m_activities.get(i);
			if (e == eneEntity)
				return true;
		}

		return false;
	}

};
