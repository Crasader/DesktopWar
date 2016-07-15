
#include "SystemBulletDamageSingle.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"
#include "data/auto/Bullet_cfg.hpp"
#include "../../core/ECSWorld.h"
#include "../../core/SystemManager.h"
#include "../pawn/SystemPawnFight.h"
#include "skill/BuffManager.h"

#include "../../components/common/ComTeam.h"

using namespace Genius;
using namespace cfg;

void SystemBulletDamageSingle::Initialize()
{
	transMapper.init(*world);
	damageMapper.init(*world);
	agentMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_BulletTrigger);
}

void SystemBulletDamageSingle::ProcessEntity(Entity* pEntity)
{
	/*ComTransform* posCom = transMapper.get(pEntity);
	
	ComBulletDamageSingle* pAttackCom = attackMapper.get(pEntity);
	ComBulletAnimBase* pAnimCom = bulletAnimMapper.get(pEntity);
	ComBulletTemplate* pTemplateCom = bulletTemplateMapper.get(pEntity);

	// 没命中，但是到最大时间了，爆炸。
	pAttackCom->lifeTime += world->GetDeltaTime();
	if (pAttackCom->lifeTime > pTemplateCom->pBulletData->maxLifeTime)
	{
		pAnimCom->ShowBody(false);
		pAnimCom->StartExplode();
		pPosCom->vx = 0;
		pPosCom->vy = 0;
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
		EventManager::GetSingleton()->FireEvent(BulletHitEvent(pEntity));
		EventManager::GetSingleton()->FireEvent(StopMoveEvent(pEntity));

		// 这里也是不合适，因为不一定碰撞之后就会触发buff。
		ComBulletAgent* bulletAgent = agentMapper.get(pEntity);
		if (bulletAgent)
		{
			const Bullet_cfg* bulletInfo = bulletAgent->pBulletData;
			for (int i = 0; i < 3; ++i)
			{
				if (bulletInfo->buffs[i] != 0)
					BuffManager::GetSingleton()->AddBuff(pEntity->GetId(), pOtherEntity->GetId(), bulletInfo->buffs[i]);
			}
		}
	}
	/*
	
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
		pPosCom->vx = 0;
		pPosCom->vy = 0;
		pAttackCom->targetID = id2;

		ComBulletAgent* bulletAgent = agentMapper.get(pOwnerEntity);
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
		ComBulletAgent* bulletAgent = agentMapper.get(pOwnerEntity);
		const Bullet_cfg* bulletInfo = bulletAgent->pBulletData;
		for (int i = 0; i < 3; ++i)
		{
			if (bulletInfo->buffs[i] != 0)
				BuffManager::GetSingleton()->AddBuff(pOwnerEntity->GetId(), pAttackCom->targetID, bulletInfo->buffs[i]);
		}
	}
	
	return true;
}