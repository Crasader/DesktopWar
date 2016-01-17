
#include "SystemPawnBevtree.h"
#include "pawn/bevtree/PawnBHTree.h"

using namespace Genius;

void SystemPawnBevtree::Initialize()
{
	bevtreeMapper.init(*world);
}

void SystemPawnBevtree::ProcessEntity(Entity* e)
{
	EntityBevInputData inputData;
	inputData.pEntity = e;
	inputData.timeDelta = world->GetDeltaTime();
	AI::BHTree::BHUpdateContext context(&inputData);
	bevtreeMapper.get(e)->m_tree->Tick(context);
}

bool SystemPawnBevtree::HandleEvent(IEventData const &event)
{
	return true;
}