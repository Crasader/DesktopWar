
#include "SystemBulletEggAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"

using namespace Genius;

void SystemBulletEggAnim::Initialize()
{
	positionMapper.init(*world);
	
	animMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_BulletHit);
	EventManager::GetSingleton()->AddListener(this, Event_ReachDestination);
}

void SystemBulletEggAnim::ProcessEntity(Entity* pEntity)
{
	ComTransform* pPosCom = positionMapper.get(pEntity);
	
	ComBulletAnimEgg* animCom = animMapper.get(pEntity);

	animCom->m_pAvatarRoot->setPosition(pPosCom->x, pPosCom->y);
	float rotation = 0;
	if (animCom->m_pBodyArmature)
		rotation = animCom->m_pBodyArmature->getRotation();

	/*if (pPosCom->vx == 0)
	{
		if (pPosCom->vy != 0)
			rotation = 90;
	}
	else if (pPosCom->vx > 0)
	{
		if (pPosCom->vy * pPosCom->vx >= 0)
			rotation = -180 * atan(pPosCom->vy / pPosCom->vx) / PI;
		else if (pPosCom->vy * pPosCom->vx < 0)
			rotation = -180 * atan(pPosCom->vy / pPosCom->vx) / PI;
	}
	else
	{
		if (pPosCom->vy * pPosCom->vx >= 0)
			rotation = 180 - 180 * atan(pPosCom->vy / pPosCom->vx) / PI;
		else if (pPosCom->vy * pPosCom->vx < 0)
			rotation = 180 - 180 * atan(pPosCom->vy / pPosCom->vx) / PI;
	}
	
	if (animCom->m_pBodyArmature)
		animCom->m_pBodyArmature->setRotation(rotation);
		*/
}

bool SystemBulletEggAnim::HandleEvent(IEventData const &evnt)
{
// 	EventType eType = evnt.GetType();
// 	switch (eType)
// 	{
// 	}

	return true;
}
