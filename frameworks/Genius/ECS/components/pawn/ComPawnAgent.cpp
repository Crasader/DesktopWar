
#include "ComPawnAgent.h"
#include "data/auto/Role_cfg.hpp"
#include "pawn/PawnBlackboard.h"
#include "pawn/action/PawnActionFactory.h"


using namespace Genius;
using namespace cfg;

ComPawnAgent::ComPawnAgent(Role_cfg* pData)
{
	m_roleCfg = pData;

	m_pBlackboard = new PawnBlackboard(this);
}

ComPawnAgent::~ComPawnAgent()
{
	if (m_pBlackboard)
		delete m_pBlackboard;
}

void ComPawnAgent::AddAction(int type)
{
	if (m_pBlackboard != nullptr)
	{
		PawnAction* pAction = PawnActionFactory::GetSingleton()->CreatePawnAction(type);

		m_pBlackboard->AddAction(pAction);
	}
}