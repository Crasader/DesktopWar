// d:)
#include "BulletEggAnimSystem.h"
#include "../../event/EventManager.h"
#include "../EntityEvents.h"
#include "../Entity.h"
#include "2Ddef.h"

using namespace Genius;

void BulletEggAnimSystem::Initialize()
{
	positionMapper.init(*world);
	velocityMapper.init(*world);
	animMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_BulletHit);
	EventManager::GetInstance().AddListener(this, Event_ReachDestination);
}

void BulletEggAnimSystem::ProcessEntity(Entity* pEntity)
{
	PositionCom* pPosCom = positionMapper.get(pEntity);
	VelocityCom* pVelCom = velocityMapper.get(pEntity);
	BulletEggAnimCom* animCom = animMapper.get(pEntity);

	animCom->m_pAvatarRoot->setPosition(pPosCom->x, pPosCom->y);
	float rotation = 0;
	if (animCom->m_pBodyArmature)
		rotation = animCom->m_pBodyArmature->getRotation();

	/*if (pVelCom->x == 0)
	{
		if (pVelCom->y != 0)
			rotation = 90;
	}
	else if (pVelCom->x > 0)
	{
		if (pVelCom->y * pVelCom->x >= 0)
			rotation = -180 * atan(pVelCom->y / pVelCom->x) / PI;
		else if (pVelCom->y * pVelCom->x < 0)
			rotation = -180 * atan(pVelCom->y / pVelCom->x) / PI;
	}
	else
	{
		if (pVelCom->y * pVelCom->x >= 0)
			rotation = 180 - 180 * atan(pVelCom->y / pVelCom->x) / PI;
		else if (pVelCom->y * pVelCom->x < 0)
			rotation = 180 - 180 * atan(pVelCom->y / pVelCom->x) / PI;
	}
	
	if (animCom->m_pBodyArmature)
		animCom->m_pBodyArmature->setRotation(rotation);
		*/
}

bool BulletEggAnimSystem::HandleEvent(IEventData const &evnt)
{
// 	EventType eType = evnt.GetType();
// 	switch (eType)
// 	{
// 	}

	return true;
}
