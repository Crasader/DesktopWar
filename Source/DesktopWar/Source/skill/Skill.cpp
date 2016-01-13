// d:)
#include "Skill.h"
#include "Logger.h"
#include "ECS/ecs.h"
#include "data/RoleDataMgr.h"
#include "data/SkillDataMgr.h"
#include "data/BulletDataMgr.h"
#include "BuffSystem.h"
#include "EntityCreators.h"

using namespace Genius;

void Skill::SetSkillType(int tp)
{
	auto skillData = SkillDataMgr::GetSingleton()->GetSkillData(tp);
	m_skillData = skillData;
}

bool Skill::CanTrigger(int target)
{
	return true;
}

bool Skill::Trigger(int owner, int target)
{
	if (nullptr == m_skillData)
		return false;

	switch (m_skillData->findTargetStyle)
	{
	case FTS_One:
		return TargetOne(owner, target);
		break;
	case FTS_Scope:
		return TargetScope(owner, target);
		break;
	case FTS_Entire:
		return TargetEntire(owner);
		break;
	case FTS_Bullet:
		return TargetBullet(owner, target);
		break;
	default:
		return false;
		break;
	}
}

bool Skill::TargetOne(int owner, int target)
{
	Entity* entTarget = ECSWorld::GetSingleton()->GetEntity(target);
	if (nullptr == entTarget)
		return false;

	switch (m_skillData->targetTeam)
	{
	case TTT_Enemy:
		target = target;
		break;
	case TTT_Self:
		target = owner;
		break;
	default:
		break;
	}

	auto pawnAttCom = entTarget->GetComponent<ComPawnAttribute>();
	if (pawnAttCom)
	{
		for (int i = 0; i < SkillData::MaxBuffNum; ++i)
		{
			if (m_skillData->buffs[i] != 0)
				BuffSystem::GetSingleton().AddBuff(m_ownerID, target, m_skillData->buffs[i]);
		}
		return true;
	}

	return false;
}

bool Skill::TargetScope(int owner, int target)
{
	auto sysMgr = ECSWorld::GetSingleton()->GetSystemManager();
	SystemPawnFight* fightSys = sysMgr->GetSystem<SystemPawnFight>();
	std::vector<Entity*> targets;

	switch (m_skillData->targetTeam)
	{
	case TTT_Enemy:
		fightSys->FindTargetsInScope(owner, m_skillData->findTargetRadius, false, false, targets);
		break;
	case TTT_Self:
		fightSys->FindTargetsInScope(owner, m_skillData->findTargetRadius, true, true, targets);
		break;
	default:
		break;
	}
	
	for (auto iter = targets.begin(); iter != targets.end(); ++iter)
	{
		for (int i = 0; i < SkillData::MaxBuffNum; ++i)
		{
			if (m_skillData->buffs[i] != 0)
				BuffSystem::GetSingleton().AddBuff(m_ownerID, (*iter)->GetId(), m_skillData->buffs[i]);
		}
	}
	
	return false;
}

bool Skill::TargetEntire(int owner)
{
	return false;
}

bool Skill::TargetBullet(int owner, int targetID)
{
	Entity* ownerEntity = ECSWorld::GetSingleton()->GetEntity(owner);
	if (nullptr == ownerEntity)
		return false;

	ComPosition* ownerPosCom = ownerEntity->GetComponent<ComPosition>();
	//ComPawnFight* ownerFightCom = ownerEntity->getComponent<ComPawnFight>();
	ComTeam* ownerComTeam = ownerEntity->GetComponent<ComTeam>();
	ComPawnTemplate* ownerTempCom = ownerEntity->GetComponent<ComPawnTemplate>();
	ComPawnDirection* ownerDirCom = ownerEntity->GetComponent<ComPawnDirection>();
	if (nullptr == ownerComTeam || nullptr == ownerTempCom || nullptr == ownerDirCom)
		return false;

	float startX = ownerPosCom->x;
	float startY = ownerPosCom->y;
	if (ownerDirCom->m_faceDir & Face_Left)
	{
		startX = ownerPosCom->x - ownerTempCom->pRoleData->bulletX;
		startY = ownerPosCom->y + ownerTempCom->pRoleData->bulletY;
	}
	else if (ownerDirCom->m_faceDir & Face_Right)
	{
		startX = ownerPosCom->x + ownerTempCom->pRoleData->bulletX;
		startY = ownerPosCom->y + ownerTempCom->pRoleData->bulletY;
	}
	else
	{
		startX = startX;
	}

	int team = ownerComTeam->team;
	
	Entity* tarEntity = ECSWorld::GetSingleton()->GetEntity(targetID);
	if (nullptr != tarEntity)
	{// 有目标就直接飞向目标
		ComPosition* posCom = tarEntity->GetComponent<ComPosition>();
		EntityCreator::CreateBullet(m_skillData->bulletID, targetID, startX, startY, team, posCom->x, posCom->y);
		return true;
	}
	else
	{
		// 没目标自己飞一会然后自己找目标。
		EntityCreator::CreateBullet(m_skillData->bulletID, Entity::InvalidID, startX, startY, team, 0, 0);
		return true;
	}

	return false;
}
