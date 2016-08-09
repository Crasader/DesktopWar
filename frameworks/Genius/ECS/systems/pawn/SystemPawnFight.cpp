
#include "SystemPawnFight.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "data/auto/Role_cfg.hpp"
#include "skill/SkillManager.h"
#include "app/GameDefine.h"
#include "pawn/PawnBlackboard.h"
#include "pawn/action/ActionDefine.h"
#include "entity/EntityUtility.h"


using namespace Genius;

void SystemPawnFight::Initialize()
{
	pawnFightMapper.init(*world);
	transMapper.init(*world);
	colliderMapper.init(*world);
	pawnAgentMapper.init(*world);
	pawnAgentMapper.init(*world);
	pawnAnimMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_attackNear);
	EventManager::GetSingleton()->AddListener(this, Event_attackNear2);
	EventManager::GetSingleton()->AddListener(this, Event_skill1);
	EventManager::GetSingleton()->AddListener(this, Event_skill2);
	EventManager::GetSingleton()->AddListener(this, Event_skill3);
	EventManager::GetSingleton()->AddListener(this, Event_Hurt);
}

void SystemPawnFight::ProcessEntity(Entity* pEntity)
{
	UpdateLifeBar(pEntity);

	ComPawnFight* myFightCom = pawnFightMapper.get(pEntity);
	ComPawnAgent* myAttCom = pawnAgentMapper.get(pEntity);

	if (myAttCom->GetBlackboard()->GetAttr(AttrType::HP)<= 0)
	{
		myFightCom->haveTarget = false;
		myFightCom->isTargetInNearRange = false;
		return;
	}

	// if enemy is far away, find another, else keep.
	bool shouldFind = false;
	if (myFightCom->haveTarget)
		shouldFind = !IsOldTargetVaild(pEntity);
	else
		shouldFind = true;

	if (shouldFind)
	{
		ComPawnFight* fightCom = pEntity->GetComponent<ComPawnFight>();
		int enemyId = FindNearestTarget(pEntity, false, false);
		if (enemyId == Entity::InvalidID)
		{
			myFightCom->haveTarget = false;
			myFightCom->isTargetInNearRange = false;
			myFightCom->enemyID = Entity::InvalidID;;
		}
		else
		{
			myFightCom->haveTarget = true;
			myFightCom->isTargetInNearRange = false;
			myFightCom->enemyID = enemyId;
		}
	}

}

bool SystemPawnFight::HandleEvent(IEventData const &evt)
{
	EventType eType = evt.GetType();
	switch (eType)
	{
	case Event_Hurt:
		HandleHurt(evt);
		break;
	default:
		break;
	}

	return true;
}

void SystemPawnFight::HandleHurt(IEventData const &evt)
{
	const HurtEvent & castedEvent = static_cast<const HurtEvent &>(evt);
	auto animCom = pawnAnimMapper.get(castedEvent.entity);
	ComPawnAgent* myTempCom = pawnAgentMapper.get(castedEvent.entity);
	if (animCom && myTempCom)
	{
		animCom->PlayFloatNumber(castedEvent.number, myTempCom->m_roleCfg->lifeBarHeight + 10);
	}
}

bool SystemPawnFight::IsOldTargetVaild(Entity* pEntity)
{
	if (nullptr == pEntity)
		return false;

	ComTransform* myPosCom = transMapper.get(pEntity);
	ComBoxCollider* myBoxCom = colliderMapper.get(pEntity);
	ComPawnFight* myFightCom = pawnFightMapper.get(pEntity);
	ComPawnAgent* myTempCom = pawnAgentMapper.get(pEntity);
	Entity* enemyEntity = world->GetEntity(myFightCom->enemyID);
	if (nullptr == enemyEntity)
	{
		myFightCom->haveTarget = false;
		myFightCom->isTargetInNearRange = false;
		myFightCom->isTargetInFarRange = false;
		return false;
	}

	ComPawnAgent* enemyAttCom = enemyEntity->GetComponent<ComPawnAgent>();
	if (enemyAttCom && enemyAttCom->GetBlackboard()->GetAttr(AttrType::HP)<= 0)
	{
		myFightCom->haveTarget = false;
		myFightCom->isTargetInNearRange = false;
		myFightCom->isTargetInFarRange = false;
		return false;
	}

	ComTransform* enePosCom = enemyEntity->GetComponent<ComTransform>();
	ComBoxCollider* eneBoxCom = enemyEntity->GetComponent<ComBoxCollider>();
	Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
	float len = vecBetween.Length();
	if (len > myTempCom->m_roleCfg->viewRange)
	{
		myFightCom->haveTarget = false;
		myFightCom->isTargetInNearRange = false;
		myFightCom->isTargetInFarRange = false;
		return false;
	}
	else
	{
		myFightCom->isTargetInFarRange = len < myTempCom->m_roleCfg->fightRangeFar + eneBoxCom->width*0.5f;
		myFightCom->isTargetInNearRange = len < myTempCom->m_roleCfg->fightRangeNear + eneBoxCom->width*0.5f;
		return true;
	}
}

