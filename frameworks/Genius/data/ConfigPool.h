#ifndef _GENIUS_CONFIGPOOL_H_
#define _GENIUS_CONFIGPOOL_H_

#include <vector>
#include <map>
#include "common/Singleton.h"
#include "BaseConfig.h"



namespace cfg
{
	class ConfigPool : public Genius::Singleton<ConfigPool>
	{
	public:
		ConfigPool(){}
		~ConfigPool(){}

		bool Init();
		void Destroy();

		BaseConfig* GetConfig(size_t hash, int id);
		std::map<int, BaseConfig*>& GetConfigMap(size_t hash);

		void RegisterFactoryCreate(std::string className, create_config_class func);

	private:
		std::map<size_t, std::map<int, BaseConfig*>>		m_pool;
		std::map<std::string, create_config_class>			m_creators;

	};
};


#define FIND_CFG(classname, id)\
	(classname*)cfg::ConfigPool::GetSingleton()->GetConfig(typeid(classname).hash_code(), id);

#define FIND_CFG_MAP(classname)\
	(std::map<int, BaseConfig*>&)cfg::ConfigPool::GetSingleton()->GetConfigMap(typeid(classname).hash_code());


#endif