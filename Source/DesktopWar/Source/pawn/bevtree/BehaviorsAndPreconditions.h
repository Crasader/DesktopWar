#ifndef _GENIUS_BEV_AND_PRE_H
#define _GENIUS_BEV_AND_PRE_H

#include "AI/BehaviorTree/BehaviorLoader.h"
#include "BehaviorCreators.h"

using namespace Genius;

AI::BHTree::BehaviorCreatorMap gBehaviorMap[] =
{
	AI::BHTree::BehaviorCreatorMap("Selector", CreateSelector),
	AI::BHTree::BehaviorCreatorMap("Sequence", CreateSequence),
	AI::BHTree::BehaviorCreatorMap("Parallel", CreateParallel),
	// user def
	/*AI::BHTree::BehaviorCreatorMap("SheepIdle", CreateSheepIdle),
	AI::BHTree::BehaviorCreatorMap("SheepEat", CreateSheepEat),
	AI::BHTree::BehaviorCreatorMap("SheepDie", CreateSheepDie),
	*/
	AI::BHTree::BehaviorCreatorMap("PawnIdle", CreatePawnIdle),
	AI::BHTree::BehaviorCreatorMap("PawnMove", CreatePawnMove),
	AI::BHTree::BehaviorCreatorMap("PawnDie", CreatePawnDie),
	AI::BHTree::BehaviorCreatorMap("PawnWander", CreatePawnWander),
	AI::BHTree::BehaviorCreatorMap("PawnChase", CreatePawnChase),

	AI::BHTree::BehaviorCreatorMap("PawnAttackNear", CreatePawnAttackNear),
	AI::BHTree::BehaviorCreatorMap("PawnAttackNear2", CreatePawnAttackNear2),
	AI::BHTree::BehaviorCreatorMap("PawnAttackFar", CreatePawnAttackFar),
	
	AI::BHTree::BehaviorCreatorMap("PawnSkill1", CreatePawnSkill1),
	AI::BHTree::BehaviorCreatorMap("PawnSkill2", CreatePawnSkill2),
	AI::BHTree::BehaviorCreatorMap("PawnSkill3", CreatePawnSkill3),

	AI::BHTree::BehaviorCreatorMap("", nullptr),
};

AI::BHTree::PreconditionCreatorMap gPreconditionMap[] =
{
	// reg precondition
	AI::BHTree::PreconditionCreatorMap("TRUE", CreateTRUE),
	AI::BHTree::PreconditionCreatorMap("NOT", CreateNOT),
	AI::BHTree::PreconditionCreatorMap("AND", CreateAND),
	AI::BHTree::PreconditionCreatorMap("OR", CreateOR),

	// user def
	AI::BHTree::PreconditionCreatorMap("Probablity", CreateProbablity),
	AI::BHTree::PreconditionCreatorMap("HaveHP", CreateHaveHP),
	AI::BHTree::PreconditionCreatorMap("LowHP", CreateLowHP),
	AI::BHTree::PreconditionCreatorMap("HighHP", CreateHighHP),
	AI::BHTree::PreconditionCreatorMap("HaveTarget", CreateHaveTarget),
	AI::BHTree::PreconditionCreatorMap("ReachTarget", CreateReachTarget),
	AI::BHTree::PreconditionCreatorMap("TargetInNearRange", CreateTargetInNearRange),
	AI::BHTree::PreconditionCreatorMap("TargetInFarRange", CreateTargetInFarRange),
	AI::BHTree::PreconditionCreatorMap("", nullptr),

};


#endif