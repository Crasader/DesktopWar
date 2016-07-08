
#include "SkillManager.h"
#include "data/auto/Skill_cfg.hpp"
#include "data/ConfigPool.h"

using namespace Genius;
using namespace cfg;


SkillManager::SkillManager() :
m_timeCounter(0)
{

}

void SkillManager::Update(float elapse)
{
	m_timeCounter += elapse;
	if (m_timeCounter < 1)
		return;
	m_timeCounter = 0;
	//
	for (auto iter = m_skillSets.begin(); iter != m_skillSets.end(); ++iter)
	{
		iter->second.Update(elapse);
	}
}

bool	 SkillManager::LoadSkill(int owner, int skillID)
{
	auto iterFind = m_skillSets.find(owner);
	if (iterFind == m_skillSets.end())
	{
		m_skillSets.insert(std::make_pair(owner, SkillSet(owner)));
	}
	iterFind = m_skillSets.find(owner);

	Skill_cfg* skillData = FIND_CFG(Skill_cfg, skillID);
	if (skillData)
	{
		iterFind->second.AddSkill(skillData->id);
	}

	return true;
}

bool	 SkillManager::SaveSkill(int owner)
{
	return true;
}

bool	 SkillManager::CanUseSkill(int owner, int target, int skill)
{
	auto iterFind = m_skillSets.find(owner);
	if (iterFind != m_skillSets.end())
		return iterFind->second.CanTrigger(owner, target, skill);
	else
		return false;
}

bool SkillManager::UseSkill(int owner, int target, int skill)
{
	auto iterFind = m_skillSets.find(owner);
	if (iterFind != m_skillSets.end())
		return iterFind->second.TriggerSkill(owner, target, skill);
	else
		return false;
}

void SkillManager::ClearSkill(int owner)
{
	auto iterFind = m_skillSets.find(owner);
	if (iterFind != m_skillSets.end())
		m_skillSets.erase(iterFind);
}

void SkillManager::ClearAllSkill()
{
	m_skillSets.clear();
}
