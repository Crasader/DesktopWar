// d:)
#include "BulletDamageSingleSystem.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"
#include "data/BulletDataMgr.h"
#include "../../core/ECSWorld.h"
#include "../../core/SystemManager.h"
#include "../pawn/PawnFightSystem.h"
#include "skill/BuffSystem.h"

#include "../../components/common/TeamCom.h"

using namespace Genius;

void BulletDamageSingleSystem::Initialize()
{
	positionMapper.init(*world);
	damageMapper.init(*world);
	bulletTemplateMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_BulletTrigger);
}

void BulletDamageSingleSystem::ProcessEntity(Entity* pEntity)
{
	/*PositionCom* posCom = positionMapper.get(pEntity);
	VelocityCom* pVelCom = velocityMapper.get(pEntity);
	BulletDamageSingleCom* pAttackCom = attackMapper.get(pEntity);
	BulletBaseAnimCom* pAnimCom = bulletAnimMapper.get(pEntity);
	BulletTemplateCom* pTemplateCom = bulletTemplateMapper.get(pEntity);

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

bool BulletDamageSingleSystem::HandleEvent(IEventData const &evnt)
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

void BulletDamageSingleSystem::collisionHandler(int id1, int id2)
{
	Entity* pEntity = ECSWorld::GetSingleton()->GetEntity(id1);
	if (!IsMyEntity(pEntity))
		return;

	Entity* pOtherEntity = ECSWorld::GetSingleton()->GetEntity(id2);
	if (nullptr == pOtherEntity)
		return;

	TeamCom* pMyTeamCom = pEntity->GetComponent<TeamCom>();
	TeamCom* pOtherTeamCom = pOtherEntity->GetComponent<TeamCom>();
	if (pMyTeamCom && pOtherTeamCom && pMyTeamCom->team != pOtherTeamCom->team)
	{
		EventManager::GetInstance().FireEvent(BulletHitEvent(pEntity));
		EventManager::GetInstance().FireEvent(StopMoveEvent(pEntity));

		// 这里也是不合适，因为不一定碰撞之后就会触发buff。
		BulletTemplateCom* bulletTempCom = bulletTemplateMapper.get(pEntity);
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
	VelocityCom* pVelCom = velocityMapper.get(pEntity);
	BezierMovementCom* pTrackCom = trackingMapper.get(pEntity);
	BulletDamageSingleCom* pAttackCom = attackMapper.get(pEntity);
	PawnFightCom* eneFightCom = pOtherEntity->getComponent<PawnFightCom>();
	if (pTrackCom && pAttackCom && eneFightCom && pAttackCom->team != eneFightCom->team)
	{
		// 命中
		pTrackCom->Stop();
		BulletBaseAnimCom* pAnimCom = bulletAnimMapper.get(pEntity);
		pAnimCom->ShowBody(false);
		pAnimCom->Destroy();
		pVelCom->x = 0;
		pVelCom->y = 0;
		pAttackCom->targetID = id2;

		BulletTemplateCom* bulletTempCom = bulletTemplateMapper.get(pEntity);
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

bool BulletDamageSingleSystem::TriggerBulletBuff(IEventData const &evt)
{
	const BulletTriggerEvent & castedEvent = static_cast<const BulletTriggerEvent &>(evt);
	Entity* pOwnerEntity = castedEvent.entity;
	if (!IsMyEntity(pOwnerEntity))
		return false;

	BulletDamageSingleCom* pAttackCom = damageMapper.get(pOwnerEntity);
	Entity* pOtherEntity = ECSWorld::GetSingleton()->GetEntity(pAttackCom->targetID);
	if (pOtherEntity)
	{
		BulletTemplateCom* bulletTempCom = bulletTemplateMapper.get(pOwnerEntity);
		const BulletData* bulletInfo = bulletTempCom->pBulletData;
		for (int i = 0; i < BulletData::BuffNum; ++i)
		{
			if (bulletInfo->buffs[i] != 0)
				BuffSystem::GetSingleton().AddBuff(pOwnerEntity->GetId(), pAttackCom->targetID, bulletInfo->buffs[i]);
		}
	}
	
	return true;
}