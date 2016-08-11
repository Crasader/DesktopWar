#ifndef _ENTITY_EVENT_H_
#define _ENTITY_EVENT_H_

#include "../event/Event.h"
#include <string>


namespace Genius
{
	class Entity;

	enum EventName
	{
		Event_unknown,

		// render
		Event_nodeCreated,
		Event_entityDestroy,

		// collider
		Event_EnterCollider,
		Event_ExitCollider,

		// bullet
		Event_BulletTrigger,
		Event_BulletHit,
		Event_ReachDestination,
		Event_StopMove,
	};

	class NodeCreatedEvent : public IEventData
	{
	public:
		NodeCreatedEvent(Entity* _entity, void* _node) :
			IEventData(Event_nodeCreated),
			entity(_entity),
			node(_node)
		{}

		Entity*				entity;
		void*				node;
	};

	class EntityDectroyEvent : public IEventData
	{
	public:
		EntityDectroyEvent(Entity* _entity) :
			IEventData(Event_entityDestroy),
			entity(_entity)
		{}

		Entity*				entity;
	};

	class TransformEvent : public IEventData
	{
	public:
		TransformEvent(EventType _type, Entity* _entity, float _x = 0, float _y = 0) :
			IEventData(_type),
			entity(_entity),
			x(_x),
			y(_y)
		{}

		Entity*	entity;
		float		x;
		float		y;
	};

	class EnterColliderEvent : public IEventData
	{
	public:
		EnterColliderEvent(Entity* _entity1, Entity* _entity2) :
			IEventData(Event_EnterCollider),
			entity1(_entity1),
			entity2(_entity2)
		{}

		Entity*	entity1;
		Entity*	entity2;
	};

	class ExitColliderEvent : public IEventData
	{
	public:
		ExitColliderEvent(Entity* _entity1, Entity* _entity2) :
			IEventData(Event_ExitCollider),
			entity1(_entity1),
			entity2(_entity2)
		{}

		Entity*	entity1;
		Entity*	entity2;
	};

	class BulletTriggerEvent : public IEventData
	{
	public:
		BulletTriggerEvent(Entity* _entity) :
			IEventData(Event_BulletTrigger),
			entity(_entity)
		{}

		Entity*	entity;
	};

	class BulletHitEvent : public IEventData
	{
	public:
		BulletHitEvent(Entity* _entity) :
			IEventData(Event_BulletHit),
			bulletEntity(_entity)
		{}

		Entity*	bulletEntity;
	};

	class ReachDestinationEvent : public IEventData
	{
	public:
		ReachDestinationEvent(Entity* _entity) :
			IEventData(Event_ReachDestination),
			entity(_entity)
		{}

		Entity*	entity;
	};

	class StopMoveEvent : public IEventData
	{
	public:
		StopMoveEvent(Entity* _entity) :
			IEventData(Event_StopMove),
			entity(_entity)
		{}

		Entity*	entity;
	};

};

#endif