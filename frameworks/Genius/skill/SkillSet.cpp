
#include "SkillSet.h"

using namespace Genius;

void SkillSet::Update(float elpase)
{

}

bool SkillSet::CanTrigger(int owner, int target, int skill)
{
	auto iterFind = m_skills.find(skill);
	if (iterFind != m_skills.end())
		return iterFind->second.CanTrigger(target);
	else
		return false;
}

bool	 SkillSet::TriggerSkill(int owner, int target, int skill)
{
	auto iterFind = m_skills.find(skill);
	if (iterFind != m_skills.end())
		return iterFind->second.Trigger(owner, target);
	else
		return false;
}

void SkillSet::AddSkill(int skill)
{
	auto iterFind = m_skills.find(skill);
	if (iterFind == m_skills.end())
	{
		m_skills.insert(std::make_pair(skill, Skill(m_ownerID)));
	}
	iterFind = m_skills.find(skill);
	iterFind->second.SetSkillCfg(skill);
}

void SkillSet::Clear()
{

}