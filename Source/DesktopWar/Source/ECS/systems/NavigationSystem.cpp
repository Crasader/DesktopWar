// d:)
#include "NavigationSystem.h"
#include "../../event/EventManager.h"
#include "../EntityEvents.h"
#include "../Entity.h"

using namespace Genius;

void NavigationSystem::Initialize()
{
	navigationMapper.init(*world);
	positionMapper.init(*world);
	velocityMapper.init(*world);
	
	// register event.
	EventManager::GetInstance().AddListener(this, Event_navigateTo);
	EventManager::GetInstance().AddListener(this, Event_navigateToEntity);
}

void NavigationSystem::ProcessEntity(Entity* e)
{
	PawnNavigationCom* navCom = navigationMapper.get(e);
	PositionCom* posCom = positionMapper.get(e);
	VelocityCom* velCom = velocityMapper.get(e);
	
	if (navCom->curPointIndex >= 0 && navCom->curPointIndex < navCom->pathPoints.size())
	{
		Point2D curPoint(posCom->x, posCom->y);
		Point2D destPoint = navCom->pathPoints[navCom->curPointIndex];
		Point2D distVec = destPoint - curPoint;
		Point2D velVec(velCom->x, velCom->y);
		float velLen = velVec.Length() * world->GetDeltaTime();
		float disLen = distVec.Length();
		if (disLen <= 0 || disLen < velLen)
		{
			navCom->curPointIndex++;
			if (navCom->curPointIndex < navCom->pathPoints.size())
			{
				Point2D newDestPoint = navCom->pathPoints[navCom->curPointIndex];
				EventManager::GetInstance().FireEvent(TransformEvent(Event_moveTo, e, newDestPoint.x, newDestPoint.y));
			}
			else
			{
				Point2D finalPoint = navCom->pathPoints[navCom->curPointIndex - 1];
				navCom->arrived = true;
				EventManager::GetInstance().FireEvent(TransformEvent(Event_setPosition, e, finalPoint.x, finalPoint.y));
				EventManager::GetInstance().FireEvent(TransformEvent(Event_pawnStopMove, e));
			}
		}
	}
}

bool NavigationSystem::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_navigateTo:
	{
		const TransformEvent & castedEvent = static_cast<const TransformEvent &>(event);
		PawnNavigationCom* navCom = navigationMapper.get(castedEvent.entity);
		if (navCom)
		{
			navCom->pathPoints.clear();
			// fake.
			//navCom->pathPoints.push_back(Point2D(233, 144));
			//navCom->pathPoints.push_back(Point2D(355, 256));

			navCom->pathPoints.push_back(Point2D(castedEvent.x, castedEvent.y));
			navCom->curPointIndex = 0;
			navCom->arrived = false;
			EventManager::GetInstance().FireEvent(TransformEvent(Event_moveTo, castedEvent.entity, 
				navCom->pathPoints[0].x, navCom->pathPoints[0].y));
		}
	}
		break;
	case Event_navigateToEntity:
	{
		const MoveToEntityEvent & castedEvent = static_cast<const MoveToEntityEvent &>(event);
		Entity* tarEntity = world->GetEntity(castedEvent.id);
		if (nullptr == tarEntity)
			break;
		PositionCom* posCom = tarEntity->GetComponent<PositionCom>();
		PawnNavigationCom* navCom = navigationMapper.get(castedEvent.entity);
		if (navCom && posCom)
		{
			navCom->pathPoints.clear();
			// fake.
			//navCom->pathPoints.push_back(Point2D(233, 144));
			//navCom->pathPoints.push_back(Point2D(355, 256));

			navCom->pathPoints.push_back(Point2D(posCom->x, posCom->y));
			navCom->curPointIndex = 0;
			navCom->arrived = false;
			EventManager::GetInstance().FireEvent(TransformEvent(Event_moveTo, castedEvent.entity,
				navCom->pathPoints[0].x, navCom->pathPoints[0].y));
		}
	}
		break;
	default:
		break;
	}
	return true;
}
