
#pragma once

#include "common/Singleton.h"
#include <map>

namespace Genius
{

	class EntityWrapper;

	class WorldWrapper : public Singleton<WorldWrapper>
	{
	public:
		EntityWrapper* CreateEntity();
		

	private:
		std::map<int, EntityWrapper*> entityMap;

	};

}

