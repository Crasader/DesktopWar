
#include "ComPawnAgent.h"
#include "data/ConfigPool.h"
#include "data/auto/Role_cfg.hpp"
#include "data/auto/Bullet_cfg.hpp"
#include "pawn/PawnBlackboard.h"
#include "pawn/action/PawnActionFactory.h"
#include "common/Log.h"


using namespace Genius;
using namespace cfg;

COM_CREATE_FN_IMPL(ComPawnAgent);

void ComPawnAgent::Create(int cfgID, bool isPawn)
{
	m_roleCfg = nullptr;
	pBulletData = nullptr;

	if (isPawn)
	{
		m_roleCfg = FIND_CFG(Role_cfg, cfgID);
		if (nullptr == m_roleCfg)
		{
			Log::Error("ComPawnAgent::Create : wrong roleCfgID %d", cfgID);
		}
	}
	else
	{
		pBulletData = FIND_CFG(Bullet_cfg, cfgID);
		if (nullptr == pBulletData)
		{
			Log::Error("ComPawnAgent::Create : wrong bulletCfgID %d", cfgID);
		}
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