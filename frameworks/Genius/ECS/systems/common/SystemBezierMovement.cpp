
#include "SystemBezierMovement.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"

#include "../../core/Entity.h"

#include "2Ddef.h"

static inline float bezierat(float a, float b, float c, float d, float t)
{
	return (powf(1 - t, 3) * a +
		3 * t*(powf(1 - t, 2))*b +
		3 * powf(t, 2)*(1 - t)*c +
		powf(t, 3)*d);
}

using namespace Genius;

void SystemBezierMovement::Initialize()
{
	transMapper.init(*world);
	
	bezierMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_StopMove);
}

void SystemBezierMovement::ProcessEntity(Entity* pEntity)
{
	ComTransform* pPosCom = transMapper.get(pEntity);
	
	ComBezierMovement* pBezierCom = bezierMapper.get(pEntity);

	if (pBezierCom->IsDone())
		return;

	float dt = world->GetDeltaTime();
	pBezierCom->timePassed += dt;
	float elapse = pBezierCom->timePassed / pBezierCom->duration;
	if (elapse <= 1.0f)
	{
		float xa = 0;
		float xb = pBezierCom->controlPoint1X;
		float xc = pBezierCom->controlPoint2X;
		float xd = pBezierCom->deltaX;

		float ya = 0;
		float yb = pBezierCom->controlPoint1Y;
		float yc = pBezierCom->controlPoint2Y;
		float yd = pBezierCom->deltaY;

		float x = bezierat(xa, xb, xc, xd, elapse);
		float y = bezierat(ya, yb, yc, yd, elapse);

		float oldX = pPosCom->x;
		float oldY = pPosCom->y;
		pPosCom->x = pBezierCom->startX + x;
		pPosCom->y = pBezierCom->startY + y;

		pPosCom->vx = pPosCom->x - oldX;
		pPosCom->vy = pPosCom->y - oldY;
	}
	else
	{
		EventManager::GetSingleton()->FireEvent(ReachDestinationEvent(pEntity));
		pPosCom->vx = 0;
		pPosCom->vy = 0;
	}
}

bool SystemBezierMovement::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();
	switch (eType)
	{
	case Event_StopMove:
		OnStopMove(event);
		break;
	}

	return true;
}

void SystemBezierMovement::OnStopMove(IEventData const &evnt)
{
	const StopMoveEvent & castedEvent = static_cast<const StopMoveEvent &>(evnt);
	Entity* pOwnerEntity = castedEvent.entity;
	if (!IsMyEntity(pOwnerEntity))
		return;

	ComBezierMovement* pBezierCom = bezierMapper.get(pOwnerEntity);
	pBezierCom->Stop();
}
