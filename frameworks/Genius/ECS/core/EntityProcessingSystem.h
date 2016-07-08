#pragma once

#include "ImmutableBag.h"
#include "EntitySystem.h"
#include "event/Event.h"

namespace Genius
{

	class Entity;

	class EntityProcessingSystem : public EntitySystem, public IEventListener
	{
	protected:
		virtual void		ProcessEntity(Entity* e) = 0;
		void					ProcessEntities(ImmutableBag<Entity*> & bag);
		virtual bool		CheckProcessing();

	public:
		virtual bool		HandleEvent(IEventData const &event);
	};
};
