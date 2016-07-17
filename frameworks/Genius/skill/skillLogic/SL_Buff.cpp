
#include "SL_Buff.h"
#include "../Skill.h"
#include "data/auto/Skill_cfg.hpp"
#include "../BuffManager.h"

using namespace Genius;

IMPL_SKILLLOGIC_CREATOR(SL_Buff);


void SL_Buff::OnActive(Skill* skill)
{
	auto targetList = skill->GetTargetList();
	for (auto iter = targetList.begin(); iter != targetList.end(); ++iter)
	{
		for (int i = 0; i < Skill::BuffCount; ++i)
		{
			auto skillCfg = skill->GetSkillCfg();
			int targetId = *iter;
			if (skillCfg->buffs[i] > 0)
			{
				BuffManager::GetSingleton()->AddBuff(skill->GetEntity(), targetId, skillCfg->buffs[i]);
			}
		}
	}
}

void SL_Buff::OnDeactive(Skill* skill)
{
	// do what ?
}


