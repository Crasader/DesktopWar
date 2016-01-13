// d:)
#include "SystemBulletDamageScope.h"
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
#include "../../components/common/ComTarget.h"

using namespace Genius;

void SystemBulletDamageScope::Initialize()
{
	positionMapper.init(*world);
	damageMapper.init(*world);
	bulletTemplateMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_BulletTrigger);
}

void SystemBulletDamageScope::ProcessEntity(Entity* pEntity)
{
}

bool SystemBulletDamageScope::HandleEvent(IEventData const &evnt)
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

void SystemBulletDamageScope::OnCollision(int id1, int id2)
{
	Entity* pEntity = ECSWorld::GetSingleton()->GetEntity(id1);
	if (!IsMyEntity(pEntity))
		return;

	Entity* pOtherEntity = ECSWorld::GetSingleton()->GetEntity(id2);
	if (nullptr == pOtherEntity)
		return;

	ComTarget* pMyComTarget = pEntity->GetComponent<ComTarget>();
	if (nullptr == pMyComTarget)
		return;

	if (pMyComTarget->targetType == Target_Entity)
	{
		if (pMyComTarget->targetID == id2)
		{
			EventManager::GetInstance().FireEvent(BulletHitEvent(pEntity));
		}
	}
	else if (pMyComTarget->targetType == Target_Location)
	{
		;
	}
}

bool SystemBulletDamageScope::TriggerBulletBuff(IEventData const &evt)
{
	const BulletTriggerEvent & castedEvent = static_cast<const BulletTriggerEvent &>(evt);
	Entity* ownerEntity = castedEvent.entity;
	if (!IsMyEntity(ownerEntity))
		return false;
	ComBulletDamageScope* attackCom = damageMapper.get(ownerEntity);
	ComBulletTemplate* bulletTempCom = bulletTemplateMapper.get(ownerEntity);
	if (nullptr == bulletTempCom || nullptr == attackCom)
		return false;

	const BulletData* bulletInfo = bulletTempCom->pBulletData;

	std::vector<Entity*> targets;
	FindTargetsInScope(ownerEntity, bulletInfo->buffTargetRadius, false, targets);
	for (auto iter = targets.begin(); iter != targets.end(); ++iter)
	{
		for (int i = 0; i < BulletData::BuffNum; ++i)
		{
			if (bulletInfo->buffs[i] != 0)
				BuffSystem::GetSingleton().AddBuff(ownerEntity->GetId(), (*iter)->GetId(), bulletInfo->buffs[i]);
		}
	}

	return true;
}

void SystemBulletDamageScope::FindTargetsInScope(Entity* pEntity, int radius, bool sameTeam, std::vector<Entity*>& eneityIDList)
{
	ComPosition* myPosCom = positionMapper.get(pEntity);
	ComBulletDamageScope* myAttackCom = damageMapper.get(pEntity);
	ComTeam* myComTeam = pEntity->GetComponent<ComTeam>();
	int myTeam = myComTeam->team;

	auto sysMgr = ECSWorld::GetSingleton()->GetSystemManager();
	SystemPawnFight* fightSys = sysMgr->GetSystem<SystemPawnFight>();
	Bag<Entity*>& activities = fightSys->GetActivities();
	for (int i = 0; i < activities.getCount(); i++)
	{
		Entity* eneEntity = activities.get(i);
		if (sameTeam && eneEntity->GetId() == pEntity->GetId())
			continue;

		ComPawnAttribute* enemyAttCom = eneEntity->GetComponent<ComPawnAttribute>();
		if (enemyAttCom && enemyAttCom->curLife <= 0)
			continue;

		ComTeam* enComTeam = eneEntity->GetComponent<ComTeam>();
		if (sameTeam && myTeam != enComTeam->team)
			continue;

		if ((!sameTeam)
			&& ((myTeam == Team_Human && enComTeam->team != Team_Monster) || (myTeam == Team_Monster && enComTeam->team != Team_Human))
			)
			continue;

		ComPosition* enePosCom = eneEntity->GetComponent<ComPosition>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < radius)
		{
			eneityIDList.push_back(eneEntity);
		}
	}
}