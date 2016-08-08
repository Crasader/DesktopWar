
#pragma once


#include <string>
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

};

