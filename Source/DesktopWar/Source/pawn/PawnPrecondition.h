#pragma once
#include "AI/AI.h"

USING_NS_AI
USING_NS_BHTREE;

class Actor;

// probablity > 0 ?
class Probablity : public Precondition
{
public:
	Probablity() :
		value(1),
		randomValue(0),
		checked(false)
	{}
	virtual ~Probablity(){}
	virtual bool Check(BHUpdateContext& context);
	virtual void Reset();

public:
	float value;
	float randomValue;
	bool checked;			// for ensure randomValue is calculated only once.
};

// hp > 0 ?
class HaveHP : public Precondition
{
public:
	virtual ~HaveHP(){}
	virtual bool Check(BHUpdateContext& context);
};


// hp < fullHp*percent ?
class LowHP : public Precondition
{
public:
	LowHP() :value(0){}
	virtual ~LowHP(){}
	virtual bool Check(BHUpdateContext& context);

public:
	float		value;
};

// hp >= fullHp*percent ?
class HighHP : public Precondition
{
public:
	HighHP() :value(0){}
	virtual ~HighHP(){}
	virtual bool Check(BHUpdateContext& context);

public:
	float		value;
};


// have ?
class HaveTarget : public Precondition
{
public:
	virtual ~HaveTarget(){}
	virtual bool Check(BHUpdateContext& context);
};


// reach ?
class ReachTarget : public Precondition
{
public:
	virtual ~ReachTarget(){}
	virtual bool Check(BHUpdateContext& context);
};


// in ?
class TargetInNearRange : public Precondition
{
public:
	virtual ~TargetInNearRange(){}
	virtual bool Check(BHUpdateContext& context);
};


// in ?
class TargetInFarRange : public Precondition
{
public:
	virtual ~TargetInFarRange(){}
	virtual bool Check(BHUpdateContext& context);
};


