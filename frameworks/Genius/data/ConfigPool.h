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

		void RegisterFactoryCreate(std::string className, create_config_class func);

	private:
		std::map<size_t, std::map<int, BaseConfig*>>		m_pool;
		std::map<std::string, create_config_class>			m_creators;

		//std::vector<IDataManager*>		m_dataMgrList;
	};
};

#endif