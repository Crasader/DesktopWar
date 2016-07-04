
#pragma once

#include <vector>
#include <string>
#include "TabFile.h"

using namespace std;

typedef Genius::BaseConfig* (*create_config_class)();

namespace Genius
{
	class BaseConfig
	{
	public:
		virtual int Init(TabFile& reader, int row, int colomn) = 0;
		
		void RegisterFactoryCreate(create_config_class* func, string& name);

	public:
		static string Separator;
	};

	string BaseConfig::Separator = ",";

}

// ÎªÁË·´Éä !
#define DECLARE_CONFIG_CREATE(class_name) \
	static Genius::BaseConfig* CreateClass## class_name();

#define IMPL_CONFIG_CREATE(class_name) \
	static Genius::BaseConfig* CreateClass## class_name(){\
	return new class_name; \
	};

#define REG_CONFIG_CREATE(class_name) \
	Genius::ConfigPool::GetSingleton()->RegisterFactoryCreate(#class_name, class_name::CreateClass## class_name);


