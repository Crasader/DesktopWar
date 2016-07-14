
#include "ComPawnAgent.h"
#include "data/ConfigPool.h"
#include "data/auto/Role_cfg.hpp"
#include "pawn/PawnBlackboard.h"
#include "pawn/action/PawnActionFactory.h"
#include "common/Log.h"


using namespace Genius;
using namespace cfg;

void ComPawnAgent::Create(int roleCfgID)
{
	m_roleCfg = FIND_CFG(Role_cfg, roleCfgID);

	if (nullptr == m_roleCfg)
	{
		Log::Error("ComPawnAgent::Create : wrong roleCfgID %d", roleCfgID);
	}

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