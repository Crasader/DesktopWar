
#include "ECSWorld.h"
#include "Entity.h"
#include "SystemManager.h"
#include "EntitySystem.h"
#include "EntityManager.h"
#include "SystemBitManager.h"
#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include <windows.h>

namespace Genius
{
	ECSWorld* ECSWorld::GetSingleton()
	{
		static ECSWorld world;
		return &world;
	}

	ECSWorld::ECSWorld()
	{
		m_sysMgr = new SystemManager(*this);
		m_entityMgr = new EntityManager(this);
		m_pTagMgr = new TagManager();
		m_deltaTime = 0;
	}

	void ECSWorld::Destroy()
	{
		//Entity manager should be deleted first.
		delete m_entityMgr;
		delete m_sysMgr;
		delete m_pTagMgr;
		ComponentTypeManager::deleteComponentTypes();
		SystemBitManager::RemoveBitSets();
	}

	float ECSWorld::GetDeltaTime()
	{
		return this->m_deltaTime;
	}

	SystemManager* ECSWorld::GetSystemManager()
	{
		return m_sysMgr;
	}

	EntityManager* ECSWorld::GetEntityManager()
	{
		return m_entityMgr;
	}

	TagManager* ECSWorld::GetTagManager()
	{
		return m_pTagMgr;
	}

	void ECSWorld::LoopStart()
	{
		if (!m_refreshedEntities.isEmpty())
		{
			for (int i = 0; i < m_refreshedEntities.getCount(); i++)
			{
				//TODO ADD  MANAGERs
				m_entityMgr->Refresh(m_refreshedEntities.get(i));
			}
			m_refreshedEntities.clear();
		}

		if (!m_deletedEntities.isEmpty())
		{
			for (int i = 0; i < m_deletedEntities.getCount(); i++)
			{
				Entity* e = m_deletedEntities.get(i);
				m_pTagMgr->Remove(e);
				m_entityMgr->Remove(e);
			}
			m_deletedEntities.clear();
		}

	}

	void ECSWorld::Process()
	{
		Bag<EntitySystem*>& systems = m_sysMgr->GetSystems();
		for (int i = 0; i < systems.getCount(); ++i)
		{
			int startTime = GetTickCount();
			systems.get(i)->Process();
			m_sysCostTime[systems.get(i)] = GetTickCount() - startTime;
		}
		return;
	}

	EntitySystem* ECSWorld::AddSystem(EntitySystem* stm)
	{
		return m_sysMgr->AddSystem(stm);
	}

	void ECSWorld::Initialize()
	{
		m_sysMgr->Init();
	}

	Entity* ECSWorld::CreateEntity()
	{
		return m_entityMgr->Create();
	}

	Entity* ECSWorld::GetEntity(int entityId)
	{
		return m_entityMgr->GetEntity(entityId);
	}

	void ECSWorld::DeleteEntity(Entity* e)
	{
		if (!m_deletedEntities.contains(e))
		{
			m_deletedEntities.add(e);
			m_pTagMgr->Remove(e);
			EventManager::GetSingleton()->FireEvent(EntityDectroyEvent(e));
		}
	}

	void ECSWorld::RefreshEntity(Entity* e)
	{
		m_refreshedEntities.add(e);
	}

	void ECSWorld::SetDeltaTime(float delta)
	{
		this->m_deltaTime = delta;
	}

	ECSWorld::~ECSWorld()
	{
		Destroy();
	}

	const std::map<EntitySystem*, int>& ECSWorld::GetSysCostTime()
	{
		return m_sysCostTime;
	}

	void ECSWorld::AddTag(Entity* entity, const std::string& tag)
	{
		m_pTagMgr->Subscribe(tag, entity);
	}

	void ECSWorld::RemoveTag(Entity* entity, const std::string& tag)
	{
		m_pTagMgr->UnSubscribe(tag, entity);
	}

	entity_map& ECSWorld::GetEntitiesByTag(const std::string& tag)
	{
		return m_pTagMgr->GetEntitys(tag);
	}

};
