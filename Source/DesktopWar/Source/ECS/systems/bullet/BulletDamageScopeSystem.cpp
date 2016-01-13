// d:)
#include "BulletDamageScopeSystem.h"
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
#include "../../components/common/TargetCom.h"

using namespace Genius;

void BulletDamageScopeSystem::Initialize()
{
	positionMapper.init(*world);
	damageMapper.init(*world);
	bulletTemplateMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_BulletTrigger);
}

void BulletDamageScopeSystem::ProcessEntity(Entity* pEntity)
{
}

bool BulletDamageScopeSystem::HandleEvent(IEventData const &evnt)
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

void BulletDamageScopeSystem::OnCollision(int id1, int id2)
{
	Entity* pEntity = ECSWorld::GetSingleton()->GetEntity(id1);
	if (!IsMyEntity(pEntity))
		return;

	Entity* pOtherEntity = ECSWorld::GetSingleton()->GetEntity(id2);
	if (nullptr == pOtherEntity)
		return;

	TargetCom* pMyTargetCom = pEntity->GetComponent<TargetCom>();
	if (nullptr == pMyTargetCom)
		return;

	if (pMyTargetCom->targetType == Target_Entity)
	{
		if (pMyTargetCom->targetID == id2)
		{
			EventManager::GetInstance().FireEvent(BulletHitEvent(pEntity));
		}
	}
	else if (pMyTargetCom->targetType == Target_Location)
	{
		;
	}
}

bool BulletDamageScopeSystem::TriggerBulletBuff(IEventData const &evt)
{
	const BulletTriggerEvent & castedEvent = static_cast<const BulletTriggerEvent &>(evt);
	Entity* ownerEntity = castedEvent.entity;
	if (!IsMyEntity(ownerEntity))
		return false;
	BulletDamageScopeCom* attackCom = damageMapper.get(ownerEntity);
	BulletTemplateCom* bulletTempCom = bulletTemplateMapper.get(ownerEntity);
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

void BulletDamageScopeSystem::FindTargetsInScope(Entity* pEntity, int radius, bool sameTeam, std::vector<Entity*>& eneityIDList)
{
	PositionCom* myPosCom = positionMapper.get(pEntity);
	BulletDamageScopeCom* myAttackCom = damageMapper.get(pEntity);
	TeamCom* myTeamCom = pEntity->GetComponent<TeamCom>();
	int myTeam = myTeamCom->team;

	auto sysMgr = ECSWorld::GetSingleton()->GetSystemManager();
	PawnFightSystem* fightSys = sysMgr->GetSystem<PawnFightSystem>();
	Bag<Entity*>& activities = fightSys->GetActivities();
	for (int i = 0; i < activities.getCount(); i++)
	{
		Entity* eneEntity = activities.get(i);
		if (sameTeam && eneEntity->GetId() == pEntity->GetId())
			continue;

		PawnAttributeCom* enemyAttCom = eneEntity->GetComponent<PawnAttributeCom>();
		if (enemyAttCom && enemyAttCom->curLife <= 0)
			continue;

		TeamCom* enTeamCom = eneEntity->GetComponent<TeamCom>();
		if (sameTeam && myTeam != enTeamCom->team)
			continue;

		if ((!sameTeam)
			&& ((myTeam == Team_Human && enTeamCom->team != Team_Monster) || (myTeam == Team_Monster && enTeamCom->team != Team_Human))
			)
			continue;

		PositionCom* enePosCom = eneEntity->GetComponent<PositionCom>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < radius)
		{
			eneityIDList.push_back(eneEntity);
		}
	}
}