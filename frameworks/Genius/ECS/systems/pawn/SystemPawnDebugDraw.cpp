
#include "SystemPawnDebugDraw.h"
#include "../../../event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../../pawn/PawnDefines.h"
#include "../../core/Entity.h"

#include "2Ddef.h"
#include "data/auto/Role_cfg.hpp"

USING_NS_CC;
using namespace Genius;

void SystemPawnDebugDraw::Initialize()
{
	debugDrawMapper.init(*world);
	transMapper.init(*world);
	pawnAgentMapper.init(*world);
	boxColliderMapper.init(*world);

	// register event.
	//EventManager::GetSingleton()->AddListener(this, Event_xxx);
}

void SystemPawnDebugDraw::ProcessEntity(Entity* e)
{
	ComPawnDebugDraw* debugCom = debugDrawMapper.get(e);
	ComTransform* posCom = transMapper.get(e);
	ComPawnAgent* tempCom = pawnAgentMapper.get(e);
	ComBoxCollider* ComBoxCollider = boxColliderMapper.get(e);
	
	if (nullptr != debugCom && nullptr != posCom && nullptr != tempCom && nullptr != ComBoxCollider)
	{
		do
		{
			// attack range
			Vec2 center(posCom->x, posCom->y);
			float radiusNear = tempCom->m_roleCfg->fightRangeNear;
			float radiusFar = tempCom->m_roleCfg->fightRangeFar;
			debugCom->Clear();
			debugCom->pNodeNearRange->drawCircle(center, radiusNear, 0, 12, true, Color4F::RED);
			debugCom->pNodeFarRange->drawCircle(center, radiusFar, 0, 12, true, Color4F::RED);
		} while (false);

		do
		{
			// box collider
			Vec2 center(posCom->x + ComBoxCollider->centerX, posCom->y + ComBoxCollider->centerY);
			Vec2 origin(center.x - ComBoxCollider->width*0.5f, center.y + ComBoxCollider->height*0.5f);
			Vec2 destination(center.x + ComBoxCollider->width*0.5f, center.y - ComBoxCollider->height*0.5f);
			debugCom->pNodeBoxCollider->drawRect(origin, destination, Color4F::GREEN);
		} while (false);
	}
}

bool SystemPawnDebugDraw::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();
	/*switch (eType)
	{
	}*/
	return true;
}
