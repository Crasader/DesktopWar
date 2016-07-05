
#include "SkillSystem.h"
#include "data/auto/Skill_cfg.hpp"
#include "data/ConfigPool.h"

using namespace Genius;
using namespace cfg;

SkillSystem& SkillSystem::GetSingleton()
{
	static SkillSystem inst;
	return inst;
}

SkillSystem::SkillSystem() :
m_timeCounter(0)
{

}

void SkillSystem::Update(float elapse)
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

bool	 SkillSystem::LoadSkill(int owner, int skillID)
{
	auto iterFind = m_skillSets.find(owner);
	if (iterFind == m_skillSets.end())
	{
		m_skillSets.insert(std::make_pair(owner, SkillSet(owner)));
	}
	iterFind = m_skillSets.find(owner);

	Skill_cfg* skillData = ConfigPool::GetSingleton()->GetConfig<Skill_cfg>(skillID);
	if (skillData)
	{
		iterFind->second.AddSkill(skillData->id);
	}

	return true;
}

bool	 SkillSystem::SaveSkill(int owner)
{
	return true;
}

bool	 SkillSystem::CanUseSkill(int owner, int target, int skill)
{
	auto iterFind = m_skillSets.find(owner);
	if (iterFind != m_skillSets.end())
		return iterFind->second.CanUseSkill(owner, target, skill);
	else
		return false;
}

bool SkillSystem::UseSkill(int owner, int target, int skill)
{
	auto iterFind = m_skillSets.find(owner);
	if (iterFind != m_skillSets.end())
		return iterFind->second.UseSkill(owner, target, skill);
	else
		return false;
}

void SkillSystem::ClearSkill(int owner)
{
	auto iterFind = m_skillSets.find(owner);
	if (iterFind != m_skillSets.end())
		m_skillSets.erase(iterFind);
}

void SkillSystem::ClearAllSkill()
{
	m_skillSets.clear();
}
