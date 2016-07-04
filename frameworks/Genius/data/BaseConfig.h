
#pragma once

#include <vector>
#include <string>
#include "TabFile.h"

using namespace std;

namespace cfg
{
	class BaseConfig
	{
	public:
		int id;
		string idStr;
		virtual int Init(Genius::TabFile& reader, int row, int colomn);

	public:
		static string Separator;
	};

}

// ÎªÁË·´Éä !

typedef cfg::BaseConfig* (*create_config_class)(void);

#define DECLARE_CONFIG_CREATE(class_name) \
	static cfg::BaseConfig* CreateClass## class_name();

#define IMPL_CONFIG_CREATE(class_name) \
	cfg::BaseConfig* class_name::CreateClass## class_name(){\
	return new class_name; \
	};

#define REG_CONFIG_CREATE(class_name) \
	cfg::ConfigPool::GetSingleton()->RegisterFactoryCreate(#class_name, class_name::CreateClass## class_name);


