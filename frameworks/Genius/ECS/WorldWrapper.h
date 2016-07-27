
#pragma once

#include "common/Singleton.h"
#include <map>

namespace Genius
{

	class EntityWrapper;

	class WorldWrapper : public Singleton<WorldWrapper>
	{
	public:
		static WorldWrapper* GetWorld();
		EntityWrapper* CreateEntity();
		void DestroyEntity(EntityWrapper* ent);

	private:
		std::map<int, EntityWrapper*> entityMap;

	};

}

