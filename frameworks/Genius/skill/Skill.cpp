
#include "Skill.h"
#include "Log.h"
#include "ECS/ecs.h"
#include "data/auto/Role_cfg.hpp"
#include "data/auto/Skill_cfg.hpp"
#include "data/auto/Bullet_cfg.hpp"
#include "data/ConfigPool.h"
#include "BuffManager.h"
#include "skillLogic/SkillLogic.h"
#include "entity/EntityUtility.h"


using namespace Genius;
using namespace cfg;

void Skill::SetSkillCfg(int skillId)
{
	auto skillData = FIND_CFG(Skill_cfg, skillId);
	m_skillData = skillData;
}

bool Skill::CanTrigger(int target)
{
	// cd ?
	return true;
}

bool Skill::Trigger(int owner, int target)
{
	if (nullptr == m_skillData)
		return false;

	m_targetList.clear();

	switch (m_skillData->targetType)
	{
	case FTS_One:
		_TargetOne(owner, target);
		break;
	case FTS_Scope:
		_TargetScope(owner, target);
		break;
	case FTS_Entire:
		_TargetEntire(owner);
		break;
	default:
		return false;
		break;
	}

	_ActiveMe();

	return true;
}

void Skill::_TargetOne(int owner, int target)
{
	switch (m_skillData->targetTeam)
	{
	case TTT_Enemy:
		target = target;
		break;
	case TTT_Self:
		target = owner;
		break;
	default:
		return;
	}
	m_targetList.push_back(target);
}

void Skill::_TargetScope(int owner, int target)
{
	switch (m_skillData->targetTeam)
	{
	case TTT_Enemy:
		EntityUtility::FindTargetsInScope(owner, m_skillData->radius, false, false, m_targetList);
		break;
	case TTT_Self:
		EntityUtility::FindTargetsInScope(owner, m_skillData->radius, true, true, m_targetList);
		break;
	default:
		return;
	}
}

void Skill::_TargetEntire(int owner)
{
	
}

void Skill::_ActiveMe()
{
	SkillLogic* logic = SkillLogic::GetLogic(m_skillData->logicId);
	if (nullptr != logic)
		logic->OnActive(this);
}

void Skill::_DeactiveMe()
{

}


