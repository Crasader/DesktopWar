
#include "SL_Bullet.h"
#include "../Skill.h"
#include "data/auto/Skill_cfg.hpp"
#include "ECS/ecs.h"
#include "entity/EntityCreators.h"
#include "pawn/PawnBlackboard.h"

using namespace Genius;

IMPL_SKILLLOGIC_CREATOR(SL_Bullet);


void SL_Bullet::OnActive(Skill* skill)
{
	auto targetList = skill->GetTargetList();
	for (auto iter = targetList.begin(); iter != targetList.end(); ++iter)
	{
		Entity* ownerEntity = ECSWorld::GetSingleton()->GetEntity(skill->GetOwner());
		if (nullptr == ownerEntity)
			return;

		ComTransform* ownerPosCom = ownerEntity->GetComponent<ComTransform>();
		//ComTeam* ownerComTeam = ownerEntity->GetComponent<ComTeam>();
		ComPawnAgent* ownerAgentCom = ownerEntity->GetComponent<ComPawnAgent>();
		ComTransform* ownerDirCom = ownerEntity->GetComponent<ComTransform>();
		if (nullptr == ownerAgentCom || nullptr == ownerDirCom)
			return;

		float startX = ownerPosCom->x;
		float startY = ownerPosCom->y;
		if (ownerPosCom->curDir & Face_Left)
		{
			startX = ownerPosCom->x - ownerAgentCom->m_roleCfg->bulletX;
			startY = ownerPosCom->y + ownerAgentCom->m_roleCfg->bulletY;
		}
		else if (ownerPosCom->curDir & Face_Right)
		{
			startX = ownerPosCom->x + ownerAgentCom->m_roleCfg->bulletX;
			startY = ownerPosCom->y + ownerAgentCom->m_roleCfg->bulletY;
		}
		else
		{
			startX = startX;
		}

		int team = ownerAgentCom->GetBlackboard()->team;
		int targetID = *iter;
		auto skillCfg = skill->GetSkillCfg();
		Entity* tarEntity = ECSWorld::GetSingleton()->GetEntity(targetID);
		if (nullptr != tarEntity)
		{
			// 有目标就直接飞向目标
			ComTransform* posCom = tarEntity->GetComponent<ComTransform>();
			EntityCreator::CreateBullet(skillCfg->bulletID, targetID, startX, startY, team, posCom->x, posCom->y);
		}
		else
		{
			// 没目标自己飞一会然后自己找目标。
			EntityCreator::CreateBullet(skillCfg->bulletID, Entity::InvalidID, startX, startY, team, 0, 0);
		}
	}
}

void SL_Bullet::OnDeactive(Skill* skill)
{
	// do what ?
}


