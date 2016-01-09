// d:)
#include "Precondition.h"


AI_NS_BEGIN
BHTREE_NS_BEGIN

bool PreconditionAnd::Check(BHUpdateContext& context)
{
	return m_pPrecondition1 && m_pPrecondition1->Check(context)
		&& m_pPrecondition2 && m_pPrecondition2->Check(context);
}

void PreconditionAnd::AddChild(Precondition* child)
{
	if (nullptr == m_pPrecondition1)
		m_pPrecondition1 = child;
	else if (nullptr == m_pPrecondition2)
		m_pPrecondition2 = child;
	/*else
		printf("pre and :too much child\n");*/
}

PreconditionAnd::~PreconditionAnd()
{
	if (m_pPrecondition1)
		delete m_pPrecondition1;
	if (m_pPrecondition2)
		delete m_pPrecondition2;
}

bool PreconditionOr::Check(BHUpdateContext& context)
{
	return (m_pPrecondition1 && m_pPrecondition1->Check(context))
		|| (m_pPrecondition2 && m_pPrecondition2->Check(context));
}

void PreconditionOr::AddChild(Precondition* child)
{
	if (nullptr == m_pPrecondition1)
		m_pPrecondition1 = child;
	else if (nullptr == m_pPrecondition2)
		m_pPrecondition2 = child;
	/*else
		printf("pre or :too much child\n");*/
}

PreconditionOr::~PreconditionOr()
{
	if (m_pPrecondition1)
		delete m_pPrecondition1;
	if (m_pPrecondition2)
		delete m_pPrecondition2;
}

bool PreconditionNot::Check(BHUpdateContext& context)
{
	return m_pPrecondition && ! m_pPrecondition->Check(context);
}

void PreconditionNot::AddChild(Precondition* child)
{
	if (nullptr == m_pPrecondition)
		m_pPrecondition = child;
	/*else
		printf("pre not :too much child\n");*/
}

PreconditionNot::~PreconditionNot()
{
	if (m_pPrecondition)
		delete m_pPrecondition;
}

BH_TREE_NS_END
AI_NS_END