
// d:)
#include "../AI.h"
#include "BehaviorTree.h"

AI_NS_BEGIN
BHTREE_NS_BEGIN

/************************************************************************/
/*                                Behavior                                      */
/************************************************************************/
eBehaviorStatus Behavior::Tick(BHUpdateContext& context)
{
	if (nullptr != m_pPrecondition)
	{
		if (m_eStatus != BH_Running)
			m_pPrecondition->Reset();

		if (!m_pPrecondition->Check(context))
		{
			if (m_eStatus == BH_Running)
			{
				OnAbort(context);
			}
			m_eStatus = BH_Failed;
			return m_eStatus;
		}
	}
	if (m_eStatus != BH_Running)
		OnInitialize(context);
	m_eStatus = Update(context);
	if (m_eStatus != BH_Running)
		OnTerminate(context, m_eStatus);
	return m_eStatus;
}

/************************************************************************/
/*                                Composite                                      */
/************************************************************************/
Composite::Composite()
{
	for (int i = 0; i < MaxChildrenNum; ++i)
	{
		m_children[i] = nullptr;
	}
	m_activeChildIndex = InvalidChildIndex;
}

Composite::~Composite()
{
	for (int i = 0; i < MaxChildrenNum; ++i)
	{
		if (m_children[i] )
			delete m_children[i];
	}
}

void Composite::AddChild(Behavior* child)
{
	if (child != nullptr)
	{
		for (int i = 0; i < MaxChildrenNum; ++i)
		{
			if (IsNodeVaild(i))
				continue;
			m_children[i] = child;
			break;
		}
	}
}

/************************************************************************/
/*                                      Sequence                                */
/************************************************************************/
void Sequence::OnInitialize(BHUpdateContext& context)
{
	m_activeChildIndex = 0;
}

void Sequence::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_activeChildIndex = 0;
}

eBehaviorStatus Sequence::Update(BHUpdateContext& context)
{
	if (IsNodeVaild(m_activeChildIndex))
	{
		eBehaviorStatus ret = m_children[m_activeChildIndex]->Tick(context);
		if (ret != BH_Success)
		{	
			return ret;
		}
		else
		{
			m_activeChildIndex++;
			if (false == IsNodeVaild(m_activeChildIndex))
				return BH_Success;
			else
				return BH_Running;
		}
	}
	return BH_Success;
}

void Sequence::OnAbort(BHUpdateContext& context)
{
	if (IsNodeVaild(m_activeChildIndex))
	{
		m_children[m_activeChildIndex]->OnAbort(context);
	}
	this->Abort(context);
}

/************************************************************************/
/*                                      Selector                                */
/************************************************************************/
void Selector::OnInitialize(BHUpdateContext& context)
{
	m_activeChildIndex = InvalidChildIndex;
}

void Selector::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_activeChildIndex = InvalidChildIndex;
}

eBehaviorStatus Selector::Update(BHUpdateContext& context)
{
	for (int i = 0; i < MaxChildrenNum; ++i)
	{
		if (false == IsNodeVaild(i))
			continue;
		eBehaviorStatus ret = m_children[i]->Tick(context);
		if (ret != BH_Failed)
		{
			if (i != m_activeChildIndex && IsNodeVaild(m_activeChildIndex))
			{
				m_children[m_activeChildIndex]->OnAbort(context);
			}
			m_activeChildIndex = i;
			return ret;
		}
	}
	return BH_Failed;
}

void Selector::OnAbort(BHUpdateContext& context)
{
	if (IsNodeVaild(m_activeChildIndex))
	{
		m_children[m_activeChildIndex]->OnAbort(context);
	}
	this->Abort(context);
}

/************************************************************************/
/*                                      Parallel                                */
/************************************************************************/
void Parallel::OnInitialize(BHUpdateContext& context)
{

}

void Parallel::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	for (int i = 0; i < MaxChildrenNum; ++i)
	{
		if (false == IsNodeVaild(i))
			continue;
		m_children[i]->Abort(context);
	}
}

eBehaviorStatus Parallel::Update(BHUpdateContext& context)
{
	unsigned int successCount = 0;
	unsigned int failureCount = 0;
	unsigned int childrenCount = 0;
	for (int i = 0; i < MaxChildrenNum; ++i)
	{
		if (false == IsNodeVaild(i))
			continue;
		
		childrenCount++;
		eBehaviorStatus ret = m_children[i]->Tick(context);
		if (BH_Success == ret)
		{
			successCount++;
			if (m_eSuccessPolicy == RequireOne)
				return BH_Success;
		}

		if (BH_Failed == ret)
		{
			failureCount++;
			if (m_eFailurePolicy == RequireOne)
				return BH_Failed;
		}

		if (m_eSuccessPolicy == RequireAll && successCount == childrenCount)
			return BH_Success;
		if (m_eFailurePolicy == RequireAll && failureCount == childrenCount)
			return BH_Failed;
	}
	return BH_Running;
}

void Parallel::OnAbort(BHUpdateContext& context)
{
	for (int i = 0; i < MaxChildrenNum; ++i)
	{
		if (false == IsNodeVaild(i))
			continue;
		m_children[i]->OnAbort(context);
	}
	this->Abort(context);
}

BH_TREE_NS_END
AI_NS_END