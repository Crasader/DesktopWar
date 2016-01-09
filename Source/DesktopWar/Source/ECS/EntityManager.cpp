// d:)
#include "EntityManager.h"
#include "EntitySystem.h"
#include "SystemManager.h"
#include "BitSize.h"
#include "ECSWorld.h"
#include "Component.h"
#include "Entity.h"

namespace Genius
{
	EntityManager::EntityManager(ECSWorld* world) : m_componentsByType(64)
	{
		this->world = world;

		m_nextAvailableId = 1001;
		m_count = 0;
		m_uniqueEntityId = 0;
		m_totalCreated = 0;
		m_totalRemoved = 0;
	};

	void EntityManager::AddComponent(Entity* pEntity, Component * pCom)
	{
		if (nullptr == pEntity || nullptr == pCom)
			return;

		ComponentType type = ComponentTypeManager::getTypeFor(typeid(*pCom));

		if (type.GetId() >= m_componentsByType.getCapacity())
		{
			//Resize
			m_componentsByType.set(type.GetId(), nullptr);
		}

		Bag<Component*> * components = m_componentsByType.get(type.GetId());

		if (components == nullptr)
		{
			components = new Bag<Component*>();
			m_componentsByType.set(type.GetId(), components);
		}

		components->set(pEntity->GetId(), pCom);
		pEntity->AddTypeBit(type.getBit());
		pCom->SetOwner(pEntity);

		components = nullptr;

	};

	Entity* EntityManager::Create()
	{

		Entity* e = this->m_removedAndAvailable.removeLast();

		if (e == nullptr)
		{
			e = new Entity(this->world, m_nextAvailableId++);
		}
		else
		{
			e->Reset();
		}

		e->SetUniqueId(m_uniqueEntityId++);
		m_activeEntities.set(e->GetId(), e);
		m_count++;
		m_totalCreated++;

		return e;
	};

	Entity* EntityManager::GetEntity(int entityId)
	{
		if (entityId == Entity::InvalidID)
			return nullptr;
		return m_activeEntities.get(entityId);
	};

	int EntityManager::GetEntityCount()
	{
		return m_count;
	};

	long EntityManager::GetTotalCreated()
	{
		return m_totalCreated;
	};

	long EntityManager::GetTotalRemoved()
	{
		return m_totalRemoved;
	};

	Component * EntityManager::GetComponent(Entity* pEntity, ComponentType & type)
	{
		if (nullptr == pEntity)
			return nullptr;

		Bag<Component*>* bag = m_componentsByType.get(type.GetId());

		if (bag != nullptr && pEntity->GetId() < bag->getCapacity())
			return bag->get(pEntity->GetId());

		return nullptr;
	};

	/**
	 * Retrieves all components for one entity.
	 */
	Bag<Component*>& EntityManager::GetComponents(Entity* pEntity)
	{
		m_entityComponents.clear();

		for (int i = 0; i < m_componentsByType.getCapacity(); i++)
		{
			Bag<Component*> * components = m_componentsByType.get(i);

			if (components != nullptr && pEntity->GetId() < components->getCapacity())
			{
				Component * c = components->get(pEntity->GetId());

				if (c != nullptr)
				{
					m_entityComponents.add(c);
				}
			}
		}

		return m_entityComponents;
	};

	bool EntityManager::IsActive(int entityId)
	{
		return m_activeEntities.get(entityId) != nullptr;
	};

	void EntityManager::Refresh(Entity* pEntity)
	{
		SystemManager * systemManager = world->GetSystemManager();
		Bag<EntitySystem*> & systems = systemManager->GetSystems();

		for (int i = 0; i < systems.getCount(); i++)
		{
			systems.get(i)->Change(pEntity);
		}

	};

	void EntityManager::Remove(Entity* pEntity)
	{
		if (nullptr == pEntity)
			return;

		m_activeEntities.set(pEntity->GetId(), nullptr);
		pEntity->SetTypeBits(0);
		Refresh(pEntity);
		RemoveComponentsOfEntity(pEntity);
		m_count--;
		m_totalRemoved++;
		m_removedAndAvailable.add(pEntity);
	};

	void EntityManager::RemoveComponent(Entity* pEntity, ComponentType & type)
	{
		if (nullptr == pEntity)
			return;

		Bag<Component* > * components = m_componentsByType.get(type.GetId());

		delete components->get(pEntity->GetId());
		components->set(pEntity->GetId(), nullptr);
		pEntity->RemoveTypeBit(type.getBit());
		components = nullptr;
	};

	void EntityManager::RemoveComponentsOfEntity(Entity* pEntity)
	{
		if (nullptr == pEntity)
			return;

		for (int i = 0; i < m_componentsByType.getCapacity(); i++)
		{
			Bag<Component*> * components = m_componentsByType.get(i);

			if (components != nullptr && pEntity->GetId() < components->getCapacity())
			{

				delete components->get(pEntity->GetId());
				components->set(pEntity->GetId(), nullptr);
			}

			components = nullptr;
		}

	};

	void EntityManager::RemoveAllEntities()
	{

		for (int i = 0; i < m_activeEntities.getCapacity(); i++)
		{
			if (m_activeEntities.get(i) != nullptr)
			{
				Remove(m_activeEntities.get(i));
			}
		}

	}

	EntityManager::~EntityManager()
	{
		//Removes every active entity and puts it in removeAndAvailable.
		//Also calls removeComponentsOfEntity. All systems will be updated and will remove each entity.
		this->RemoveAllEntities();
		// Destroy the data from memory; activeEntities should be empty by now.
		this->m_removedAndAvailable.deleteData();

		for (int i = 0; i < m_componentsByType.getCapacity(); i++)
		{
			if (m_componentsByType.get(i) == nullptr) continue;
			m_componentsByType.get(i)->clear();
		}
		m_componentsByType.deleteData();
		m_componentsByType.clear();

		//Does not own world. Only points to it.
		this->world = nullptr;
	}
};
