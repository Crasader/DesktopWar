// d:)
#include "BulletDebugDrawSystem.h"
#include "../../event/EventManager.h"
#include "../EntityEvents.h"
#include "../../pawn/PawnDefines.h"
#include "../core/Entity.h"

#include "2Ddef.h"
#include "BulletDataMgr.h"

using namespace Genius;

void BulletDebugDrawSystem::Initialize()
{
	debugDrawMapper.init(*world);
	positionMapper.init(*world);
	templateMapper.init(*world);
	boxColliderMapper.init(*world);

	// register event.
	//EventManager::GetInstance().AddListener(this, Event_xxx);
}

void BulletDebugDrawSystem::ProcessEntity(Entity* e)
{
	BulletDebugDrawCom* debugCom = debugDrawMapper.get(e);
	PositionCom* posCom = positionMapper.get(e);
	BulletTemplateCom* tempCom = templateMapper.get(e);
	BoxColliderCom* boxColliderCom = boxColliderMapper.get(e);
	
	if (nullptr != debugCom && nullptr != posCom && nullptr != tempCom && nullptr != boxColliderCom)
	{
		do
		{
			// attack range
			Vec2 center(posCom->x, posCom->y);
			float radiusNear = tempCom->pBulletData->buffTargetRadius;
			debugCom->Clear();
			debugCom->pNodeHurtRange->drawCircle(center, radiusNear, 0, 12, true, Color4F::RED);
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

bool BulletDebugDrawSystem::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();
	/*switch (eType)
	{
	}*/
	return true;
}
