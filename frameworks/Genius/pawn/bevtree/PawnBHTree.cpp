
#include "PawnBHTree.h"
#include "PawnPrecondition.h"
#include "AI/BehaviorTree/BehaviorLoader.h"


USING_NS_AI
USING_NS_BHTREE

bool PawnBHTree::CreateTree(const char* fileName)
{
	Behavior* root = BehaviorLoader::GetInstance().LoadFromXml(fileName);
	SetRoot(root);

	return true;
}