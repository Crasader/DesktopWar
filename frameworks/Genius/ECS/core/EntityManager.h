#pragma  once

#include "ImmutableBag.h"
#include "IComponent.h"
#include "ComponentTypeManager.h"


namespace Genius
{

	class Entity;
	class ECSWorld;
	class EntityManager
	{
	public:
		EntityManager(ECSWorld* world);
		~EntityManager();
		Entity*			Create();
		void				Remove(Entity* e);
		void				RemoveComponentsOfEntity(Entity* e);
		bool				IsActive(int entityId);
		void				AddComponent(Entity* e, IComponent* com);
		void				Refresh(Entity* e);

		void				RemoveAllEntities();
		void				RemoveComponent(Entity* e, ComponentType& type);

		template<typename c>
		void RemoveComponent(Entity* e)
		{
			RemoveComponent(e, ComponentTypeManager::getTypeFor<c>());
		}

		IComponent * GetComponent(Entity* e, ComponentType& type);

		template<typename c>
		IComponent * GetComponent(Entity* e)
		{
			ComponentType type = ComponentTypeManager::getTypeFor<c>();
			return GetComponent(e, type);
		}

		Entity*			GetEntity(int entityId);
		int				GetEntityCount();
		long				GetTotalCreated();
		long				GetTotalRemoved();

		Bag<IComponent*>& GetComponents(Entity* e);


	private:
		ECSWorld*				world;
		Bag<Entity*>			m_activeEntities;
		Bag<Entity*>			m_removedAndAvailable;
		int							m_nextAvailableId;
		int							m_count;
		long							m_uniqueEntityId;
		long							m_totalCreated;
		long							m_totalRemoved;

		Bag<Bag<IComponent*>*>		m_componentsByType;
		Bag<IComponent*>					m_entityComponents;

	};
};
