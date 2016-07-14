
#include "SystemDelayTrackMovement.h"
#include "../../../event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../../pawn/PawnDefines.h"
#include "../../core/Entity.h"

#include "2Ddef.h"

using namespace Genius;

void SystemDelayTrackMovement::Initialize()
{
	positionMapper.init(*world);
	
	trackMapper.init(*world);

	// register event.
	//EventManager::GetSingleton()->AddListener(this, Event_xxx);
}

void SystemDelayTrackMovement::ProcessEntity(Entity* pEntity)
{
	ComTransform* pPosCom = positionMapper.get(pEntity);
	
	ComDelayTrackMoving* pTrackCom = trackMapper.get(pEntity);

	if (!pTrackCom->isTracking)
	{
		pPosCom->vx = 0;
		pPosCom->vy = 0;
	}

	pTrackCom->lifeTime += world->GetDeltaTime();
	if (pTrackCom->isTracking && pTrackCom->lifeTime >= pTrackCom->delayTime)
	{
		Point2D toTarVec(0, 0);
		Entity* pTarEntity = world->GetEntity(pTrackCom->targetEntityID);
		if (nullptr != pTarEntity)
		{
			// 锁定了entity就飞向它
			ComTransform* pTarPosCom = pTarEntity->GetComponent<ComTransform>();
			toTarVec.x = pTarPosCom->x - pPosCom->x;
			toTarVec.y = pTarPosCom->y - pPosCom->y;
		}
		else
		{
			// Entity已经消失，飞向一开始记录的位置
			toTarVec.x = pTrackCom->targetCachePosX - pPosCom->x;
			toTarVec.y = pTrackCom->targetCachePosY - pPosCom->y;
			if (toTarVec.Length() < Point2D(pPosCom->vx, pPosCom->vy).Length())
			{
				EventManager::GetSingleton()->FireEvent(ReachDestinationEvent(pEntity));
				pTrackCom->isTracking = false;
			}
		}
		toTarVec.Normalize();
		Point2D curVelVec(pPosCom->vx, pPosCom->vy);
		float velLen = curVelVec.Length();
		curVelVec.Normalize();
		Point2D deltaVec(toTarVec.x - curVelVec.x, toTarVec.y - curVelVec.y);
		pPosCom->vx += deltaVec.x;
		pPosCom->vy += deltaVec.y;

		// 临时这样计算8
		pPosCom->vx = toTarVec.x * velLen;
		pPosCom->vy = toTarVec.y * velLen;
	}
}

bool SystemDelayTrackMovement::HandleEvent(IEventData const &event)
{
	/*EventType eType = event.GetType();
	switch (eType)
	{
	}*/

	return true;
}
