#ifndef _BEHAVIOR_CREATORS_H_
#define _BEHAVIOR_CREATORS_H_

#include "AI/AI.h"

USING_NS_AI
USING_NS_BHTREE

class TiXmlElement;

/************************************************************************/
/*                                               behaviors							                       */
/************************************************************************/
Behavior* CreateSelector(TiXmlElement* xml);
Behavior* CreateSequence(TiXmlElement* xml);
Behavior* CreateParallel(TiXmlElement* xml);

/************************************************************************/
/*                                               Preconditions							                       */
/************************************************************************/
Precondition* CreateTRUE(TiXmlElement* xml);
Precondition* CreateNOT(TiXmlElement* xml);
Precondition* CreateAND(TiXmlElement* xml);
Precondition* CreateOR(TiXmlElement* xml);

/************************************************************************/
/*                                               user behaviors							                       */
/************************************************************************/
/*Behavior* CreateSheepIdle(TiXmlElement* xml);
Behavior* CreateSheepEat(TiXmlElement* xml);
Behavior* CreateSheepDie(TiXmlElement* xml);*/
Behavior* CreatePawnIdle(TiXmlElement* xml);
Behavior* CreatePawnWander(TiXmlElement* xml);
Behavior* CreatePawnChase(TiXmlElement* xml);
Behavior* CreatePawnAttackNear(TiXmlElement* xml);
Behavior* CreatePawnAttackNear2(TiXmlElement* xml);
Behavior* CreatePawnAttackFar(TiXmlElement* xml);
Behavior* CreatePawnMove(TiXmlElement* xml);
Behavior* CreatePawnDie(TiXmlElement* xml);
Behavior* CreatePawnSkill1(TiXmlElement* xml);
Behavior* CreatePawnSkill2(TiXmlElement* xml);
Behavior* CreatePawnSkill3(TiXmlElement* xml);

/************************************************************************/
/*                                               user preconditions							             */
/************************************************************************/
Precondition* CreateProbablity(TiXmlElement* xml);
Precondition* CreateHaveHP(TiXmlElement* xml);
Precondition* CreateLowHP(TiXmlElement* xml);
Precondition* CreateHighHP(TiXmlElement* xml);
Precondition* CreateHaveTarget(TiXmlElement* xml);
Precondition* CreateReachTarget(TiXmlElement* xml);
Precondition* CreateTargetInNearRange(TiXmlElement* xml);
Precondition* CreateTargetInFarRange(TiXmlElement* xml);

#endif