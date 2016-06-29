
#include "SystemBulletBombAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"

using namespace Genius;

void SystemBulletBombAnim::Initialize()
{
	positionMapper.init(*world);
	velocityMapper.init(*world);
	animMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_BulletHit);
	EventManager::GetInstance().AddListener(this, Event_BulletLifeOver);
	EventManager::GetInstance().AddListener(this, Event_ReachDestination);
}

void SystemBulletBombAnim::ProcessEntity(Entity* pEntity)
{
	ComPosition* pPosCom = positionMapper.get(pEntity);
	ComVelocity* pVelCom = velocityMapper.get(pEntity);
	ComBulletAnimBomb* animCom = animMapper.get(pEntity);

	animCom->m_pAvatarRoot->setPosition(pPosCom->x, pPosCom->y);
	float rotation = 0;
	if (animCom->m_pBodyArmature)
		rotation = animCom->m_pBodyArmature->getRotation();

	if (pVelCom->x == 0)
	{
		if (pVelCom->y != 0)
			rotation = -90;
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

bool SystemBulletBombAnim::HandleEvent(IEventData const &evnt)
{
	EventType eType = evnt.GetType();
	switch (eType)
	{
	case Event_BulletHit:
		OnBulletHit(evnt);
		break;
	case Event_BulletLifeOver:
		break;
	case Event_ReachDestination:
		OnReachDest(evnt);
		break;
	}

	return true;
}

void SystemBulletBombAnim::OnBulletHit(IEventData const &evnt)
{
	const BulletHitEvent & castedEvent = static_cast<const BulletHitEvent &>(evnt);
	Entity* pOwnerEntity = castedEvent.bulletEntity;
	if (!IsMyEntity(pOwnerEntity))
		return;

	ComBulletAnimBomb* pAnimCom = animMapper.get(pOwnerEntity);
	pAnimCom->StartExplode();

	ComVelocity* pVelCom = velocityMapper.get(pOwnerEntity);
	pVelCom->x = 0;
	pVelCom->y = 0;
}

void SystemBulletBombAnim::OnReachDest(IEventData const &evnt)
{
	const ReachDestinationEvent & castedEvent = static_cast<const ReachDestinationEvent &>(evnt);
	Entity* pOwnerEntity = castedEvent.entity;
	if (!IsMyEntity(pOwnerEntity))
		return;

	ComBulletAnimBomb* pAnimCom = animMapper.get(pOwnerEntity);
	pAnimCom->StartExplode();
}
