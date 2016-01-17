
#include "PawnBlackboard.h"
#include "ECS/components/pawn/ComPawnAgent.h"
#include "action/PawnActionFactory.h"
#include "action/ActionHandler.h"

using namespace Genius;

PawnBlackboard::PawnBlackboard(ComPawnAgent* agent)
{
	m_pAgent = agent;
	m_currentHP = agent->m_pRoleData->baseLife;
}

PawnBlackboard::~PawnBlackboard()
{

}

void PawnBlackboard::Update()
{

}

void PawnBlackboard::AddAction(PawnAction* pAction)
{
	if (nullptr == pAction)
		return;

	m_actionQueue.push(pAction);

	for (auto iter = m_actionHandlers.begin(); iter != m_actionHandlers.end(); ++iter)
	{
		if ((*iter) != nullptr)
		{
			(*iter)->HandleAction(pAction);
		}
	}

}

void PawnBlackboard::FinishAction(PawnAction* pAction)
{
	if (nullptr == pAction)
		return;

	PawnActionFactory::GetSingleton()->RecycleAction(pAction);
}

void PawnBlackboard::AddActionHandler(ActionHandler* pHandler)
{
	bool repeated = false;
	for (auto iter = m_actionHandlers.begin(); iter != m_actionHandlers.end(); ++iter)
	{
		if ((*iter) != nullptr && (*iter) == pHandler)
		{
			repeated = true;
			break;
		}
	}

	if (!repeated)
	{
		m_actionHandlers.push_back(pHandler);
	}
	
}

void PawnBlackboard::RemoveActionHandler(ActionHandler* pHandler)
{
	for (auto iter = m_actionHandlers.begin(); iter != m_actionHandlers.end(); ++iter)
	{
		if ((*iter) != nullptr && (*iter) == pHandler)
		{
			m_actionHandlers.erase(iter);
			break;
		}
	}
}















