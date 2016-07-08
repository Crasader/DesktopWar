
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
		int series;
		int hurtType;
		int duration;
		int jumpTime;
		int maxPileCount;
		int pileType;
		int actionID;
		int actionType;
	};
};