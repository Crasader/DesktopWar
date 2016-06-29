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
		//Event_startAction,
		//Event_updateAction,
		Event_turnBack,

		// transform
		Event_setPosition,
		Event_navigateTo,
		Event_navigateToEntity,
		Event_moveTo,
		Event_pawnStopMove,
		Event_velocityChanged,
		Event_turnTo,

		// fight
		Event_attackNear,
		Event_attackNear2,
		Event_attackFar,
		Event_skill1,
		Event_skill2,
		Event_skill3,
		Event_Hurt,

		// animation
		Event_animMovement,

		// bullet
		Event_BulletTrigger,
		Event_BulletHit,
		Event_BulletLifeOver,
		Event_ReachDestination,
		Event_StopMove,
	};

	/*class ActionEvent : public IEventData
	{
	public:
		ActionEvent(Entity* _entity, ActionType _action) :
			IEventData(Event_startAction),
			entity(_entity),
			action(_action)
		{}

		Entity*				entity;
		ActionType		action;
	};*/

	/*class UpdateActionEvent : public IEventData
	{
	public:
		UpdateActionEvent(Entity* _entity) :
			IEventData(Event_updateAction),
			entity(_entity)
		{}

		Entity*				entity;
	};*/

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

	class AttackNearEvent : public IEventData
	{
	public:
		AttackNearEvent(Entity* _entity) :
			IEventData(Event_attackNear),
			entity(_entity)
		{}

		Entity*	entity;
	};

	class AttackNear2Event : public IEventData
	{
	public:
		AttackNear2Event(Entity* _entity) :
			IEventData(Event_attackNear2),
			entity(_entity)
		{}

		Entity*	entity;
	};

	class AttackFarEvent : public IEventData
	{
	public:
		AttackFarEvent(Entity* _entity) :
			IEventData(Event_attackFar),
			entity(_entity)
		{}

		Entity*	entity;
	};

	class UseSkillEvent : public IEventData
	{
	public:
		enum
		{
			NormalSkill1,
			NormalSkill2,
			SpecialSkill1,
			SpecialSkill2,
			SpecialSkill3,
		};
	public:
		UseSkillEvent(Entity* _entity, int _type) :
			IEventData(Event_skill1),
			entity(_entity),
			skillType(_type)
		{}

		Entity*	entity;
		int		skillType;
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

	class AnimationMovementEvent : public IEventData
	{
	public:
		AnimationMovementEvent(const std::string& _name, int _moveType, int _entityID) :
			IEventData(Event_animMovement),
			animName(_name),
			moveType(_moveType),
			entityID(_entityID)
		{}

		int			moveType;
		std::string	animName;
		int			entityID;
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