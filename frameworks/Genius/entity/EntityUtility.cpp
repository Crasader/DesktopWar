

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


int EntityUtility::FindNearestTarget(Entity* pEntity, bool sameTeam, bool includeSelf)
{
	ComTransform* myPosCom = pEntity->GetComponent<ComTransform>();
	ComPawnAgent* myTempCom = pEntity->GetComponent<ComPawnAgent>();
	int enemyId = Entity::InvalidID;
	float minDist = 0;

	std::string targetTag;
	if (sameTeam)
	{
		bool isTagged = EntityUtility::IsTagged(GameDefine::Tag_Soldier, pEntity);
		targetTag = isTagged ? GameDefine::Tag_Soldier : GameDefine::Tag_Monster;
	}
	else
	{
		bool isTagged = EntityUtility::IsTagged(GameDefine::Tag_Soldier, pEntity);
		targetTag = isTagged ? GameDefine::Tag_Monster : GameDefine::Tag_Soldier;
	}
	entity_map& activities = ECSWorld::GetSingleton()->GetEntitiesByTag(targetTag);
	if (activities.size() == 0)
		return Entity::InvalidID;

	for (auto& it : activities)
	{
		Entity* pEnemyEntity = it.second;
		if ((!includeSelf) && pEnemyEntity->GetId() == pEntity->GetId())
			continue;

		/*if (enemyAttCom && enemyAttCom->GetBlackboard()->GetAttr(AttrType::HP)<= 0)
		continue;*/

		ComTransform* enePosCom = pEnemyEntity->GetComponent<ComTransform>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < myTempCom->m_roleCfg->viewRange)
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

void EntityUtility::FindTargetsInScope(int entityID, int scopeSize, bool sameTeam, bool includeSelf, std::vector<int>& eneityIDList)
{
	Entity* pEntity = ECSWorld::GetSingleton()->GetEntity(entityID);
	ComTransform* myPosCom = pEntity->GetComponent<ComTransform>();

	std::string targetTag;
	if (sameTeam)
	{
		bool isTagged = EntityUtility::IsTagged(GameDefine::Tag_Soldier, pEntity);
		targetTag = isTagged ? GameDefine::Tag_Soldier : GameDefine::Tag_Monster;
	}
	else
	{
		bool isTagged = EntityUtility::IsTagged(GameDefine::Tag_Soldier, pEntity);
		targetTag = isTagged ? GameDefine::Tag_Monster : GameDefine::Tag_Soldier;
	}

	entity_map& activities = ECSWorld::GetSingleton()->GetEntitiesByTag(targetTag);
	for (auto& it : activities)
	{
		Entity* pEnemyEntity = it.second;
		ComPawnAgent* enemyAttCom = pEnemyEntity->GetComponent<ComPawnAgent>();
		ComTransform* enePosCom = pEnemyEntity->GetComponent<ComTransform>();
		Point2D vecBetween(myPosCom->x - enePosCom->x, myPosCom->y - enePosCom->y);
		float len = vecBetween.Length();
		if (len < scopeSize)
		{
			eneityIDList.push_back(pEnemyEntity->GetId());
		}
	}
}


int EntityUtility::FindRandTargetByTag(const string& tag)
{
	int tarEntityID = Entity::InvalidID;

	entity_map& activities = ECSWorld::GetSingleton()->GetEntitiesByTag(tag);
	for (auto& it : activities)
	{
		tarEntityID = it.second->GetId();
		break;
	}

	return tarEntityID;
}
