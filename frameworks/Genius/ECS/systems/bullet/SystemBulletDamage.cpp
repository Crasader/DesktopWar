
#include "SystemBulletDamage.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"
#include "data/auto/Bullet_cfg.hpp"
#include "../../core/ECSWorld.h"
#include "../../core/SystemManager.h"
#include "../pawn/SystemPawnFight.h"
#include "skill/BuffManager.h"
#include "pawn/PawnBlackboard.h"
#include "entity/EntityUtility.h"
#include "entity/BulletDefines.h"


using namespace Genius;
using namespace cfg;

void SystemBulletDamage::Initialize()
{
	transMapper.init(*world);
	damageMapper.init(*world);
	agentMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_BulletTrigger);
	EventManager::GetSingleton()->AddListener(this, Event_EnterCollider);
}

void SystemBulletDamage::ProcessEntity(Entity* pEntity)
{
	/*ComTransform* posCom = transMapper.get(pEntity);
	
	ComBulletDamageSingle* pAttackCom = attackMapper.get(pEntity);
	ComBulletAnimBase* pAnimCom = bulletAnimMapper.get(pEntity);
	ComBulletTemplate* pTemplateCom = bulletTemplateMapper.get(pEntity);

	// û���У����ǵ����ʱ���ˣ���ը��
	pAttackCom->lifeTime += world->GetDeltaTime();
	if (pAttackCom->lifeTime > pTemplateCom->pBulletData->maxLifeTime)
	{
		pAnimCom->ShowBody(false);
		pAnimCom->StartExplode();
		pPosCom->vx = 0;
		pPosCom->vy = 0;
	}*/
}

bool SystemBulletDamage::HandleEvent(const IEventData &evnt)
{
	EventType eType = evnt.GetType();
	switch (eType)
	{
	case Event_BulletTrigger:
		return TriggerBulletBuff(evnt);
		break;
	case Event_EnterCollider:
		collisionHandler(evnt);
		break;
	}

	return true;
}

void SystemBulletDamage::collisionHandler(const IEventData& evt)
{
	const EnterColliderEvent & castedEvent = static_cast<const EnterColliderEvent &>(evt);

	Entity* pEntity = castedEvent.entity1;
	if (!IsMyEntity(pEntity))
		return;

	Entity* pOtherEntity = castedEvent.entity2;
	if (nullptr == pOtherEntity)
		return;

	auto myAgent = agentMapper.get(pEntity);
	bool isEnemy = EntityUtility::IsEnemy(pEntity, pOtherEntity);
	if (myAgent->pBulletData->moveType == BulletMoveType::BMT_Line)
	{
	}
	else if (myAgent->pBulletData->moveType == BulletMoveType::BMT_Line)
	{
		if (myAgent && isEnemy)
		{
			EventManager::GetSingleton()->FireEvent(BulletHitEvent(pEntity));
			EventManager::GetSingleton()->FireEvent(StopMoveEvent(pEntity));

			// ����Ҳ�ǲ����ʣ���Ϊ��һ����ײ֮��ͻᴥ��buff��
			ComPawnAgent* bulletAgent = agentMapper.get(pEntity);
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
	}
	else if (myAgent->pBulletData->moveType == BulletMoveType::BMT_Line)
	{
		if (myAgent->GetBlackboard()->targetType == Target_Entity)
		{
			if (myAgent->GetBlackboard()->targetID == pOtherEntity->GetId())
			{
				EventManager::GetSingleton()->FireEvent(BulletHitEvent(pEntity));
			}
		}
		else if (myAgent->GetBlackboard()->targetType == Target_Location)
		{
			;
		}
	}


	

	

}

bool SystemBulletDamage::TriggerBulletBuff(IEventData const &evt)
{
	const BulletTriggerEvent & castedEvent = static_cast<const BulletTriggerEvent &>(evt);
	Entity* pOwnerEntity = castedEvent.entity;
	if (!IsMyEntity(pOwnerEntity))
		return false;

	ComBulletDamage* pAttackCom = damageMapper.get(pOwnerEntity);
	auto agentCom = agentMapper.get(pOwnerEntity);
	if (agentCom->pBulletData->moveType == BulletMoveType::BMT_Line)
	{
		const Bullet_cfg* bulletInfo = agentCom->pBulletData;
		for (int i = 0; i < 3; ++i)
		{
			if (bulletInfo->buffs[i] != 0)
				BuffManager::GetSingleton()->AddBuff(pOwnerEntity->GetId(), Entity::InvalidID, bulletInfo->buffs[i]);
		}
	}
	else if (agentCom->pBulletData->moveType == BulletMoveType::BMT_Bezier)
	{
		Entity* pOtherEntity = ECSWorld::GetSingleton()->GetEntity(pAttackCom->targetID);
		if (pOtherEntity)
		{
			ComPawnAgent* bulletAgent = agentMapper.get(pOwnerEntity);
			const Bullet_cfg* bulletInfo = bulletAgent->pBulletData;
			for (int i = 0; i < 3; ++i)
			{
				if (bulletInfo->buffs[i] != 0)
					BuffManager::GetSingleton()->AddBuff(pOwnerEntity->GetId(), pAttackCom->targetID, bulletInfo->buffs[i]);
			}
		}
	}
	else if (agentCom->pBulletData->moveType == BulletMoveType::BMT_Tracking)
	{
		const Bullet_cfg* bulletInfo = agentCom->pBulletData;
		std::vector<Entity*> targets;
		FindTargetsInScope(pOwnerEntity, bulletInfo->buffTargetRadius, false, targets);
		for (auto iter = targets.begin(); iter != targets.end(); ++iter)
		{
			for (int i = 0; i < 3; ++i)
			{
				if (bulletInfo->buffs[i] != 0)
					BuffManager::GetSingleton()->AddBuff(pOwnerEntity->GetId(), (*iter)->GetId(), bulletInfo->buffs[i]);
			}
		}
	}
	
	
	return true;
}



void SystemBulletDamage::FindTargetsInScope(Entity* pEntity, int radius, bool sameTeam, std::vector<Entity*>& eneityIDList)
{
	ComTransform* myPosCom = transMapper.get(pEntity);
	//ComBulletDamageScope* myAttackCom = damageMapper.get(pEntity);
	auto myComAgent = agentMapper.get(pEntity);
	//int myTeam = myComAgent->GetBlackboard()->team;
	std::string targetTag;
	if (sameTeam)
	{
		bool isTagged = EntityUtility::IsTagged(GameDefine::Tag_Soldier, pEntity);
		targetTag = isTagged ? GameDefine::Tag_Soldier : GameDefine::Tag_Monster;
	}
	else
	{
		bool isTagged = EntityUtility::IsTagged(GameDefine::Tag_Soldier, pEntity);
		targetTag = isTagged ? GameDefine::Tag_Monster : GameDefine::Tag_Soldier;
	}

	entity_map& activities = world->GetEntitiesByTag(targetTag);
	for (auto& it : activities)
	{
		Entity* eneEntity = it.second;

		ComPawnAgent* enemyAgent = eneEntity->GetComponent<ComPawnAgent>();
		if (enemyAgent && enemyAgent->GetBlackboard()->GetAttr(AttrType::HP) <= 0)
			continue;

		ComTransform* enePosCom = eneEntity->GetComponent<ComTransform>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < radius)
		{
			eneityIDList.push_back(eneEntity);
		}
	}
}


