
#include "SystemPawnFight.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "RoleDataMgr.h"
#include "skill/SkillSystem.h"
#include "app/GameDefine.h"
#include "pawn/PawnBlackboard.h"
#include "pawn/action/ActionDefine.h"
#include "../../components/common/ComTeam.h"

using namespace Genius;

void SystemPawnFight::Initialize()
{
	pawnFightMapper.init(*world);
	positionMapper.init(*world);
	colliderMapper.init(*world);
	pawnAgentMapper.init(*world);
	pawnAgentMapper.init(*world);
	pawnAnimMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_attackNear);
	EventManager::GetInstance().AddListener(this, Event_attackNear2);
	EventManager::GetInstance().AddListener(this, Event_skill1);
	EventManager::GetInstance().AddListener(this, Event_skill2);
	EventManager::GetInstance().AddListener(this, Event_skill3);
	EventManager::GetInstance().AddListener(this, Event_Hurt);
}

void SystemPawnFight::ProcessEntity(Entity* pEntity)
{
	UpdateLifeBar(pEntity);

	ComPawnFight* myFightCom = pawnFightMapper.get(pEntity);
	ComPawnAgent* myAttCom = pawnAgentMapper.get(pEntity);

	if (myAttCom->GetBlackboard()->m_currentHP<= 0)
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
	case Event_attackNear:
		HandleAttackTarget(evt);
		break;
	case Event_attackNear2:
		HandleAttackTarget2(evt);
		break;
	case Event_skill1:
		HandleUseSkill(evt);
		break;
	case Event_Hurt:
		HandleHurt(evt);
		break;
	default:
		break;
	}

	return true;
}

void SystemPawnFight::HandleAttackTarget(IEventData const &evt)
{
	const AttackNearEvent & castedEvent = static_cast<const AttackNearEvent &>(evt);
	auto fightCom = pawnFightMapper.get(castedEvent.entity);
	if (fightCom)
	{
		Entity* enemy = ECSWorld::GetSingleton()->GetEntity(fightCom->enemyID);
		if (nullptr == enemy)
			return;
		auto posCom = enemy->GetComponent<ComPosition>();
		if (posCom)
		{
			EventManager::GetInstance().FireEvent(TurnToEvent(castedEvent.entity, posCom->x, posCom->y));
			//EventManager::GetInstance().FireEvent(ActionEvent(castedEvent.entity, Action_Attack_Near));
			ComPawnAgent* agentCom = castedEvent.entity->GetComponent<ComPawnAgent>();
			agentCom->AddAction(PAT_AttackNear);
		}
	}
}

void SystemPawnFight::HandleAttackTarget2(IEventData const &evt)
{
	const AttackNearEvent & castedEvent = static_cast<const AttackNearEvent &>(evt);
	auto fightCom = pawnFightMapper.get(castedEvent.entity);
	if (fightCom)
	{
		Entity* enemy = ECSWorld::GetSingleton()->GetEntity(fightCom->enemyID);
		if (nullptr == enemy)
			return;
		auto posCom = enemy->GetComponent<ComPosition>();
		if (posCom)
		{
			EventManager::GetInstance().FireEvent(TurnToEvent(castedEvent.entity, posCom->x, posCom->y));
			//EventManager::GetInstance().FireEvent(ActionEvent(castedEvent.entity, Action_Attack_Near2));
			ComPawnAgent* agentCom = castedEvent.entity->GetComponent<ComPawnAgent>();
			agentCom->AddAction(PAT_AttackNear);
		}
	}
}

void SystemPawnFight::HandleUseSkill(IEventData const &evt)
{
	const UseSkillEvent & castedEvent = static_cast<const UseSkillEvent &>(evt);
	auto fightCom = pawnFightMapper.get(castedEvent.entity);
	ComPawnAgent* templateCom = pawnAgentMapper.get(castedEvent.entity);
	bool ret = false;
	switch (castedEvent.skillType)
	{
	case UseSkillEvent::NormalSkill1:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->normalSkill1);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->normalSkill1);
		break;
	case UseSkillEvent::NormalSkill2:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->normalSkill2);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->normalSkill1);
		break;
	case UseSkillEvent::SpecialSkill1:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->specialSkill1);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->specialSkill1);
		break;
	case UseSkillEvent::SpecialSkill2:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->specialSkill2);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->specialSkill2);
		break;
	case UseSkillEvent::SpecialSkill3:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->specialSkill3);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->m_pRoleData->specialSkill3);
		break;
	default:
		return;
	}
}

void SystemPawnFight::HandleHurt(IEventData const &evt)
{
	const HurtEvent & castedEvent = static_cast<const HurtEvent &>(evt);
	auto animCom = pawnAnimMapper.get(castedEvent.entity);
	ComPawnAgent* myTempCom = pawnAgentMapper.get(castedEvent.entity);
	if (animCom && myTempCom)
	{
		animCom->PlayFloatNumber(castedEvent.number, myTempCom->m_pRoleData->lifeBarHeight + 10);
	}
}

bool SystemPawnFight::IsOldTargetVaild(Entity* pEntity)
{
	if (nullptr == pEntity)
		return false;

	ComPosition* myPosCom = positionMapper.get(pEntity);
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
	if (enemyAttCom && enemyAttCom->GetBlackboard()->m_currentHP<= 0)
	{
		myFightCom->haveTarget = false;
		myFightCom->isTargetInNearRange = false;
		myFightCom->isTargetInFarRange = false;
		return false;
	}

	ComPosition* enePosCom = enemyEntity->GetComponent<ComPosition>();
	ComBoxCollider* eneBoxCom = enemyEntity->GetComponent<ComBoxCollider>();
	Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
	float len = vecBetween.Length();
	if (len > myTempCom->m_pRoleData->viewRange)
	{
		myFightCom->haveTarget = false;
		myFightCom->isTargetInNearRange = false;
		myFightCom->isTargetInFarRange = false;
		return false;
	}
	else
	{
		myFightCom->isTargetInFarRange = len < myTempCom->m_pRoleData->fightRangeFar + eneBoxCom->width*0.5f;
		myFightCom->isTargetInNearRange = len < myTempCom->m_pRoleData->fightRangeNear + eneBoxCom->width*0.5f;
		return true;
	}
}

