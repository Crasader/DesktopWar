
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
using namespace cfg;
using namespace Genius;

bool ConfigPool::Init()
{
	map<string, string> fileMap;
	map<string, size_t> typeMap;
	fileMap["anim_cfg"] = "anim.tab";
	typeMap["anim_cfg"] = typeid(anim_cfg).hash_code();
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
		m_pool.insert(make_pair(typeMap[className], oneMap));

		for (int i = 4; i < rowCount; ++i)
		{
			BaseConfig* pCfg = (*m_creators[className])();
			pCfg->Init(tabFile, i, 1);
			oneMap.insert(make_pair(pCfg->id, pCfg));
		}

	}

	return true;
}

void ConfigPool::Destroy()
{
	std::map<size_t, std::map<int, BaseConfig*>>::iterator iter = m_pool.begin();
	for (; iter != m_pool.end(); ++iter)
	{
		std::map<int, BaseConfig*>::iterator iter2 = iter->second.begin();
		for (; iter2 != iter->second.end(); ++iter2)
		{
			if (iter2->second != nullptr)
				delete iter2->second;
		}
		iter->second.clear();
	}
	m_pool.clear();
}

void ConfigPool::RegisterFactoryCreate(string className, create_config_class func)
{
	m_creators.insert(make_pair(className, func));
}


