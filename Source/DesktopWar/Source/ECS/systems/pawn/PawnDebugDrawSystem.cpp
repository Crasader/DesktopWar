// d:)
#include "PawnDebugDrawSystem.h"
#include "../../../event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../../pawn/PawnDefines.h"
#include "../../core/Entity.h"

#include "2Ddef.h"
#include "RoleDataMgr.h"

using namespace Genius;

void PawnDebugDrawSystem::Initialize()
{
	debugDrawMapper.init(*world);
	positionMapper.init(*world);
	pawnTemplateMapper.init(*world);
	boxColliderMapper.init(*world);

	// register event.
	//EventManager::GetInstance().AddListener(this, Event_xxx);
}

void PawnDebugDrawSystem::ProcessEntity(Entity* e)
{
	PawnDebugDrawCom* debugCom = debugDrawMapper.get(e);
	PositionCom* posCom = positionMapper.get(e);
	PawnTemplateCom* tempCom = pawnTemplateMapper.get(e);
	BoxColliderCom* boxColliderCom = boxColliderMapper.get(e);
	
	if (nullptr != debugCom && nullptr != posCom && nullptr != tempCom && nullptr != boxColliderCom)
	{
		do
		{
			// attack range
			Vec2 center(posCom->x, posCom->y);
			float radiusNear = tempCom->pRoleData->fightRangeNear;
			float radiusFar = tempCom->pRoleData->fightRangeFar;
			debugCom->Clear();
			debugCom->pNodeNearRange->drawCircle(center, radiusNear, 0, 12, true, Color4F::RED);
			debugCom->pNodeFarRange->drawCircle(center, radiusFar, 0, 12, true, Color4F::RED);
		} while (false);

		do
		{
			// box collider
			Vec2 center(posCom->x + boxColliderCom->centerX, posCom->y + boxColliderCom->centerY);
			Vec2 origin(center.x - boxColliderCom->width*0.5f, center.y + boxColliderCom->height*0.5f);
			Vec2 destination(center.x + boxColliderCom->width*0.5f, center.y - boxColliderCom->height*0.5f);
			debugCom->pNodeBoxCollider->drawRect(origin, destination, Color4F::GREEN);
		} while (false);
	}
}

bool PawnDebugDrawSystem::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();
	/*switch (eType)
	{
	}*/
	return true;
}
