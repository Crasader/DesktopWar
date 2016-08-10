
#include "ComPawnAgent.h"
#include "data/ConfigPool.h"
#include "data/auto/Role_cfg.hpp"
#include "data/auto/Bullet_cfg.hpp"
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

}

ComPawnAgent::~ComPawnAgent()
{
}

void ComPawnAgent::AddAction(int type)
{
}