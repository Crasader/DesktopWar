// d:)
#include "BulletAnimSystem.h"
#include "../../event/EventManager.h"
#include "../EntityEvents.h"
#include "../core/Entity.h"
#include "2Ddef.h"

using namespace Genius;

void BulletAnimSystem::Initialize()
{
	positionMapper.init(*world);
	velocityMapper.init(*world);
	animMapper.init(*world);

	// register event.
	//EventManager::GetInstance().AddListener(this, Event_xxx);
}

void BulletAnimSystem::ProcessEntity(Entity* pEntity)
{
	PositionCom* pPosCom = positionMapper.get(pEntity);
	VelocityCom* pVelCom = velocityMapper.get(pEntity);
	BulletBaseAnimCom* animCom = animMapper.get(pEntity);

	animCom->m_pAvatarRoot->setPosition(pPosCom->x, pPosCom->y);
	float rotation = 0;
	if (pVelCom->x == 0)
	{
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
}

bool BulletAnimSystem::HandleEvent(IEventData const &event)
{
	/*EventType eType = event.GetType();
	switch (eType)
	{
	}*/

	return true;
}
