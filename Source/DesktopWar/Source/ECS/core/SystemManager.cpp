// d:)
#include "SystemManager.h"
#include "ECSWorld.h"
#include "EntitySystem.h"
#include "SystemBitManager.h"

#include "../systems/MovementSystem.h"
#include "../systems/SimpleAnimSystem.h"
#include "../systems/BoxColliderSystem.h"
#include "../systems/BezierMovingSystem.h"
#include "../systems/DelayTrackMovingSystem.h"
#include "../systems/BevtreeSystem.h"
#include "../systems/PawnAnimSystem.h"
#include "../systems/PawnActionSystem.h"
#include "../systems/PawnDirectionSystem.h"
#include "../systems/navigationSystem.h"
#include "../systems/PawnFightSystem.h"
#include "../systems/PawnDebugDrawSystem.h"
#include "../systems/BulletAnimSystem.h"
#include "../systems/BulletDamageSingleSystem.h"
#include "../systems/BulletDamageScopeSystem.h"
#include "../systems/BulletDamageNoneSystem.h"
#include "../systems/BulletDebugDrawSystem.h"
#include "../systems/BulletArrowAnimSystem.h"
#include "../systems/BulletBombAnimSystem.h"
#include "../systems/BulletEggAnimSystem.h"
#include "../systems/BulletTargetSystem.h"

#include "../systems/HumanGameControlSystem.h"
#include "../systems/MonsterGameControlSystem.h"


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
		this->AddSystem(new MovementSystem());
		this->AddSystem(new SimpleAnimSystem());
		this->AddSystem(new BoxColliderSystem());
		this->AddSystem(new BezierMovingSystem());
		this->AddSystem(new DelayTrackMovingSystem());
		this->AddSystem(new PawnAnimSystem());
		this->AddSystem(new PawnActionSystem());
		this->AddSystem(new PawnDirectionSystem());
		this->AddSystem(new BevtreeSystem());
		this->AddSystem(new NavigationSystem());
		this->AddSystem(new PawnFightSystem());
		this->AddSystem(new PawnDebugDrawSystem());
		this->AddSystem(new BulletAnimSystem());
		this->AddSystem(new BulletDamageSingleSystem());
		this->AddSystem(new BulletDamageScopeSystem());
		this->AddSystem(new BulletDamageNoneSystem());
		this->AddSystem(new BulletDebugDrawSystem());
		this->AddSystem(new BulletArrowAnimSystem());
		this->AddSystem(new BulletBombAnimSystem());
		this->AddSystem(new BulletEggAnimSystem());
		this->AddSystem(new BulletTargetSystem());
		this->AddSystem(new HumanGameControlSystem());
		this->AddSystem(new MonsterGameControlSystem());

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
