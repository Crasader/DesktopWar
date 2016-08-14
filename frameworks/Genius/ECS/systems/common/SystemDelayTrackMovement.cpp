
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

	if (pTrackCom->currentState == ComDelayTrackMovement::Wait)
	{
		pTrackCom->delayTime -= world->GetDeltaTime();
		if (abs(tran->vx) > 10 || tran->vy <= 0)
		{
			// keep moving up
			Point2D currentVel(tran->vx, tran->vy);
			Point2D desiredVel(0, currentVel.Length());
			Point2D adjustedVel = currentVel + (desiredVel - currentVel)*0.03f;
			adjustedVel.Normalize();
			tran->vx = adjustedVel.x;
			tran->vy = adjustedVel.y;
		}
		else if (pTrackCom->delayTime < 0)
		{
			pTrackCom->currentState = ComDelayTrackMovement::FindTarget;
		}
	}
	else if (pTrackCom->currentState == ComDelayTrackMovement::FindTarget)
	{
		pTrackCom->targetEntityID = EntityUtility::FindRandTargetByTag(GameDefine::Tag_Soldier);
		if (pTrackCom->targetEntityID == Entity::InvalidID)
		{
			pTrackCom->currentState = ComDelayTrackMovement::Wait;
		}
		else
		{
			pTrackCom->currentState = ComDelayTrackMovement::AdjustDirection;
		}
	}
	else if (pTrackCom->currentState == ComDelayTrackMovement::AdjustDirection)
	{
		Entity* pTarEntity = world->GetEntity(pTrackCom->targetEntityID);
		if (nullptr != pTarEntity)
		{
			auto tarTran = pTarEntity->GetComponent<ComTransform>();
			// keep moving towards target
			Point2D currentVel(tran->vx, tran->vy);
			float length = currentVel.Length();
			Point2D desiredVel(tarTran->x - tran->x, tarTran->y - tran->y);
			desiredVel.Normalize();
			desiredVel = desiredVel*length;
			Point2D adjustedVel = currentVel + (desiredVel - currentVel)*0.05f;
			adjustedVel.Normalize();
			adjustedVel = adjustedVel*length;
			tran->vx = adjustedVel.x;
			tran->vy = adjustedVel.y;

			pTrackCom->targetCachePosX = tarTran->x;
			pTrackCom->targetCachePosY = tarTran->y;

			// collider
			Point2D toTarVec(pTrackCom->targetCachePosX - tran->x, pTrackCom->targetCachePosY - tran->y);
			if (abs(toTarVec.x)< 20 && abs(toTarVec.y)< 20)
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
	else if (pTrackCom->currentState == ComDelayTrackMovement::Explode)
	{
		tran->vx = 0;
		tran->vy = 0;
	}

	if (pTrackCom->currentState != ComDelayTrackMovement::Explode && pTrackCom->lifeTime > 10)
	{
		pTrackCom->currentState = ComDelayTrackMovement::Explode;
		EventManager::GetSingleton()->FireEvent(ReachDestinationEvent(pEntity));
	}
	
	

	/*if (pTrackCom->isTracking && pTrackCom->lifeTime >= pTrackCom->delayTime)
	{
		Point2D toTarVec(0, 0);
		Entity* pTarEntity = world->GetEntity(pTrackCom->targetEntityID);
		if (nullptr != pTarEntity)
		{
			// 锁定了entity就飞向它
			ComTransform* pTarPosCom = pTarEntity->GetComponent<ComTransform>();
			toTarVec.x = pTarPosCom->x - tran->x;
			toTarVec.y = pTarPosCom->y - tran->y;
		}
		else
		{
			int targetID = EntityUtility::FindRandTargetByTag(EntityUtility::GetEnemyTag());
			// Entity已经消失，飞向一开始记录的位置
			toTarVec.x = pTrackCom->targetCachePosX - tran->x;
			toTarVec.y = pTrackCom->targetCachePosY - tran->y;
			if (toTarVec.Length() < Point2D(tran->vx, tran->vy).Length())
			{
				EventManager::GetSingleton()->FireEvent(ReachDestinationEvent(pEntity));
				pTrackCom->isTracking = false;
			}
		}
		toTarVec.Normalize();
		Point2D curVelVec(tran->vx, tran->vy);
		float velLen = curVelVec.Length();
		curVelVec.Normalize();
		Point2D deltaVec(toTarVec.x - curVelVec.x, toTarVec.y - curVelVec.y);
		tran->vx += deltaVec.x;
		tran->vy += deltaVec.y;

		// 暂时这样计算8，理想的方式是圆滑的轨迹
		tran->vx = toTarVec.x * velLen;
		tran->vy = toTarVec.y * velLen;
	}*/
}

bool SystemDelayTrackMovement::HandleEvent(IEventData const &event)
{
	/*EventType eType = event.GetType();
	switch (eType)
	{
	}*/

	return true;
}
