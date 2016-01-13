// d:)
#include "PawnFightSystem.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "RoleDataMgr.h"
#include "skill/SkillSystem.h"
#include "GameDefine.h"

#include "../../components/common/TeamCom.h"

using namespace Genius;

void PawnFightSystem::Initialize()
{
	pawnFightMapper.init(*world);
	positionMapper.init(*world);
	colliderMapper.init(*world);
	pawnTemplateMapper.init(*world);
	pawnAttributeMapper.init(*world);
	pawnAnimMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_attackNear);
	EventManager::GetInstance().AddListener(this, Event_attackNear2);
	EventManager::GetInstance().AddListener(this, Event_skill1);
	EventManager::GetInstance().AddListener(this, Event_skill2);
	EventManager::GetInstance().AddListener(this, Event_skill3);
	EventManager::GetInstance().AddListener(this, Event_Hurt);
}

void PawnFightSystem::ProcessEntity(Entity* pEntity)
{
	UpdateLifeBar(pEntity);

	PawnFightCom* myFightCom = pawnFightMapper.get(pEntity);
	PawnAttributeCom* myAttCom = pawnAttributeMapper.get(pEntity);

	if (myAttCom->curLife <= 0)
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
		PawnFightCom* fightCom = pEntity->GetComponent<PawnFightCom>();
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

bool PawnFightSystem::HandleEvent(IEventData const &evt)
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

void PawnFightSystem::HandleAttackTarget(IEventData const &evt)
{
	const AttackNearEvent & castedEvent = static_cast<const AttackNearEvent &>(evt);
	auto fightCom = pawnFightMapper.get(castedEvent.entity);
	if (fightCom)
	{
		Entity* enemy = ECSWorld::GetSingleton()->GetEntity(fightCom->enemyID);
		if (nullptr == enemy)
			return;
		auto posCom = enemy->GetComponent<PositionCom>();
		if (posCom)
		{
			EventManager::GetInstance().FireEvent(TurnToEvent(castedEvent.entity, posCom->x, posCom->y));
			EventManager::GetInstance().FireEvent(ActionEvent(castedEvent.entity, Action_Attack_Near));
		}
	}
}

void PawnFightSystem::HandleAttackTarget2(IEventData const &evt)
{
	const AttackNearEvent & castedEvent = static_cast<const AttackNearEvent &>(evt);
	auto fightCom = pawnFightMapper.get(castedEvent.entity);
	if (fightCom)
	{
		Entity* enemy = ECSWorld::GetSingleton()->GetEntity(fightCom->enemyID);
		if (nullptr == enemy)
			return;
		auto posCom = enemy->GetComponent<PositionCom>();
		if (posCom)
		{
			EventManager::GetInstance().FireEvent(TurnToEvent(castedEvent.entity, posCom->x, posCom->y));
			EventManager::GetInstance().FireEvent(ActionEvent(castedEvent.entity, Action_Attack_Near2));
		}
	}
}

void PawnFightSystem::HandleUseSkill(IEventData const &evt)
{
	const UseSkillEvent & castedEvent = static_cast<const UseSkillEvent &>(evt);
	auto fightCom = pawnFightMapper.get(castedEvent.entity);
	PawnTemplateCom* templateCom = pawnTemplateMapper.get(castedEvent.entity);
	bool ret = false;
	switch (castedEvent.skillType)
	{
	case UseSkillEvent::NormalSkill1:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->normalSkill1);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->normalSkill1);
		break;
	case UseSkillEvent::NormalSkill2:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->normalSkill2);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->normalSkill1);
		break;
	case UseSkillEvent::SpecialSkill1:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->specialSkill1);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->specialSkill1);
		break;
	case UseSkillEvent::SpecialSkill2:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->specialSkill2);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->specialSkill2);
		break;
	case UseSkillEvent::SpecialSkill3:
		ret = SkillSystem::GetSingleton().CanUseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->specialSkill3);
		if (ret)
			SkillSystem::GetSingleton().UseSkill(castedEvent.entity->GetId(), fightCom->enemyID, templateCom->pRoleData->specialSkill3);
		break;
	default:
		return;
	}
}

