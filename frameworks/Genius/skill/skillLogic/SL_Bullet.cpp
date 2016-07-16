
#include "SL_Bullet.h"
#include "../Skill.h"
#include "data/auto/Skill_cfg.hpp"
#include "data/auto/Role_cfg.hpp"
#include "ECS/ecs.h"
#include "entity/EntityCreators.h"
#include "entity/EntityUtility.h"
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

		bool isTagged = EntityUtility::IsTagged(GameDefine::Tag_Soldier, ownerEntity);
		const string& targetTag = isTagged ? GameDefine::Tag_Soldier : GameDefine::Tag_Monster;
		int targetID = *iter;
		auto skillCfg = skill->GetSkillCfg();
		Entity* tarEntity = ECSWorld::GetSingleton()->GetEntity(targetID);
		if (nullptr != tarEntity)
		{
			// ��Ŀ���ֱ�ӷ���Ŀ��
			ComTransform* posCom = tarEntity->GetComponent<ComTransform>();
			EntityCreator::CreateBullet(skillCfg->bulletID, targetID, startX, startY, targetTag, posCom->x, posCom->y);
		}
		else
		{
			// ûĿ���Լ���һ��Ȼ���Լ���Ŀ�ꡣ
			EntityCreator::CreateBullet(skillCfg->bulletID, Entity::InvalidID, startX, startY, targetTag, 0, 0);
		}
	}
}

void SL_Bullet::OnDeactive(Skill* skill)
{
	// do what ?
}


