#pragma once

#include "ImmutableBag.h"
#include "TagManager.h"
#include <map>

namespace Genius
{
	class Entity;
	class EntityManager;
	class SystemManager;
	class EntitySystem;

	class ECSWorld
	{
	public:
		static ECSWorld* GetSingleton();
		void Destroy();
		~ECSWorld();

		SystemManager*		GetSystemManager();
		EntityManager*		GetEntityManager();
		TagManager*			GetTagManager();

		EntitySystem* AddSystem(EntitySystem*);
		void Initialize();

		Entity* CreateEntity();
		Entity* GetEntity(int entityId);
		void DeleteEntity(Entity* e);
		void RefreshEntity(Entity* e);

		void LoopStart();
		void Process();

		float GetDeltaTime();
		void SetDeltaTime(float deltaTime);

		const std::map<EntitySystem*, int>& GetSysCostTime();

		// Tag
		void AddTag(Entity* entity, const std::string& tag);
		void RemoveTag(Entity* entity, const std::string& tag);
		entity_map& GetEntitiesByTag(const std::string& tag);

	private:
		ECSWorld();

	private:
		SystemManager*		m_sysMgr;
		EntityManager*		m_entityMgr;
		TagManager*			m_pTagMgr;
		Bag<Entity*>			m_refreshedEntities;
		Bag<Entity*>			m_deletedEntities;
		float							m_deltaTime;
		
		//
		std::map<EntitySystem*, int>		m_sysCostTime;
	};
};
