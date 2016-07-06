
#pragma once

#include "../BaseConfig.h"

namespace cfg
{
	class BuffAction_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(BuffAction_cfg)

		virtual int Init(Genius::TabFile& reader, int row, int col);

		int buffType;
		string function;
		int params[3];
	};
};