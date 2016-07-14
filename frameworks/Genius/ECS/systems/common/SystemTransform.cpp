
#include "SystemTransform.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/PawnDefines.h"
#include "../../core/Entity.h"
#include "../../components/pawn/ComPawnAgent.h"


#include "2Ddef.h"
#include "data/auto/Role_cfg.hpp"

using namespace Genius;

void SystemTransform::Initialize()
{
	transMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_setPosition);
	EventManager::GetSingleton()->AddListener(this, Event_moveTo);
	EventManager::GetSingleton()->AddListener(this, Event_pawnStopMove);
}

void SystemTransform::ProcessEntity(Entity* e)
{
	auto tranCom = transMapper.get(e);
	tranCom->x += tranCom->vx * world->GetDeltaTime();
	tranCom->y += tranCom->vy * world->GetDeltaTime();
}

bool SystemTransform::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_setPosition:
	{
		const TransformEvent & actionEvent = static_cast<const TransformEvent &>(event);
		auto pos = transMapper.get(actionEvent.entity);
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
		auto tran = transMapper.get(actionEvent.entity);
		if (tran)
		{
			//printf("mov to %f, %f\n", actionEvent.x, actionEvent.y);
			float dx = actionEvent.x - tran->x;
			float dy = actionEvent.y - tran->y;
			Point2D delta(dx, dy);
			delta.Normalize();
			
			float speed = 20;
			ComPawnAgent* pawnTemp = actionEvent.entity->GetComponent<ComPawnAgent>();
			if (pawnTemp)
			{
				speed = pawnTemp->m_roleCfg->moveSpeed;
			}
			tran->vx = delta.x * speed;
			tran->vy = delta.y * speed;

			EventManager::GetSingleton()->FireEvent(VelocityChangedEvent(actionEvent.entity, tran->vx, tran->vy));
		}
	}
		break;
	case Event_pawnStopMove:
	{
		const TransformEvent & actionEvent = static_cast<const TransformEvent &>(event);
		auto vel = transMapper.get(actionEvent.entity);
		if (vel)
		{
			vel->vx = 0;
			vel->vy = 0;
		}
	}
		break;
	}

	return true;
}
