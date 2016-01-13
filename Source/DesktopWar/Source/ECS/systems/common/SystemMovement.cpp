// d:)
#include "SystemMovement.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/PawnDefines.h"
#include "../../core/Entity.h"

#include "../../components/pawn/ComPawnTemplate.h"

#include "2Ddef.h"
#include "RoleDataMgr.h"

using namespace Genius;

void SystemMovement::Initialize()
{
	velocityMapper.init(*world);
	positionMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_setPosition);
	EventManager::GetInstance().AddListener(this, Event_moveTo);
	EventManager::GetInstance().AddListener(this, Event_pawnStopMove);
}

void SystemMovement::ProcessEntity(Entity* e)
{
	positionMapper.get(e)->x += velocityMapper.get(e)->x * world->GetDeltaTime();
	positionMapper.get(e)->y += velocityMapper.get(e)->y * world->GetDeltaTime();
}

bool SystemMovement::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_setPosition:
	{
		const TransformEvent & actionEvent = static_cast<const TransformEvent &>(event);
		ComPosition* pos = positionMapper.get(actionEvent.entity);
		if (pos)
		{
			pos->x = actionEvent.x;
			pos->y = actionEvent.y;
		}
	}
		break;
	case Event_moveTo:
	{
		const TransformEvent & actionEvent = static_cast<const TransformEvent &>(event);
		ComPosition* pos = positionMapper.get(actionEvent.entity);
		ComVelocity* vel = velocityMapper.get(actionEvent.entity);
		if (pos && vel)
		{
			//printf("mov to %f, %f\n", actionEvent.x, actionEvent.y);
			float dx = actionEvent.x - pos->x;
			float dy = actionEvent.y - pos->y;
			Point2D delta(dx, dy);
			delta.Normalize();
			
			float speed = 20;
			ComPawnTemplate* pawnTemp = actionEvent.entity->GetComponent<ComPawnTemplate>();
			if (pawnTemp)
			{
				speed = pawnTemp->pRoleData->moveSpeed;
			}
			vel->x = delta.x * speed;
			vel->y = delta.y * speed;

			EventManager::GetInstance().FireEvent(ActionEvent(actionEvent.entity, Action_Move));
			EventManager::GetInstance().FireEvent(VelocityChangedEvent(actionEvent.entity, vel->x, vel->y));
		}
	}
		break;
	case Event_pawnStopMove:
	{
		const TransformEvent & actionEvent = static_cast<const TransformEvent &>(event);
		ComVelocity* vel = velocityMapper.get(actionEvent.entity);
		if (vel)
		{
			vel->x = 0;
			vel->y = 0;
			EventManager::GetInstance().FireEvent(ActionEvent(actionEvent.entity, Action_Idle));
		}
	}
		break;
	}

	return true;
}
