// d:)
#include "EntityProcessingSystem.h"

#ifdef _DEBUG
//#include <debug_new.h>
#endif

namespace Genius
{

	bool EntityProcessingSystem::CheckProcessing()
	{
		return true;
	}

	void EntityProcessingSystem::ProcessEntities(ImmutableBag<Entity*>& bag)
	{
		for (int i = 0; i < bag.getCount(); i++)
		{
			ProcessEntity(bag.get(i));
		}
	}

	bool EntityProcessingSystem::HandleEvent(IEventData const &event)
	{
		return true;
	}

};
