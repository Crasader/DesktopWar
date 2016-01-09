// d:)
#include <string>
#include "tinyxml.h"
#include "BehaviorCreators.h"
//
#include "PawnBehaviors.h"
#include "PawnPrecondition.h"


/************************************************************************/
/*                                               basic behaviors							                     */
/************************************************************************/
Behavior* CreateSelector(TiXmlElement* xml)
{
	Selector* pBehavior = new Selector;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreateSequence(TiXmlElement* xml)
{
	Sequence* pBehavior = new Sequence;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreateParallel(TiXmlElement* xml)
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
Precondition* CreateTRUE(TiXmlElement* xml)
{
	PreconditionTrue* precondition = new PreconditionTrue;
	return precondition;
}

Precondition* CreateNOT(TiXmlElement* xml)
{
	PreconditionNot* precondition = new PreconditionNot();
	return precondition;
}

Precondition* CreateAND(TiXmlElement* xml)
{
	PreconditionAnd* precondition = new PreconditionAnd();
	return precondition;
}

Precondition* CreateOR(TiXmlElement* xml)
{
	PreconditionOr* precondition = new PreconditionOr();
	return precondition;
}

/************************************************************************/
/*                                               user behaviors							                     */
/************************************************************************/
/*Behavior* CreateSheepIdle(TiXmlElement* xml)
{
	SheepIdle* pBehavior = new SheepIdle;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreateSheepEat(TiXmlElement* xml)
{
	SheepEat* pBehavior = new SheepEat;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreateSheepDie(TiXmlElement* xml)
{
	SheepDie* pBehavior = new SheepDie;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}*/

Behavior* CreatePawnIdle(TiXmlElement* xml)
{
	PawnIdle* pBehavior = new PawnIdle;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnWander(TiXmlElement* xml)
{
	PawnWander* pBehavior = new PawnWander;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnChase(TiXmlElement* xml)
{
	PawnChase* pBehavior = new PawnChase;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnAttackNear(TiXmlElement* xml)
{
	PawnAttackNear* pBehavior = new PawnAttackNear;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnAttackNear2(TiXmlElement* xml)
{
	PawnAttackNear2* pBehavior = new PawnAttackNear2;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnAttackFar(TiXmlElement* xml)
{
	PawnAttackFar* pBehavior = new PawnAttackFar;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnMove(TiXmlElement* xml)
{
	PawnMove* pBehavior = new PawnMove;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnDie(TiXmlElement* xml)
{
	PawnDie* pBehavior = new PawnDie;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnSkill1(TiXmlElement* xml)
{
	PawnSkill1* pBehavior = new PawnSkill1;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnSkill2(TiXmlElement* xml)
{
	PawnSkill2* pBehavior = new PawnSkill2;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

Behavior* CreatePawnSkill3(TiXmlElement* xml)
{
	PawnSkill3* pBehavior = new PawnSkill3;
	pBehavior->LoadFromXml(xml);
	return pBehavior;
}

/************************************************************************/
/*                                               user behaviors					     */
/************************************************************************/

Precondition* CreateProbablity(TiXmlElement* xml)
{
	Probablity* precondition = new Probablity();
	float value = (float)atof(xml->Attribute("value"));
	precondition->value = value;
	return precondition;
}


Precondition* CreateHaveHP(TiXmlElement* xml)
{
	HaveHP* precondition = new HaveHP();
	return precondition;
}


Precondition* CreateLowHP(TiXmlElement* xml)
{
	LowHP* precondition = new LowHP();
	float value = (float)atof(xml->Attribute("value"));
	precondition->value = value;
	return precondition;
}


Precondition* CreateHighHP(TiXmlElement* xml)
{
	HighHP* precondition = new HighHP();
	float value = (float)atof(xml->Attribute("value"));
	precondition->value = value;
	return precondition;
}


Precondition* CreateHaveTarget(TiXmlElement* xml)
{
	HaveTarget* precondition = new HaveTarget();
	return precondition;
}


Precondition* CreateReachTarget(TiXmlElement* xml)
{
	ReachTarget* precondition = new ReachTarget();
	return precondition;
}


Precondition* CreateTargetInNearRange(TiXmlElement* xml)
{
	TargetInNearRange* precondition = new TargetInNearRange();
	return precondition;
}


Precondition* CreateTargetInFarRange(TiXmlElement* xml)
{
	TargetInFarRange* precondition = new TargetInFarRange();
	return precondition;
}











