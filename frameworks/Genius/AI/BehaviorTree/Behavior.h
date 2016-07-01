#pragma once

#include "../AIBaseDef.h"
#include "Precondition.h"

namespace tinyxml2
{
	class XMLElement;
};

using namespace tinyxml2;
using namespace Genius;

AI_NS_BEGIN
BHTREE_NS_BEGIN

typedef Genius::AnyData BHUpdateContext;

enum eBehaviorStatus
{
	BH_Invalid,
	BH_Running,
	BH_Success,
	BH_Aborted,
	BH_Failed,
};

#define InvalidChildIndex -1
#define MaxChildrenNum 16

/**
 *	Behavior, base class of behavior node.
 */
class Behavior
{
public:
	virtual eBehaviorStatus Update(BHUpdateContext& context) = 0;
	virtual void OnInitialize(BHUpdateContext& context){}
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state){}
	virtual void OnAbort(BHUpdateContext& context){ Abort(context); }
	virtual void AddChild(Behavior*){}
	virtual bool LoadFromXml(XMLElement* xml){ return true; }

	Behavior() : 
		m_eStatus(BH_Invalid),
		m_pPrecondition(nullptr)
	{}

	virtual ~Behavior()
	{
		if (m_pPrecondition)
			delete m_pPrecondition;
	}

	eBehaviorStatus Tick(BHUpdateContext& context);

	void Reset()
	{
		m_eStatus = BH_Invalid; 
	}

	void Abort(BHUpdateContext& context)
	{
		OnTerminate(context, BH_Aborted);
		m_eStatus = BH_Aborted;
	}

	eBehaviorStatus GetStatus()
	{
		return m_eStatus; 
	}
	bool IsRunning()
	{
		return m_eStatus == BH_Running;
	}
	bool IsTermanated()
	{
		return m_eStatus == BH_Success || m_eStatus == BH_Failed;
	}

	void SetPrecondition(Precondition* pre)
	{
		m_pPrecondition = pre;
	}

private:
	eBehaviorStatus		m_eStatus;
	Precondition*			m_pPrecondition;
};

/**
 *	Composite, base class of composite node.
 */
class Composite : public Behavior
{
public:
	Composite();
	virtual ~Composite();
	void AddChild(Behavior* child);

protected:
	bool IsNodeVaild(int index)
	{
		return index > InvalidChildIndex && index < MaxChildrenNum && m_children[index];
	}

protected:
	Behavior*		m_children[MaxChildrenNum];
	int				m_activeChildIndex;
};

/**
 *	Decorator, base class of decorator node.
 */
class Decorator : public Behavior
{
protected:
	Behavior*		m_pChild;

public:
	Decorator(Behavior* child) : m_pChild(){}
};

/**
 *	Action, base class of action node.
 */
class Action : public Behavior
{
public:
	virtual eBehaviorStatus Update(BHUpdateContext& context){ return BH_Success; };
	virtual void OnInitialize(BHUpdateContext& context){}
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state){}
};

/**
*	Sequence, base class of sequence node.
*/
class Sequence : public Composite
{
	typedef Behavior Super;
public:
	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual void OnAbort(BHUpdateContext& context);
};

/**
*	Selector, base class of selector node.
*/
class Selector : public Composite
{
	typedef Behavior Super;
public:
	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual void OnAbort(BHUpdateContext& context);
};

/**
*	Parallel, base class of parallel node.
*/
class Parallel : public Composite
{
	typedef Behavior Super;
public:
	enum ePolicy
	{
		RequireOne,
		RequireAll,
	};

	Parallel(ePolicy successPolicy, ePolicy failurePolicy)
		: m_eSuccessPolicy(successPolicy),
		m_eFailurePolicy(failurePolicy)
	{}

	virtual eBehaviorStatus Update(BHUpdateContext& context);
	virtual void OnInitialize(BHUpdateContext& context);
	virtual void OnTerminate(BHUpdateContext& context, eBehaviorStatus state);
	virtual void OnAbort(BHUpdateContext& context);

protected:
	ePolicy			m_eSuccessPolicy;
	ePolicy			m_eFailurePolicy;
};

BH_TREE_NS_END
AI_NS_END