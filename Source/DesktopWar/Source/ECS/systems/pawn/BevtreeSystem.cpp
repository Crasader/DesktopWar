// d:)
#include "BevtreeSystem.h"
#include "pawn/PawnBHTree.h"

using namespace Genius;

void BevtreeSystem::Initialize()
{
	bevtreeMapper.init(*world);
}

void BevtreeSystem::ProcessEntity(Entity* e)
{
	EntityBevInputData inputData;
	inputData.pEntity = e;
	inputData.timeDelta = world->GetDeltaTime();
	AI::BHTree::BHUpdateContext context(&inputData);
	bevtreeMapper.get(e)->m_tree->Tick(context);
}

bool BevtreeSystem::HandleEvent(IEventData const &event)
{
	return true;
}