int SystemPawnFight::FindNearestTarget(Entity* pEntity, bool sameTeam, bool includeSelf)
{
	ComPosition* myPosCom = positionMapper.get(pEntity);
	ComPawnFight* myFightCom = pawnFightMapper.get(pEntity);
	ComTeam* myComTeam = pEntity->GetComponent<ComTeam>();
	ComPawnAgent* myTempCom = pawnAgentMapper.get(pEntity);
	int enemyId = Entity::InvalidID;
	float minDist = 0;
	//Bag<Entity*>& activities = getActivities();
	std::string targetGroup;
	if (sameTeam)
	{
		targetGroup = myComTeam->team == Team_Human ? GameDefine::Group_Human : GameDefine::Group_Monster;
	}
	else
	{
		targetGroup = myComTeam->team == Team_Human ? GameDefine::Group_Monster : GameDefine::Group_Human;
	}
	ImmutableBag<Entity*>* activities = world->GetGroupManager()->GetEntities(targetGroup);
	if (nullptr == activities)
		return Entity::InvalidID;

	for (int i = 0; i < activities->getCount(); i++)
	{
		Entity* pEnemyEntity = activities->get(i);
		if ((! includeSelf) && pEnemyEntity->GetId() == pEntity->GetId())
			continue;

		ComPawnAgent* enemyAttCom = pEnemyEntity->GetComponent<ComPawnAgent>();
		if (enemyAttCom && enemyAttCom->GetBlackboard()->m_currentHP<= 0)
			continue;

		//ComPawnFight* eneFightCom = pEnemyEntity->getComponent<ComPawnFight>();
		/*ComTeam* enComTeam = pEnemyEntity->getComponent<ComTeam>();
		if (sameTeam && myComTeam->team != enComTeam->team)
			continue;

		if ((!sameTeam)
			&& ((myComTeam->team == Team_Human && enComTeam->team != Team_Monster) || (myComTeam->team == Team_Monster && enComTeam->team != Team_Human))
			)
			continue;*/

		ComPosition* enePosCom = pEnemyEntity->GetComponent<ComPosition>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < myTempCom->m_pRoleData->viewRange)
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

void SystemPawnFight::FindTargetsInScope(int entityID, int scopeSize, bool sameTeam, bool includeSelf, std::vector<Entity*>& eneityIDList)
{
	Entity* pEntity = world->GetEntity(entityID);
	ComPosition* myPosCom = positionMapper.get(pEntity);
	ComPawnFight* myFightCom = pawnFightMapper.get(pEntity);
	ComPawnAgent* myTempCom = pawnAgentMapper.get(pEntity);
	ComTeam* myComTeam = pEntity->GetComponent<ComTeam>();

	Bag<Entity*>& activities = GetActivities();
	for (int i = 0; i < activities.getCount(); i++)
	{
		Entity* pEnemyEntity = activities.get(i);
		if ( (!(sameTeam && includeSelf)) && pEnemyEntity->GetId() == pEntity->GetId())
 			continue;

		ComPawnAgent* enemyAttCom = pEnemyEntity->GetComponent<ComPawnAgent>();
		if (enemyAttCom && enemyAttCom->GetBlackboard()->m_currentHP<= 0)
			continue;

		//ComPawnFight* eneFightCom = eneEntity->getComponent<ComPawnFight>();
		ComTeam* enComTeam = pEnemyEntity->GetComponent<ComTeam>();
		if (sameTeam && myComTeam->team != enComTeam->team)
			continue;

		if ((!sameTeam)
			&& ((myComTeam->team == Team_Human && enComTeam->team != Team_Monster) || (myComTeam->team == Team_Monster && enComTeam->team != Team_Human))
			)
			continue;

		ComPosition* enePosCom = pEnemyEntity->GetComponent<ComPosition>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < scopeSize)
		{
			eneityIDList.push_back(pEnemyEntity);
		}
	}
}

void SystemPawnFight::UpdateLifeBar(Entity* pEntity)
{
	if (nullptr == pEntity)
		return;

	//ComPosition* myPosCom = positionMapper.get(pEntity);
	ComPawnAgent* myTempCom = pawnAgentMapper.get(pEntity);
	ComPawnAgent* myAttCom = pawnAgentMapper.get(pEntity);
	ComPawnAnim* animCom = pawnAnimMapper.get(pEntity);

	animCom->m_pLifeBar->setPercent((int)(100.0f * myAttCom->GetBlackboard()->m_currentHP/ myTempCom->m_pRoleData->baseLife));
}

int SystemPawnFight::FindFirstTargetByTeam(int team)
{
	int tarEntityID = Entity::InvalidID;
	int tarTeam = team == Team_Human ? Team_Monster : Team_Human;
	Bag<Entity*>& fightActivities = GetActivities();
	for (int i = 0; i < fightActivities.getCount(); i++)
	{
		Entity* pEnemyEntity = fightActivities.get(i);
		ComTeam* enComTeam = pEnemyEntity->GetComponent<ComTeam>();
		if (enComTeam->team == tarTeam)
		{
			tarEntityID = pEnemyEntity->GetId();
			break;
		}
	}
	return tarEntityID;
}