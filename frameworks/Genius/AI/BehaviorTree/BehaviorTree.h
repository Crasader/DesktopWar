#pragma once
#include "../AIBaseDef.h"
#include "Behavior.h"

AI_NS_BEGIN
BHTREE_NS_BEGIN

typedef AnyData BHUpdateContext;

class BehaviorTree
{
public:
	BehaviorTree() :m_pRoot(nullptr){}
	virtual ~BehaviorTree(){}

	bool Init(const char* tree_name);
	void Tick(BHUpdateContext& context);
	void Destroy();

	virtual bool CreateTree(const char* fileName) = 0;
	void SetRoot(Behavior* root){ m_pRoot = root; }

private:
	Behavior*		m_pRoot;
};


BH_TREE_NS_END
AI_NS_END