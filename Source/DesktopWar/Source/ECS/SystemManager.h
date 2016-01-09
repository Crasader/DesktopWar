#pragma once

#include <typeinfo>
#include <unordered_map>
#include "ImmutableBag.h"
#include <iostream>
namespace Genius
{

	class EntitySystem;
	class Entity;
	class ECSWorld;

	class SystemManager
	{
	public:
		SystemManager(ECSWorld &world);
		~SystemManager();

		void Init();

		Bag<EntitySystem*> & GetSystems();
		EntitySystem* AddSystem(EntitySystem * stm);

		template<typename T>
		T* GetSystem()
		{
			return (T*)(m_systems[typeid(T).hash_code()]);
		}

	private:
		ECSWorld * world;
		std::unordered_map<size_t, EntitySystem*> m_systems;
		Bag<EntitySystem*> m_bagged;
	};

};
