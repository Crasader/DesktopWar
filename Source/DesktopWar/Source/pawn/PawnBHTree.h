#pragma once
#include "AI/AI.h"

class PawnBHTree : public AI::BHTree::BehaviorTree
{
public:
	virtual bool CreateTree(const char* fileName);
};