void PawnFightSystem::HandleHurt(IEventData const &evt)
{
	const HurtEvent & castedEvent = static_cast<const HurtEvent &>(evt);
	auto animCom = pawnAnimMapper.get(castedEvent.entity);
	PawnTemplateCom* myTempCom = pawnTemplateMapper.get(castedEvent.entity);
	if (animCom && myTempCom)
	{
		animCom->PlayFloatNumber(castedEvent.number, myTempCom->pRoleData->lifeBarHeight + 10);
	}
}

bool PawnFightSystem::IsOldTargetVaild(Entity* pEntity)
{
	if (nullptr == pEntity)
		return false;

	PositionCom* myPosCom = positionMapper.get(pEntity);
	BoxColliderCom* myBoxCom = colliderMapper.get(pEntity);
	PawnFightCom* myFightCom = pawnFightMapper.get(pEntity);
	PawnTemplateCom* myTempCom = pawnTemplateMapper.get(pEntity);
	Entity* enemyEntity = world->GetEntity(myFightCom->enemyID);
	if (nullptr == enemyEntity)
	{
		myFightCom->haveTarget = false;
		myFightCom->isTargetInNearRange = false;
		myFightCom->isTargetInFarRange = false;
		return false;
	}

	PawnAttributeCom* enemyAttCom = enemyEntity->GetComponent<PawnAttributeCom>();
	if (enemyAttCom && enemyAttCom->curLife <= 0)
	{
		myFightCom->haveTarget = false;
		myFightCom->isTargetInNearRange = false;
		myFightCom->isTargetInFarRange = false;
		return false;
	}

	PositionCom* enePosCom = enemyEntity->GetComponent<PositionCom>();
	BoxColliderCom* eneBoxCom = enemyEntity->GetComponent<BoxColliderCom>();
	Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
	float len = vecBetween.Length();
	if (len > myTempCom->pRoleData->viewRange)
	{
		myFightCom->haveTarget = false;
		myFightCom->isTargetInNearRange = false;
		myFightCom->isTargetInFarRange = false;
		return false;
	}
	else
	{
		myFightCom->isTargetInFarRange = len < myTempCom->pRoleData->fightRangeFar + eneBoxCom->width*0.5f;
		myFightCom->isTargetInNearRange = len < myTempCom->pRoleData->fightRangeNear + eneBoxCom->width*0.5f;
		return true;
	}
}