int SystemPawnFight::FindNearestTarget(Entity* pEntity, bool sameTeam, bool includeSelf)
{
	ComTransform* myPosCom = transMapper.get(pEntity);
	ComPawnFight* myFightCom = pawnFightMapper.get(pEntity);
	ComPawnAgent* myTempCom = pawnAgentMapper.get(pEntity);
	int enemyId = Entity::InvalidID;
	float minDist = 0;
	
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
	if (activities.size() == 0)
		return Entity::InvalidID;

	for (auto& it : activities)
	{
		Entity* pEnemyEntity = it.second;
		if ((! includeSelf) && pEnemyEntity->GetId() == pEntity->GetId())
			continue;

		ComPawnAgent* enemyAttCom = pEnemyEntity->GetComponent<ComPawnAgent>();
		if (enemyAttCom && enemyAttCom->GetBlackboard()->GetAttr(AttrType::HP)<= 0)
			continue;

		ComTransform* enePosCom = pEnemyEntity->GetComponent<ComTransform>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < myTempCom->m_roleCfg->viewRange)
		{
			if (enemyId == Entity::InvalidID)
			{
				enemyId = pEnemyEntity->GetId();
				minDist = len;
			}
			else if (len < minDist)
			{
				enemyId = pEnemyEntity->GetId();
				minDist = len;
			}
		}
	}

	return enemyId;
}

void SystemPawnFight::FindTargetsInScope(int entityID, int scopeSize, bool sameTeam, bool includeSelf, std::vector<int>& eneityIDList)
{
	Entity* pEntity = world->GetEntity(entityID);
	ComTransform* myPosCom = transMapper.get(pEntity);
	ComPawnFight* myFightCom = pawnFightMapper.get(pEntity);
	ComPawnAgent* myTempCom = pawnAgentMapper.get(pEntity);

	//int myTeam = myTempCom->GetBlackboard()->team;

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
		Entity* pEnemyEntity = it.second;
// 	}
// 	Bag<Entity*>& activities = GetActivities();
// 	for (int i = 0; i < activities.getCount(); i++)
// 	{
// 		Entity* pEnemyEntity = activities.get(i);
	/*	if ( (!(sameTeam && includeSelf)) && pEnemyEntity->GetId() == pEntity->GetId())
 			continue;*/

		ComPawnAgent* enemyAttCom = pEnemyEntity->GetComponent<ComPawnAgent>();
		if (enemyAttCom && enemyAttCom->GetBlackboard()->GetAttr(AttrType::HP)<= 0)
			continue;

	/*	int enemyTeam = enemyAttCom->GetBlackboard()->team;
		if (sameTeam && myTeam != enemyTeam)
			continue;

		if ((!sameTeam)
			&& ((myTeam == Team_Human && enemyTeam != Team_Monster) || (myTeam == Team_Monster && enemyTeam != Team_Human))
			)
			continue;*/

		ComTransform* enePosCom = pEnemyEntity->GetComponent<ComTransform>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < scopeSize)
		{
			eneityIDList.push_back(pEnemyEntity->GetId());
		}
	}
}

void SystemPawnFight::UpdateLifeBar(Entity* pEntity)
{
	if (nullptr == pEntity)
		return;

	//ComTransform* myPosCom = transMapper.get(pEntity);
	ComPawnAgent* myTempCom = pawnAgentMapper.get(pEntity);
	ComPawnAgent* myAttCom = pawnAgentMapper.get(pEntity);
	ComPawnAnim* animCom = pawnAnimMapper.get(pEntity);

	animCom->m_pLifeBar->setPercent((int)(100.0f * myAttCom->GetBlackboard()->GetAttr(AttrType::HP)/ myTempCom->m_roleCfg->baseLife));
}

int SystemPawnFight::FindRandTargetByTag(const string& tag)
{
	int tarEntityID = Entity::InvalidID;

	entity_map& activities = world->GetEntitiesByTag(tag);
	for (auto& it : activities)
	{
		tarEntityID = it.second->GetId();
		break;
	}

	/*int tarTeam = team == Team_Human ? Team_Monster : Team_Human;
	Bag<Entity*>& fightActivities = GetActivities();
	for (int i = 0; i < fightActivities.getCount(); i++)
	{
		Entity* pEnemyEntity = fightActivities.get(i);
		auto enComAgent = pEnemyEntity->GetComponent<ComPawnAgent>();
		if (enComAgent->GetBlackboard()->team == tarTeam)
		{
			tarEntityID = pEnemyEntity->GetId();
			break;
		}
	}*/
	return tarEntityID;
}