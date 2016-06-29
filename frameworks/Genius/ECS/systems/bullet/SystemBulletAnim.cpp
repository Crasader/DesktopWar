
#include "SystemBulletAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"

using namespace Genius;

void SystemBulletAnim::Initialize()
{
	positionMapper.init(*world);
	velocityMapper.init(*world);
	animMapper.init(*world);

	// register event.
	//EventManager::GetInstance().AddListener(this, Event_xxx);
}

void SystemBulletAnim::ProcessEntity(Entity* pEntity)
{
	ComPosition* pPosCom = positionMapper.get(pEntity);
	ComVelocity* pVelCom = velocityMapper.get(pEntity);
	ComBulletAnimBase* animCom = animMapper.get(pEntity);

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

bool SystemBulletAnim::HandleEvent(IEventData const &event)
{
	/*EventType eType = event.GetType();
	switch (eType)
	{
	}*/

	return true;
}
