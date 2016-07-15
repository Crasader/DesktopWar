
#include "SystemBulletAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"

using namespace Genius;

void SystemBulletAnim::Initialize()
{
	transMapper.init(*world);
	
	animMapper.init(*world);

	// register event.
	//EventManager::GetSingleton()->AddListener(this, Event_xxx);
}

void SystemBulletAnim::ProcessEntity(Entity* pEntity)
{
	ComTransform* pPosCom = transMapper.get(pEntity);
	ComBulletAnimBase* animCom = animMapper.get(pEntity);

	animCom->m_pAvatarRoot->setPosition(pPosCom->x, pPosCom->y);
	float rotation = 0;
	if (pPosCom->vx == 0)
	{
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
			rotation = 180 - 180 * atan(pPosCom->vy / pPosCom->x) / PI;
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
