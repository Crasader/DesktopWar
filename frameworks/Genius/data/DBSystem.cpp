
#include "DBSystem.h"
#include "RoleDataMgr.h"
#include "AnimDataMgr.h"
#include "SkillDataMgr.h"
#include "BuffDataMgr.h"
#include "BuffActionDataMgr.h"
#include "BulletDataMgr.h"
#include "Logger.h"

using namespace Genius;

bool DBSystem::Init()
{
	AddDataManager(RoleDataMgr::GetSingleton());
	AddDataManager(AnimDataMgr::GetSingleton());
	AddDataManager(SkillDataMgr::GetSingleton());
	AddDataManager(BuffDataMgr::GetSingleton());
	AddDataManager(BuffActionDataMgr::GetSingleton());
	AddDataManager(BulletDataMgr::GetSingleton());

	for (auto iter = m_dataMgrList.begin(); iter != m_dataMgrList.end(); ++iter)
	{
		if (!(*iter)->Init())
		{
			Logger::LogError("DBSystem init failed !");
			return false;
		}
	}

	return true;
}

void DBSystem::Destroy()
{
	for (auto iter = m_dataMgrList.begin(); iter != m_dataMgrList.end(); ++iter)
	{
		(*iter)->Destroy();
		delete *iter;
	}
	m_dataMgrList.clear();
}

void DBSystem::AddDataManager(IDataManager* mgr)
{
	m_dataMgrList.push_back(mgr);
}