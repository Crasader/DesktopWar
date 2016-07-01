#ifndef _BEHAVIOR_CREATORS_H_
#define _BEHAVIOR_CREATORS_H_

#include "AI/AI.h"

USING_NS_AI
USING_NS_BHTREE

namespace tinyxml2
{
	class XMLElement;
};

/************************************************************************/
/*                                               behaviors							                       */
/************************************************************************/
Behavior* CreateSelector(XMLElement* xml);
Behavior* CreateSequence(XMLElement* xml);
Behavior* CreateParallel(XMLElement* xml);

/************************************************************************/
/*                                               Preconditions							                       */
/************************************************************************/
Precondition* CreateTRUE(XMLElement* xml);
Precondition* CreateNOT(XMLElement* xml);
Precondition* CreateAND(XMLElement* xml);
Precondition* CreateOR(XMLElement* xml);

/************************************************************************/
/*                                               user behaviors							                       */
/************************************************************************/
/*Behavior* CreateSheepIdle(XMLElement* xml);
Behavior* CreateSheepEat(XMLElement* xml);
Behavior* CreateSheepDie(XMLElement* xml);*/
Behavior* CreatePawnIdle(XMLElement* xml);
Behavior* CreatePawnWander(XMLElement* xml);
Behavior* CreatePawnChase(XMLElement* xml);
Behavior* CreatePawnAttackNear(XMLElement* xml);
Behavior* CreatePawnAttackNear2(XMLElement* xml);
Behavior* CreatePawnAttackFar(XMLElement* xml);
Behavior* CreatePawnMove(XMLElement* xml);
Behavior* CreatePawnDie(XMLElement* xml);
Behavior* CreatePawnSkill1(XMLElement* xml);
Behavior* CreatePawnSkill2(XMLElement* xml);
Behavior* CreatePawnSkill3(XMLElement* xml);

/************************************************************************/
/*                                               user preconditions							             */
/************************************************************************/
Precondition* CreateProbablity(XMLElement* xml);
Precondition* CreateHaveHP(XMLElement* xml);
Precondition* CreateLowHP(XMLElement* xml);
Precondition* CreateHighHP(XMLElement* xml);
Precondition* CreateHaveTarget(XMLElement* xml);
Precondition* CreateReachTarget(XMLElement* xml);
Precondition* CreateTargetInNearRange(XMLElement* xml);
Precondition* CreateTargetInFarRange(XMLElement* xml);

#endif