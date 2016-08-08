

#include "EntityUtility.h"
#include "common/Log.h"
#include "ECS/ecs.h"
#include "ECS/EntityWrapper.h"
#include "data/auto/Role_cfg.hpp"


const std::string& EntityUtility::GetEnemyTag(const std::string& myTag)
{
	if (myTag == GameDefine::Tag_Soldier)
		return GameDefine::Tag_Monster;
	else if (myTag == GameDefine::Tag_Monster)
		return GameDefine::Tag_Soldier;
	else
	{
		Log::Error("EntityUtility::GetEnemyTag : invalid tag.");
		static std::string empty;
		return empty;
	}
}

bool EntityUtility::IsTagged(const std::string& tag, Entity* entity)
{
	return ECSWorld::GetSingleton()->GetTagManager()->IsSubscribed(tag, entity);
}

bool EntityUtility::IsEnemy(Entity* entity1, Entity* entity2)
{
	if (nullptr == entity1 || nullptr == entity2)
		return false;

	bool isSoldier1 = EntityUtility::IsTagged(GameDefine::Tag_Soldier, entity1);
	if (isSoldier1)
		return EntityUtility::IsTagged(GameDefine::Tag_Monster, entity2);

	bool isMonster1 = EntityUtility::IsTagged(GameDefine::Tag_Monster, entity1);
	if (isMonster1)
		return EntityUtility::IsTagged(GameDefine::Tag_Soldier, entity2);

	return false;
}


bool EntityUtility::AreEntitiesCloseEnough(EntityWrapper* entityw1, EntityWrapper* entityw2, float distance)
{
	auto entity1 = entityw1->GetEntity();
	auto entity2 = entityw2->GetEntity();
	auto box1 = entity1->GetComponent<ComBoxCollider>();
	auto box2 = entity2->GetComponent<ComBoxCollider>();
	auto tran1 = entity1->GetComponent<ComTransform>();
	auto tran2 = entity2->GetComponent<ComTransform>();
	auto distx = abs(tran1->GetX() - tran2->GetX());
	auto disty = abs(tran1->GetY() - tran2->GetY());
	auto width = box1->GetWidth()*0.5f + box2->GetWidth()*0.5f;
	auto height = width*0.5f;
	return distx - width < distance && disty - height < distance;
}

bool EntityUtility::IsInMyViewSight(EntityWrapper* entityw1, EntityWrapper* entityw2)
{
	auto entity1 = entityw1->GetEntity();
	auto entity2 = entityw2->GetEntity();
	float distance = entity1->GetComponent<ComPawnAgent>()->m_roleCfg->viewRange;
	return AreEntitiesCloseEnough(entityw1, entityw2, distance);
}

bool EntityUtility::IsInMyNearRange(EntityWrapper* entityw1, EntityWrapper* entityw2)
{
	auto entity1 = entityw1->GetEntity();
	auto entity2 = entityw2->GetEntity();
	float distance = entity1->GetComponent<ComPawnAgent>()->m_roleCfg->fightRangeNear;
	return AreEntitiesCloseEnough(entityw1, entityw2, distance);
}

bool EntityUtility::IsInMyFarRange(EntityWrapper* entityw1, EntityWrapper* entityw2)
{
	auto entity1 = entityw1->GetEntity();
	auto entity2 = entityw2->GetEntity();
	float distance = entity1->GetComponent<ComPawnAgent>()->m_roleCfg->fightRangeFar;
	return AreEntitiesCloseEnough(entityw1, entityw2, distance);
}


