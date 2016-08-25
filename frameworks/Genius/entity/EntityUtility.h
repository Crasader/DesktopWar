
#pragma once


#include <string>
#include <vector>
#include "app/GameDefine.h"

namespace Genius
{
	class Entity;
	class EntityWrapper;
}

using namespace Genius;


class EntityUtility
{

public:

	const static std::string& GetEnemyTag(const std::string& myTag);

	static bool IsTagged(const std::string& tag, Entity* entity);

	static bool IsEnemy(Entity* entity1, Entity* entity2);

	static bool AreEntitiesCloseEnough(EntityWrapper* entity1, EntityWrapper* entity2, float distance);

	static bool IsInMyViewSight(EntityWrapper* entity1, EntityWrapper* entity2);

	static bool IsInMyNearRange(EntityWrapper* entity1, EntityWrapper* entity2);

	static bool IsInMyFarRange(EntityWrapper* entity1, EntityWrapper* entity2);

	static int FindNearestTarget(Entity* e, bool sameTeam, bool includeSelf);
	static void FindTargetsInScope(int entityID, int scopeSize, bool sameTeam, bool includeSelf, std::vector<int>& eneityIDList);
	static int FindRandTargetByTag(const std::string& tag);

	static void CreatePawn(int id, float x, float y, const std::string& tag);
	static void CreateBullet(int bulletID, int targetEntityID, float x, float y, const std::string& tag, float destX, float destY);

};

