
#pragma once

#include "../BaseConfig.h"

namespace cfg
{
	class Animation_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(Animation_cfg)

		virtual int Init(Genius::TabFile& reader, int row, int col);

		string filePath;
	};
};