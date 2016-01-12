// d:)
#include "DelayTrackMovingSystem.h"
#include "../../event/EventManager.h"
#include "../EntityEvents.h"
#include "../../pawn/PawnDefines.h"
#include "../core/Entity.h"
#include "../components/PawnComponents.h"
#include "2Ddef.h"

using namespace Genius;

void DelayTrackMovingSystem::Initialize()
{
	positionMapper.init(*world);
	velocityMapper.init(*world);
	trackMapper.init(*world);

	// register event.
	//EventManager::GetInstance().AddListener(this, Event_xxx);
}

void DelayTrackMovingSystem::ProcessEntity(Entity* pEntity)
{
	PositionCom* pPosCom = positionMapper.get(pEntity);
	VelocityCom* pVelCom = velocityMapper.get(pEntity);
	DelayTrackMovingCom* pTrackCom = trackMapper.get(pEntity);

	if (!pTrackCom->isTracking)
	{
		pVelCom->x = 0;
		pVelCom->y = 0;
	}

	pTrackCom->lifeTime += world->GetDeltaTime();
	if (pTrackCom->isTracking && pTrackCom->lifeTime >= pTrackCom->delayTime)
	{
		Point2D toTarVec(0, 0);
		Entity* pTarEntity = world->GetEntity(pTrackCom->targetEntityID);
		if (nullptr != pTarEntity)
		{
			// 锁定了entity就飞向它
			PositionCom* pTarPosCom = pTarEntity->GetComponent<PositionCom>();
			toTarVec.x = pTarPosCom->x - pPosCom->x;
			toTarVec.y = pTarPosCom->y - pPosCom->y;
		}
		else
		{
			// Entity已经消失，飞向一开始记录的位置
			toTarVec.x = pTrackCom->targetCachePosX - pPosCom->x;
			toTarVec.y = pTrackCom->targetCachePosY - pPosCom->y;
			if (toTarVec.Length() < Point2D(pVelCom->x, pVelCom->y).Length())
			{
				EventManager::GetInstance().FireEvent(ReachDestinationEvent(pEntity));
				pTrackCom->isTracking = false;
			}
		}
		toTarVec.Normalize();
		Point2D curVelVec(pVelCom->x, pVelCom->y);
		float velLen = curVelVec.Length();
		curVelVec.Normalize();
		Point2D deltaVec(toTarVec.x - curVelVec.x, toTarVec.y - curVelVec.y);
		pVelCom->x += deltaVec.x;
		pVelCom->y += deltaVec.y;

		// 临时这样计算8
		pVelCom->x = toTarVec.x * velLen;
		pVelCom->y = toTarVec.y * velLen;
	}
}

bool DelayTrackMovingSystem::HandleEvent(IEventData const &event)
{
	/*EventType eType = event.GetType();
	switch (eType)
	{
	}*/

	return true;
}
