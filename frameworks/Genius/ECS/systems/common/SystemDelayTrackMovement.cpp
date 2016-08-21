
#include "SystemDelayTrackMovement.h"
#include "../../../event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "entity/EntityUtility.h"
#include "2Ddef.h"

using namespace Genius;

void SystemDelayTrackMovement::Initialize()
{
	transMapper.init(*world);
	
	trackMapper.init(*world);

	// register event.
	//EventManager::GetSingleton()->AddListener(this, Event_xxx);
}

void SystemDelayTrackMovement::ProcessEntity(Entity* pEntity)
{
	ComTransform* tran = transMapper.get(pEntity);
	ComDelayTrackMovement* pTrackCom = trackMapper.get(pEntity);

	pTrackCom->lifeTime += world->GetDeltaTime();

	switch (pTrackCom->currentState)
	{
	case ComDelayTrackMovement::Wait:
		_doWait(pEntity);
		break;
	case ComDelayTrackMovement::FindTarget:
		_doFindTarget(pEntity);
		break;
	case ComDelayTrackMovement::AdjustDirection:
		_doAdjustDirection(pEntity);
		break;
	case ComDelayTrackMovement::SpeedUp:
		_doSpeedUp(pEntity);
		break;
	case ComDelayTrackMovement::Explode:
		_doExplode(pEntity);
		break;
	}
	
	// time out, then explode
	if (pTrackCom->currentState != ComDelayTrackMovement::Explode && pTrackCom->lifeTime > 10)
	{
		pTrackCom->currentState = ComDelayTrackMovement::Explode;
		EventManager::GetSingleton()->FireEvent(ReachDestinationEvent(pEntity));
	}
	
}

void SystemDelayTrackMovement::_doWait(Entity* pEntity)
{
	ComTransform* tran = transMapper.get(pEntity);
	ComDelayTrackMovement* pTrackCom = trackMapper.get(pEntity);
	pTrackCom->delayTime -= world->GetDeltaTime();

	if (abs(tran->vx) > 10 || tran->vy <= 0)
	{
		// keep moving up
		Point2D currentVel(tran->vx, tran->vy);
		float length = currentVel.Length();
		Point2D desiredVel(0, length);
		Point2D adjustedVel = currentVel + (desiredVel - currentVel)*0.03f;
		adjustedVel.Normalize();
		adjustedVel = adjustedVel*length;
		tran->vx = adjustedVel.x;
		tran->vy = adjustedVel.y;
	}
	else if (pTrackCom->delayTime < 0)
	{
		pTrackCom->currentState = ComDelayTrackMovement::FindTarget;
	}
}

void SystemDelayTrackMovement::_doFindTarget(Entity* pEntity)
{
	ComDelayTrackMovement* pTrackCom = trackMapper.get(pEntity);

	pTrackCom->targetEntityID = EntityUtility::FindRandTargetByTag(GameDefine::Tag_Soldier);
	if (pTrackCom->targetEntityID == Entity::InvalidID)
	{
		pTrackCom->currentState = ComDelayTrackMovement::Wait;
	}
	else
	{
		ComTransform* tran = transMapper.get(pEntity);
		Entity* pTarEntity = world->GetEntity(pTrackCom->targetEntityID);
		auto tarTran = pTarEntity->GetComponent<ComTransform>();
		pTrackCom->shouldTurnLeft = tarTran->x > tran->x;
		pTrackCom->currentState = ComDelayTrackMovement::AdjustDirection;
	}
}

void SystemDelayTrackMovement::_doAdjustDirection(Entity* pEntity)
{
	ComTransform* tran = transMapper.get(pEntity);
	ComDelayTrackMovement* pTrackCom = trackMapper.get(pEntity);

	Entity* pTarEntity = world->GetEntity(pTrackCom->targetEntityID);
	if (nullptr != pTarEntity)
	{
		auto tarTran = pTarEntity->GetComponent<ComTransform>();

		Point2D currentVel(tran->vx, tran->vy);
		float length = currentVel.Length();
		Point2D forceVec;
		if (pTrackCom->shouldTurnLeft)
			forceVec = Point2D(-tran->vy, tran->vx);
		else
			forceVec = Point2D(tran->vy, -tran->vx);

		Point2D desiredVel(tarTran->x - tran->x, tarTran->y - tran->y);
		desiredVel.Normalize();
		desiredVel = desiredVel*length;
		float angle = currentVel.AngleBetween(desiredVel);
		if (angle > 5)
		{
			Point2D adjustedVel = currentVel + forceVec*0.08f;
			adjustedVel.Normalize();
			adjustedVel = adjustedVel*length;
			tran->vx = adjustedVel.x;
			tran->vy = adjustedVel.y;
		}
		else
		{
			tran->vx = desiredVel.x;
			tran->vy = desiredVel.y;
			pTrackCom->targetCachePosX = tarTran->x;
			pTrackCom->targetCachePosY = tarTran->y;
			pTrackCom->currentState = ComDelayTrackMovement::SpeedUp;
		}
		
	}
	else
	{
		pTrackCom->currentState = ComDelayTrackMovement::Wait;
	}
}

void SystemDelayTrackMovement::_doSpeedUp(Entity* pEntity)
{
	ComTransform* tran = transMapper.get(pEntity);
	ComDelayTrackMovement* pTrackCom = trackMapper.get(pEntity);

	Entity* pTarEntity = world->GetEntity(pTrackCom->targetEntityID);
	if (nullptr != pTarEntity)
	{
		Point2D toTarVec(pTrackCom->targetCachePosX - tran->x, pTrackCom->targetCachePosY - tran->y);
		if (abs(toTarVec.x) < 20 && abs(toTarVec.y) < 20)
		{
			pTrackCom->currentState = ComDelayTrackMovement::Explode;
			EventManager::GetSingleton()->FireEvent(ReachDestinationEvent(pEntity));
		}
	}
	else
	{
		pTrackCom->currentState = ComDelayTrackMovement::Wait;
	}
}

void SystemDelayTrackMovement::_doExplode(Entity* pEntity)
{
	ComTransform* tran = transMapper.get(pEntity);
	tran->vx = 0;
	tran->vy = 0;
}

bool SystemDelayTrackMovement::HandleEvent(IEventData const &event)
{
	/*EventType eType = event.GetType();
	switch (eType)
	{
	}*/

	return true;
}
