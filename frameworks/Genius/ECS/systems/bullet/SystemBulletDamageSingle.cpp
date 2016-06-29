
#include "SystemBulletDamageSingle.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"
#include "data/BulletDataMgr.h"
#include "../../core/ECSWorld.h"
#include "../../core/SystemManager.h"
#include "../pawn/SystemPawnFight.h"
#include "skill/BuffSystem.h"

#include "../../components/common/ComTeam.h"

using namespace Genius;

void SystemBulletDamageSingle::Initialize()
{
	positionMapper.init(*world);
	damageMapper.init(*world);
	bulletTemplateMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_BulletTrigger);
}

void SystemBulletDamageSingle::ProcessEntity(Entity* pEntity)
{
	/*ComPosition* posCom = positionMapper.get(pEntity);
	ComVelocity* pVelCom = velocityMapper.get(pEntity);
	ComBulletDamageSingle* pAttackCom = attackMapper.get(pEntity);
	ComBulletAnimBase* pAnimCom = bulletAnimMapper.get(pEntity);
	ComBulletTemplate* pTemplateCom = bulletTemplateMapper.get(pEntity);

	// 没命中，但是到最大时间了，爆炸。
	pAttackCom->lifeTime += world->GetDeltaTime();
	if (pAttackCom->lifeTime > pTemplateCom->pBulletData->maxLifeTime)
	{
		pAnimCom->ShowBody(false);
		pAnimCom->StartExplode();
		pVelCom->x = 0;
		pVelCom->y = 0;
	}*/
}

bool SystemBulletDamageSingle::HandleEvent(IEventData const &evnt)
{
	EventType eType = evnt.GetType();
	switch (eType)
	{
	case Event_BulletTrigger:
		return TriggerBulletBuff(evnt);
		break;
	}

	return true;
}

void SystemBulletDamageSingle::collisionHandler(int id1, int id2)
{
	Entity* pEntity = ECSWorld::GetSingleton()->GetEntity(id1);
	if (!IsMyEntity(pEntity))
		return;

	Entity* pOtherEntity = ECSWorld::GetSingleton()->GetEntity(id2);
	if (nullptr == pOtherEntity)
		return;

	ComTeam* pMyComTeam = pEntity->GetComponent<ComTeam>();
	ComTeam* pOtherComTeam = pOtherEntity->GetComponent<ComTeam>();
	if (pMyComTeam && pOtherComTeam && pMyComTeam->team != pOtherComTeam->team)
	{
		EventManager::GetInstance().FireEvent(BulletHitEvent(pEntity));
		EventManager::GetInstance().FireEvent(StopMoveEvent(pEntity));

		// 这里也是不合适，因为不一定碰撞之后就会触发buff。
		ComBulletTemplate* bulletTempCom = bulletTemplateMapper.get(pEntity);
		if (bulletTempCom)
		{
			const BulletData* bulletInfo = bulletTempCom->pBulletData;
			for (int i = 0; i < BulletData::BuffNum; ++i)
			{
				if (bulletInfo->buffs[i] != 0)
					BuffSystem::GetSingleton().AddBuff(pEntity->GetId(), pOtherEntity->GetId(), bulletInfo->buffs[i]);
			}
		}
	}
	/*
	ComVelocity* pVelCom = velocityMapper.get(pEntity);
	ComBezierMovement* pTrackCom = trackingMapper.get(pEntity);
	ComBulletDamageSingle* pAttackCom = attackMapper.get(pEntity);
	ComPawnFight* eneFightCom = pOtherEntity->getComponent<ComPawnFight>();
	if (pTrackCom && pAttackCom && eneFightCom && pAttackCom->team != eneFightCom->team)
	{
		// 命中
		pTrackCom->Stop();
		ComBulletAnimBase* pAnimCom = bulletAnimMapper.get(pEntity);
		pAnimCom->ShowBody(false);
		pAnimCom->Destroy();
		pVelCom->x = 0;
		pVelCom->y = 0;
		pAttackCom->targetID = id2;

		ComBulletTemplate* bulletTempCom = bulletTemplateMapper.get(pEntity);
		if (nullptr != bulletTempCom)
		{
			const BulletData* bulletInfo = bulletTempCom->pBulletData;
			for (int i = 0; i < BulletData::BuffNum; ++i)
			{
				if (bulletInfo->buffs[i] != 0)
					BuffSystem::GetSingleton().AddBuff(pEntity->GetId(), pAttackCom->targetID, bulletInfo->buffs[i]);
			}
		}
	}*/
}

bool SystemBulletDamageSingle::TriggerBulletBuff(IEventData const &evt)
{
	const BulletTriggerEvent & castedEvent = static_cast<const BulletTriggerEvent &>(evt);
	Entity* pOwnerEntity = castedEvent.entity;
	if (!IsMyEntity(pOwnerEntity))
		return false;

	ComBulletDamageSingle* pAttackCom = damageMapper.get(pOwnerEntity);
	Entity* pOtherEntity = ECSWorld::GetSingleton()->GetEntity(pAttackCom->targetID);
	if (pOtherEntity)
	{
		ComBulletTemplate* bulletTempCom = bulletTemplateMapper.get(pOwnerEntity);
		const BulletData* bulletInfo = bulletTempCom->pBulletData;
		for (int i = 0; i < BulletData::BuffNum; ++i)
		{
			if (bulletInfo->buffs[i] != 0)
				BuffSystem::GetSingleton().AddBuff(pOwnerEntity->GetId(), pAttackCom->targetID, bulletInfo->buffs[i]);
		}
	}
	
	return true;
}