#ifndef _ENTITY_EVENT_H_
#define _ENTITY_EVENT_H_

#include "../event/Event.h"
#include <string>
#include "../pawn/PawnDefines.h"

namespace Genius
{
	class Entity;

	enum EventName
	{
		Event_unknown,

		// render
		Event_nodeCreated,
		Event_entityDestroy,
		Event_turnBack,

		// transform
		Event_setPosition,
		Event_navigateTo,
		Event_navigateToEntity,
		Event_moveTo,
		Event_pawnStopMove,
		Event_velocityChanged,
		Event_turnTo,

		// collider
		Event_EnterCollider,
		Event_ExitCollider,

		// fight
		Event_attackNear,
		Event_attackNear2,
		Event_attackFar,
		Event_skill1,
		Event_skill2,
		Event_skill3,
		Event_Hurt,

		// bullet
		Event_BulletTrigger,
		Event_BulletHit,
		Event_BulletLifeOver,
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

	class TurnBackEvent : public IEventData
	{
	public:
		TurnBackEvent(Entity* _entity) :
			IEventData(Event_turnBack),
			entity(_entity)
		{}

		Entity*		entity;
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

	class MoveToEntityEvent : public IEventData
	{
	public:
		MoveToEntityEvent(Entity* _entity, int _id) :
			IEventData(Event_navigateToEntity),
			entity(_entity),
			id(_id)
		{}

		Entity*	entity;
		int			id;
	};

	class VelocityChangedEvent : public IEventData
	{
	public:
		VelocityChangedEvent(Entity* _entity, float _x, float _y) :
			IEventData(Event_velocityChanged),
			entity(_entity),
			x(_x),
			y(_y)
		{}

		Entity*	entity;
		float		x;
		float		y;
	};

	class TurnToEvent : public IEventData
	{
	public:
		TurnToEvent(Entity* _entity, float _x, float _y) :
			IEventData(Event_turnTo),
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

	class HurtEvent : public IEventData
	{
	public:
		HurtEvent(Entity* _entity, int num) :
			IEventData(Event_Hurt),
			entity(_entity),
			number(num)
		{}

		Entity*	entity;
		int			number;
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

	class BulletLifeOverEvent : public IEventData
	{
	public:
		BulletLifeOverEvent(Entity* _entity) :
			IEventData(Event_BulletLifeOver),
			entity(_entity)
		{}

		Entity*	entity;
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