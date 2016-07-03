
#include "SystemBulletDebugDraw.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/PawnDefines.h"
#include "../../core/Entity.h"

#include "2Ddef.h"
#include "BulletDataMgr.h"

using namespace Genius;

void SystemBulletDebugDraw::Initialize()
{
	debugDrawMapper.init(*world);
	positionMapper.init(*world);
	templateMapper.init(*world);
	boxColliderMapper.init(*world);

	// register event.
	//EventManager::GetSingleton()->AddListener(this, Event_xxx);
}

void SystemBulletDebugDraw::ProcessEntity(Entity* e)
{
	ComBulletDebugDraw* debugCom = debugDrawMapper.get(e);
	ComPosition* posCom = positionMapper.get(e);
	ComBulletTemplate* tempCom = templateMapper.get(e);
	ComBoxCollider* ComBoxCollider = boxColliderMapper.get(e);
	
	if (nullptr != debugCom && nullptr != posCom && nullptr != tempCom && nullptr != ComBoxCollider)
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
			Vec2 center(posCom->x + ComBoxCollider->centerX, posCom->y + ComBoxCollider->centerY);
			Vec2 origin(center.x - ComBoxCollider->width*0.5f, center.y + ComBoxCollider->height*0.5f);
			Vec2 destination(center.x + ComBoxCollider->width*0.5f, center.y - ComBoxCollider->height*0.5f);
			debugCom->pNodeBoxCollider->drawRect(origin, destination, Color4F::GREEN);
		} while (false);
	}
}

bool SystemBulletDebugDraw::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();
	/*switch (eType)
	{
	}*/
	return true;
}