int PawnFightSystem::FindNearestTarget(Entity* pEntity, bool sameTeam, bool includeSelf)
{
	PositionCom* myPosCom = positionMapper.get(pEntity);
	PawnFightCom* myFightCom = pawnFightMapper.get(pEntity);
	TeamCom* myTeamCom = pEntity->GetComponent<TeamCom>();
	PawnTemplateCom* myTempCom = pawnTemplateMapper.get(pEntity);
	int enemyId = Entity::InvalidID;
	float minDist = 0;
	//Bag<Entity*>& activities = getActivities();
	std::string targetGroup;
	if (sameTeam)
	{
		targetGroup = myTeamCom->team == Team_Human ? GameDefine::Group_Human : GameDefine::Group_Monster;
	}
	else
	{
		targetGroup = myTeamCom->team == Team_Human ? GameDefine::Group_Monster : GameDefine::Group_Human;
	}
	ImmutableBag<Entity*>* activities = world->GetGroupManager()->GetEntities(targetGroup);
	if (nullptr == activities)
		return Entity::InvalidID;

	for (int i = 0; i < activities->getCount(); i++)
	{
		Entity* pEnemyEntity = activities->get(i);
		if ((! includeSelf) && pEnemyEntity->GetId() == pEntity->GetId())
			continue;

		PawnAttributeCom* enemyAttCom = pEnemyEntity->GetComponent<PawnAttributeCom>();
		if (enemyAttCom && enemyAttCom->curLife <= 0)
			continue;

		//PawnFightCom* eneFightCom = pEnemyEntity->getComponent<PawnFightCom>();
		/*TeamCom* enTeamCom = pEnemyEntity->getComponent<TeamCom>();
		if (sameTeam && myTeamCom->team != enTeamCom->team)
			continue;

		if ((!sameTeam)
			&& ((myTeamCom->team == Team_Human && enTeamCom->team != Team_Monster) || (myTeamCom->team == Team_Monster && enTeamCom->team != Team_Human))
			)
			continue;*/

		PositionCom* enePosCom = pEnemyEntity->GetComponent<PositionCom>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < myTempCom->pRoleData->viewRange)
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

void PawnFightSystem::FindTargetsInScope(int entityID, int scopeSize, bool sameTeam, bool includeSelf, std::vector<Entity*>& eneityIDList)
{
	Entity* pEntity = world->GetEntity(entityID);
	PositionCom* myPosCom = positionMapper.get(pEntity);
	PawnFightCom* myFightCom = pawnFightMapper.get(pEntity);
	PawnTemplateCom* myTempCom = pawnTemplateMapper.get(pEntity);
	TeamCom* myTeamCom = pEntity->GetComponent<TeamCom>();

	Bag<Entity*>& activities = GetActivities();
	for (int i = 0; i < activities.getCount(); i++)
	{
		Entity* pEnemyEntity = activities.get(i);
		if ( (!(sameTeam && includeSelf)) && pEnemyEntity->GetId() == pEntity->GetId())
 			continue;

		PawnAttributeCom* enemyAttCom = pEnemyEntity->GetComponent<PawnAttributeCom>();
		if (enemyAttCom && enemyAttCom->curLife <= 0)
			continue;

		//PawnFightCom* eneFightCom = eneEntity->getComponent<PawnFightCom>();
		TeamCom* enTeamCom = pEnemyEntity->GetComponent<TeamCom>();
		if (sameTeam && myTeamCom->team != enTeamCom->team)
			continue;

		if ((!sameTeam)
			&& ((myTeamCom->team == Team_Human && enTeamCom->team != Team_Monster) || (myTeamCom->team == Team_Monster && enTeamCom->team != Team_Human))
			)
			continue;

		PositionCom* enePosCom = pEnemyEntity->GetComponent<PositionCom>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < scopeSize)
		{
			eneityIDList.push_back(pEnemyEntity);
		}
	}
}

void PawnFightSystem::UpdateLifeBar(Entity* pEntity)
{
	if (nullptr == pEntity)
		return;

	//PositionCom* myPosCom = positionMapper.get(pEntity);
	PawnTemplateCom* myTempCom = pawnTemplateMapper.get(pEntity);
	PawnAttributeCom* myAttCom = pawnAttributeMapper.get(pEntity);
	PawnAnimCom* animCom = pawnAnimMapper.get(pEntity);

	animCom->m_pLifeBar->setPercent((int)(100.0f * myAttCom->curLife / myTempCom->pRoleData->baseLife));
}

int PawnFightSystem::FindFirstTargetByTeam(int team)
{
	int tarEntityID = Entity::InvalidID;
	int tarTeam = team == Team_Human ? Team_Monster : Team_Human;
	Bag<Entity*>& fightActivities = GetActivities();
	for (int i = 0; i < fightActivities.getCount(); i++)
	{
		Entity* pEnemyEntity = fightActivities.get(i);
		TeamCom* enTeamCom = pEnemyEntity->GetComponent<TeamCom>();
		if (enTeamCom->team == tarTeam)
		{
			tarEntityID = pEnemyEntity->GetId();
			break;
		}
	}
	return tarEntityID;
}