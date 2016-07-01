
#include <string>
#include "tinyxml2.h"
#include "BehaviorCreators.h"
//
#include "PawnBehaviors.h"
#include "PawnPrecondition.h"

using namespace tinyxml2;

/************************************************************************/
/*                                               basic behaviors							                     */
/************************************************************************/
Behavior* CreateSelector(XMLElement* xml)
{
	Selector* pBehavior = new Selector;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreateSequence(XMLElement* xml)
{
	Sequence* pBehavior = new Sequence;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreateParallel(XMLElement* xml)
{
	Parallel::ePolicy success = Parallel::RequireAll;
	Parallel::ePolicy failure = Parallel::RequireOne;
	std::string successPolicy = xml->Attribute("successPolicy");
	std::string failurePolicy = xml->Attribute("failurePolicy");
	if (successPolicy == "RequireAll")
		success = Parallel::RequireAll;
	else if (successPolicy == "RequireOne")
		success = Parallel::RequireOne;
	if (failurePolicy == "RequireAll")
		failure = Parallel::RequireAll;
	else if (failurePolicy == "RequireOne")
		failure = Parallel::RequireOne;

	Parallel* pBehavior = new Parallel(success, failure);
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

/************************************************************************/
/*                                               basic preconditions					                    */
/************************************************************************/
Precondition* CreateTRUE(XMLElement* xml)
{
	PreconditionTrue* precondition = new PreconditionTrue;
	return precondition;
}

Precondition* CreateNOT(XMLElement* xml)
{
	PreconditionNot* precondition = new PreconditionNot();
	return precondition;
}

Precondition* CreateAND(XMLElement* xml)
{
	PreconditionAnd* precondition = new PreconditionAnd();
	return precondition;
}

Precondition* CreateOR(XMLElement* xml)
{
	PreconditionOr* precondition = new PreconditionOr();
	return precondition;
}

/************************************************************************/
/*                                               user behaviors							                     */
/************************************************************************/
/*Behavior* CreateSheepIdle(XMLElement* xml)
{
	SheepIdle* pBehavior = new SheepIdle;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreateSheepEat(XMLElement* xml)
{
	SheepEat* pBehavior = new SheepEat;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreateSheepDie(XMLElement* xml)
{
	SheepDie* pBehavior = new SheepDie;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}*/

Behavior* CreatePawnIdle(XMLElement* xml)
{
	PawnIdle* pBehavior = new PawnIdle;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnWander(XMLElement* xml)
{
	PawnWander* pBehavior = new PawnWander;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnChase(XMLElement* xml)
{
	PawnChase* pBehavior = new PawnChase;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnAttackNear(XMLElement* xml)
{
	PawnAttackNear* pBehavior = new PawnAttackNear;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnAttackNear2(XMLElement* xml)
{
	PawnAttackNear2* pBehavior = new PawnAttackNear2;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnAttackFar(XMLElement* xml)
{
	PawnAttackFar* pBehavior = new PawnAttackFar;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnMove(XMLElement* xml)
{
	PawnMove* pBehavior = new PawnMove;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnDie(XMLElement* xml)
{
	PawnDie* pBehavior = new PawnDie;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnSkill1(XMLElement* xml)
{
	PawnSkill1* pBehavior = new PawnSkill1;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnSkill2(XMLElement* xml)
{
	PawnSkill2* pBehavior = new PawnSkill2;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnSkill3(XMLElement* xml)
{
	PawnSkill3* pBehavior = new PawnSkill3;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

/************************************************************************/
/*                                               user behaviors					     */
/************************************************************************/

Precondition* CreateProbablity(XMLElement* xml)
{
	Probablity* precondition = new Probablity();
	float value = (float)atof(xml->Attribute("value"));
	precondition->value = value;
	return precondition;
}


Precondition* CreateHaveHP(XMLElement* xml)
{
	HaveHP* precondition = new HaveHP();
	return precondition;
}


Precondition* CreateLowHP(XMLElement* xml)
{
	LowHP* precondition = new LowHP();
	float value = (float)atof(xml->Attribute("value"));
	precondition->value = value;
	return precondition;
}


Precondition* CreateHighHP(XMLElement* xml)
{
	HighHP* precondition = new HighHP();
	float value = (float)atof(xml->Attribute("value"));
	precondition->value = value;
	return precondition;
}


Precondition* CreateHaveTarget(XMLElement* xml)
{
	HaveTarget* precondition = new HaveTarget();
	return precondition;
}


Precondition* CreateReachTarget(XMLElement* xml)
{
	ReachTarget* precondition = new ReachTarget();
	return precondition;
}


Precondition* CreateTargetInNearRange(XMLElement* xml)
{
	TargetInNearRange* precondition = new TargetInNearRange();
	return precondition;
}


Precondition* CreateTargetInFarRange(XMLElement* xml)
{
	TargetInFarRange* precondition = new TargetInFarRange();
	return precondition;
}











