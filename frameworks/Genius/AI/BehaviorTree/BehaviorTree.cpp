
#include "BehaviorTree.h"

AI_NS_BEGIN
BHTREE_NS_BEGIN

bool BehaviorTree::Init(const char* tree_name)
{
	return CreateTree(tree_name);
}

void BehaviorTree::Tick(BHUpdateContext& context)
{
	if (m_pRoot)
		m_pRoot->Tick(context);
}

void BehaviorTree::Destroy()
{
	if (m_pRoot)
	{
		delete m_pRoot;
		m_pRoot = nullptr;
	}
}

BH_TREE_NS_END
AI_NS_END
