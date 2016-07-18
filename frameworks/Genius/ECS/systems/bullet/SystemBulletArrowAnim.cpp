
#include "SystemBulletArrowAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"

using namespace Genius;

void SystemBulletArrowAnim::Initialize()
{
	transMapper.init(*world);
	
	animMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_BulletHit);
	EventManager::GetSingleton()->AddListener(this, Event_ReachDestination);
}

void SystemBulletArrowAnim::ProcessEntity(Entity* pEntity)
{
	/*ComTransform* pPosCom = transMapper.get(pEntity);
	
	ComBulletAnimArrow* animCom = animMapper.get(pEntity);

	//animCom->m_pAvatarRoot->setPosition(pPosCom->x, pPosCom->y);
	float rotation = 0;
	if (animCom->m_pBodyArmature)
		rotation = animCom->m_pBodyArmature->getRotation();

	if (pPosCom->vx == 0)
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

bool SystemBulletArrowAnim::HandleEvent(IEventData const &evnt)
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

void SystemBulletArrowAnim::OnBulletHit(IEventData const &evnt)
{
	const BulletHitEvent & castedEvent = static_cast<const BulletHitEvent &>(evnt);
	Entity* pOwnerEntity = castedEvent.bulletEntity;
	if (!IsMyEntity(pOwnerEntity))
		return;
	// 箭击中目标之后应该消失，并播放掉血动画.
	ComBulletAnimArrow* pAnimCom = animMapper.get(pOwnerEntity);
	pOwnerEntity->Remove();

	auto pPosCom = transMapper.get(pOwnerEntity);
	pPosCom->vx = 0;
	pPosCom->vy = 0;
}

void SystemBulletArrowAnim::OnReachDest(IEventData const &evnt)
{
	const ReachDestinationEvent & castedEvent = static_cast<const ReachDestinationEvent &>(evnt);
	Entity* pOwnerEntity = castedEvent.entity;
	if (!IsMyEntity(pOwnerEntity))
		return;

	// 箭到地面后，保持角度，播放插在地上的动画。
	ComBulletAnimArrow* pAnimCom = animMapper.get(pOwnerEntity);
	pAnimCom->StayStill();
}
