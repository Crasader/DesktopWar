
#include "Log.h"
#include "ConfigPool.h"
#include "Headers.h"


using namespace std;
using namespace cfg;
using namespace Genius;

// 注册cfg类和文件
#define INSERT_CFG_TO_MAP(class_name, file_name)\
	fileMap[#class_name] = file_name; \
	typeMap[#class_name] = typeid(class_name).hash_code(); \
	REG_CONFIG_CREATE(class_name);

bool ConfigPool::Init()
{
	map<string, string> fileMap;
	map<string, size_t> typeMap;

	INSERT_CFG_TO_MAP(Animation_cfg, "Animation.tab");
	INSERT_CFG_TO_MAP(Buff_cfg, "Buff.tab");
	INSERT_CFG_TO_MAP(BuffAction_cfg, "BuffAction.tab");
	INSERT_CFG_TO_MAP(Bullet_cfg, "Bullet.tab");
	INSERT_CFG_TO_MAP(Role_cfg, "Role.tab");
	INSERT_CFG_TO_MAP(Skill_cfg, "Skill.tab");

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

template <typename T>
T* ConfigPool::GetConfig(int id)
{
	size_t key = typeid(T).hash_code();
	if (m_pool.find(m_pool) != m_pool.end())
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

template <typename T>
T* ConfigPool::GetConfig(std::string& id)
{
	return nullptr;
}

template <typename T>
std::map<int, BaseConfig*>& ConfigPool::GetConfigMap()
{
	size_t key = typeid(T).hash_code();
	if (m_pool.find(m_pool) != m_pool.end())
	{
		return m_pool[key];
	}
	else
	{
		static std::map<int, BaseConfig*> sMap;
		return sMap;
	}
}


