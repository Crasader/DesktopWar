
#include "Log.h"
#include "ConfigPool.h"
#include "Headers.h"


using namespace std;
using namespace cfg;
using namespace Genius;


#define INSERT_CFG_TO_MAP(class_name, file_name)\
	fileMap[#class_name] = file_name; \
	typeMap[#class_name] = typeid(class_name).hash_code(); \
	REG_CONFIG_CREATE(class_name);

bool ConfigPool::Init()
{
	map<string, string> fileMap;
	map<string, size_t> typeMap;

	INSERT_CFG_TO_MAP(Animation_cfg, "Animation.txt");
	INSERT_CFG_TO_MAP(Buff_cfg, "Buff.txt");
	INSERT_CFG_TO_MAP(BuffAction_cfg, "BuffAction.txt");
	INSERT_CFG_TO_MAP(Bullet_cfg, "Bullet.txt");
	INSERT_CFG_TO_MAP(Role_cfg, "Role.txt");
	INSERT_CFG_TO_MAP(Skill_cfg, "Skill.txt");

	map<string, string>::iterator iter = fileMap.begin();
	while (iter != fileMap.end())
	{
		const std::string& className = iter->first;
		const std::string& fileName = iter->second;
		iter++;

		TabFile tabFile;
		string filePath = "res/data/" + fileName;
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

		for (int i = 4; i < rowCount; ++i)
		{
			BaseConfig* pCfg = (*m_creators[className])();
			pCfg->Init(tabFile, i, 1);
			if (pCfg->id > 0)
				oneMap.insert(make_pair(pCfg->id, pCfg));
		}

		m_pool.insert(make_pair(typeMap[className], oneMap));

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

BaseConfig* ConfigPool::GetConfig(size_t hash, int id)
{
	size_t key = hash;
	if (m_pool.find(key) != m_pool.end())
	{
		auto mp = m_pool[key];
		if (mp.find(id) != mp.end())
			return mp[id];
		else
			return nullptr;
	}
	else
	{
		return nullptr;
	}
}

std::map<int, BaseConfig*>& ConfigPool::GetConfigMap(size_t hash)
{
	size_t key = hash;
	if (m_pool.find(key) != m_pool.end())
	{
		return m_pool[key];
	}
	else
	{
		static std::map<int, BaseConfig*> sMap;
		return sMap;
	}
}


