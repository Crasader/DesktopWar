// d:)
#include "BulletArrowAnimSystem.h"
#include "../../event/EventManager.h"
#include "../EntityEvents.h"
#include "../Entity.h"
#include "2Ddef.h"

using namespace Genius;

void BulletArrowAnimSystem::Initialize()
{
	positionMapper.init(*world);
	velocityMapper.init(*world);
	animMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_BulletHit);
	EventManager::GetInstance().AddListener(this, Event_ReachDestination);
}

void BulletArrowAnimSystem::ProcessEntity(Entity* pEntity)
{
	PositionCom* pPosCom = positionMapper.get(pEntity);
	VelocityCom* pVelCom = velocityMapper.get(pEntity);
	BulletArrowAnimCom* animCom = animMapper.get(pEntity);

	animCom->m_pAvatarRoot->setPosition(pPosCom->x, pPosCom->y);
	float rotation = 0;
	if (animCom->m_pBodyArmature)
		rotation = animCom->m_pBodyArmature->getRotation();

	if (pVelCom->x == 0)
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
}

bool BulletArrowAnimSystem::HandleEvent(IEventData const &evnt)
{
	EventType eType = evnt.GetType();
	switch (eType)
	{
	case Event_BulletHit:
		OnBulletHit(evnt);
		break;
	case Event_ReachDestination:
		OnReachDest(evnt);
		break;
	}

	return true;
}

void BulletArrowAnimSystem::OnBulletHit(IEventData const &evnt)
{
	const BulletHitEvent & castedEvent = static_cast<const BulletHitEvent &>(evnt);
	Entity* pOwnerEntity = castedEvent.bulletEntity;
	if (!IsMyEntity(pOwnerEntity))
		return;
	// 箭击中目标之后应该消失，并播放掉血动画.
	BulletArrowAnimCom* pAnimCom = animMapper.get(pOwnerEntity);
	pOwnerEntity->Remove();

	VelocityCom* pVelCom = velocityMapper.get(pOwnerEntity);
	pVelCom->x = 0;
	pVelCom->y = 0;
}

void BulletArrowAnimSystem::OnReachDest(IEventData const &evnt)
{
	const ReachDestinationEvent & castedEvent = static_cast<const ReachDestinationEvent &>(evnt);
	Entity* pOwnerEntity = castedEvent.entity;
	if (!IsMyEntity(pOwnerEntity))
		return;

	// 箭到地面后，保持角度，播放插在地上的动画。
	BulletArrowAnimCom* pAnimCom = animMapper.get(pOwnerEntity);
	pAnimCom->StayStill();
}
