
#include "WorldWrapper.h"
#include "EntityWrapper.h"
#include "ECS/ecs.h"


using namespace Genius;

WorldWrapper* WorldWrapper::GetWorld()
{
	return WorldWrapper::GetSingleton();
}


EntityWrapper* WorldWrapper::CreateEntity()
{
	Entity* ent = ECSWorld::GetSingleton()->CreateEntity();
	EntityWrapper* entWrapper = new EntityWrapper(ent);

	entityMap[ent->GetId()] = entWrapper;

	return entWrapper;
}



