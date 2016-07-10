
#pragma once

#include "../BaseConfig.h"

namespace cfg
{
	class Buff_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(Buff_cfg)

		virtual int Init(Genius::TabFile& reader, int row, int col);

		int logicId;
		int attrType;
		int modType;
		int calType;
		int value;
		int duration;
		int jumpTime;
		int series;
		int pileType;
		int maxPileCount;
	};
};