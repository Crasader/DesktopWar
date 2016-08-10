
#include "SystemManager.h"
#include "ECSWorld.h"
#include "EntitySystem.h"
#include "SystemBitManager.h"
#include "../ecs.h"


namespace Genius
{

	SystemManager::SystemManager(ECSWorld& world)
	{
		this->world = &world;
	}

	Bag<EntitySystem*> & SystemManager::GetSystems()
	{
		return m_bagged;
	}

	void SystemManager::Init()
	{
		this->AddSystem(new SystemTransform());
		this->AddSystem(new SystemRender());
		this->AddSystem(new SystemDirection());
		this->AddSystem(new SystemBoxCollider());
		this->AddSystem(new SystemBezierMovement());
		this->AddSystem(new SystemDelayTrackMovement());

		this->AddSystem(new SystemBulletDamage());
		this->AddSystem(new SystemBulletArrowAnim());
		this->AddSystem(new SystemBulletBombAnim());
		this->AddSystem(new SystemBulletTarget());

		for (int i = 0; i < m_bagged.getCount(); i++)
		{
			m_bagged.get(i)->Initialize();
		}

	}

	EntitySystem* SystemManager::AddSystem(EntitySystem* stm)
	{

		bool bitFlag = false;
		int index = 0;

		//Check if system is known.
		for (int i = 0; i < m_bagged.getCount(); i++)
		{
			if (typeid(*stm) == typeid(*m_bagged.get(i)))
			{
				bitFlag = true;
				index = i;
			}
		}

		//Check if stm pointer doesn't point to an existing system
		//Else add system to manager
		if (m_bagged.get(index) != stm)
		{
			//If it doesn't point to an existing system
			//Check if the new system is already known
			if (bitFlag)
			{
				//Delete newly made system.
				delete stm;
				//Point to existing system in bag.
				stm = m_bagged.get(index);
			}
			else
			{
				stm->SetWorld(world);
				m_systems[typeid(*stm).hash_code()] = stm;
				m_bagged.add(stm);
				stm->SetSystemBit(SystemBitManager::GetBitFor(typeid(*stm)));
			}
		}

		return stm;
	}

	SystemManager::~SystemManager()
	{
		m_systems.clear();
		m_bagged.deleteData();
	}
};
