
#include "ConfigPool.h"
#include "RoleDataMgr.h"
#include "AnimDataMgr.h"
#include "SkillDataMgr.h"
#include "BuffDataMgr.h"
#include "BuffActionDataMgr.h"
#include "BulletDataMgr.h"
#include "Log.h"

#include "auto/anim_cfg.hpp"


using namespace std;
using namespace Genius;

bool ConfigPool::Init()
{
	map<string, string> fileMap;
	fileMap["anim_cfg"] = "anim.tab";
	REG_CONFIG_CREATE(anim_cfg)

	map<string, string>::iterator iter = fileMap.begin();
	while (iter != fileMap.end())
	{
		const std::string& className = iter->first;
		const std::string& fileName = iter->second;
		iter++;

		TabFile tabFile;
		string filePath = fileName;
		if (!tabFile.LoadFile(filePath))
		{
			Log::Error("load file failed : %s", filePath.c_str());
			return false;
		}

		int rowCount = tabFile.GetRowCount();
		int colCount = tabFile.GetColCount();
		if (rowCount < 1 || colCount < 1)
		{
			Log::Error("load file failed : %s", filePath.c_str());
			return false;
		}

		map<int, BaseConfig*> oneMap;
		m_pool.insert(make_pair(typeid(ConfigPool)., oneMap));

		for (int i = 4; i < rowCount; ++i)
		{
			BaseConfig* pCfg = m_creators[className]();
			pCfg->Init(tabFile, i, 1);
			oneMap.insert((std::make_pair((pCfg->id, pCfg));
		}

	}

	/*AddDataManager(RoleDataMgr::GetSingleton());
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
	}*/

	return true;
}

void ConfigPool::Destroy()
{
	for (auto iter = m_dataMgrList.begin(); iter != m_dataMgrList.end(); ++iter)
	{
		(*iter)->Destroy();
		delete *iter;
	}
	m_dataMgrList.clear();
}

/*void ConfigPool::AddDataManager(IDataManager* mgr)
{
	m_dataMgrList.push_back(mgr);
}*/

void ConfigPool::RegisterFactoryCreate(string className, create_config_class* func)
{
	m_creators.insert(make_pair(className, func));
}


