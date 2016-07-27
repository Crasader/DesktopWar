
#include "WorldWrapper.h"
#include "EntityWrapper.h"
#include "ECS/ecs.h"
#include "common/Log.h"

using namespace Genius;

WorldWrapper* WorldWrapper::GetWorld()
{
	return WorldWrapper::GetSingleton();
}


EntityWrapper* WorldWrapper::CreateEntity()
{
	Entity* ent = ECSWorld::GetSingleton()->CreateEntity();
	ent->Refresh();
	EntityWrapper* entWrapper = new EntityWrapper(ent);

	entityMap[ent->GetId()] = entWrapper;

	return entWrapper;
}

void WorldWrapper::DestroyEntity(EntityWrapper* ent)
{
	if (nullptr == ent)
	{
		Log::Warning("try destroy null entity wrapper.");
		return;
	}

	auto itFind = entityMap.find(ent->GetID());
	if (itFind != entityMap.end())
	{
		entityMap.erase(itFind);
		ent->OnDestroy();
		delete ent;
	}

}

