

#include "EntityUtility.h"
#include "common/Log.h"
#include "ECS/ecs.h"


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




