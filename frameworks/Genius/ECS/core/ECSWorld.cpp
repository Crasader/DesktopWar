
#include "ECSWorld.h"
#include "Entity.h"
#include "SystemManager.h"
#include "EntitySystem.h"
#include "EntityManager.h"
#include "SystemBitManager.h"
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
		//TODO add more managers
		m_pSystemManager = new SystemManager(*this);
		m_pEntityManager = new EntityManager(this);
		m_pGroupManager = new GroupManager();
		m_pTagManager = new TagManager();
		m_deltaTime = 0;
	}

	void ECSWorld::Destroy()
	{
		//Entity manager should be deleted first.
		delete m_pEntityManager;
		delete m_pSystemManager;
		delete m_pGroupManager;
		delete m_pTagManager;
		ComponentTypeManager::deleteComponentTypes();
		SystemBitManager::RemoveBitSets();
	}

	void ECSWorld::DeleteEntity(Entity* e)
	{
		if (!m_deletedEntities.contains(e))
			m_deletedEntities.add(e);
	}

	float ECSWorld::GetDeltaTime()
	{
		return this->m_deltaTime;
	}

	SystemManager* ECSWorld::GetSystemManager()
	{
		return m_pSystemManager;
	}

	EntityManager* ECSWorld::GetEntityManager()
	{
		return m_pEntityManager;
	}

	GroupManager* ECSWorld::GetGroupManager()
	{
		return m_pGroupManager;
	}

	TagManager* ECSWorld::GetTagManager()
	{
		return m_pTagManager;
	}

	void ECSWorld::LoopStart()
	{
		if (!m_refreshedEntities.isEmpty())
		{
			for (int i = 0; i < m_refreshedEntities.getCount(); i++)
			{
				//TODO ADD  MANAGERs
				m_pEntityManager->Refresh(m_refreshedEntities.get(i));
			}
			m_refreshedEntities.clear();
		}

		if (!m_deletedEntities.isEmpty())
		{
			for (int i = 0; i < m_deletedEntities.getCount(); i++)
			{
				Entity* e = m_deletedEntities.get(i);
				m_pGroupManager->Remove(e);
				m_pTagManager->Remove(e);
				m_pEntityManager->Remove(e);
			}
			m_deletedEntities.clear();
		}

	}

	void ECSWorld::Process()
	{
		Bag<EntitySystem*>& systems = m_pSystemManager->GetSystems();
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
		return m_pSystemManager->AddSystem(stm);
	}

	void ECSWorld::Initialize()
	{
		m_pSystemManager->Init();
	}

	Entity* ECSWorld::CreateEntity()
	{
		return m_pEntityManager->Create();
	}

	Entity* ECSWorld::GetEntity(int entityId)
	{
		return m_pEntityManager->GetEntity(entityId);
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
};
