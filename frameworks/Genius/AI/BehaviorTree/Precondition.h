#pragma once
#include "../AIBaseDef.h"



using namespace Genius;

AI_NS_BEGIN
BHTREE_NS_BEGIN

typedef Genius::AnyData BHUpdateContext;

/**
*	Precondition, base class of Precondition.
*/
class Precondition
{
public:
	virtual ~Precondition(){}
	virtual bool Check(BHUpdateContext& context) = 0;
	virtual void AddChild(Precondition*){}
	virtual void Reset(){};
};

class PreconditionTrue : public Precondition
{
public:
	virtual bool Check(BHUpdateContext& context){ return true; }
};

class PreconditionAnd : public Precondition
{
public:
	PreconditionAnd(Precondition* c1, Precondition* c2) :
		m_pPrecondition1(c1),
		m_pPrecondition2(c2)
	{}
	PreconditionAnd() :
		m_pPrecondition1(nullptr),
		m_pPrecondition2(nullptr)
	{}
	virtual ~PreconditionAnd();
	virtual bool Check(BHUpdateContext& context);
	virtual void AddChild(Precondition*);

private:
	Precondition*		m_pPrecondition1;
	Precondition*		m_pPrecondition2;
};

class PreconditionOr : public Precondition
{
public:
	PreconditionOr(Precondition* c1, Precondition* c2) :
		m_pPrecondition1(c1),
		m_pPrecondition2(c2)
	{}
	PreconditionOr() :
		m_pPrecondition1(nullptr),
		m_pPrecondition2(nullptr)
	{}
	virtual ~PreconditionOr();
	virtual bool Check(BHUpdateContext& context);
	virtual void AddChild(Precondition*);

private:
	Precondition*		m_pPrecondition1;
	Precondition*		m_pPrecondition2;
};

class PreconditionNot : public Precondition
{
public:
	PreconditionNot(Precondition* c1) :
		m_pPrecondition(c1)
	{}
	PreconditionNot() :
		m_pPrecondition(nullptr)
	{}
	virtual ~PreconditionNot();
	virtual bool Check(BHUpdateContext& context);
	virtual void AddChild(Precondition*);

private:
	Precondition*		m_pPrecondition;
};

BH_TREE_NS_END
AI_NS_END
