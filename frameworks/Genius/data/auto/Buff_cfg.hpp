#pragma once

#include "../BaseConfig.h"

namespace cfg
{
	class Buff_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(Buff_cfg)

		int series;
		int hurtType;
		int duration;
		int jumpTime;
		int maxPileCount;
		int pileType;
		int actionID;
		int actionType;

		virtual int Init(Genius::TabFile& reader, int row, int col)
		{
			series = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				series = reader.GetIntValue(row, col++);

			hurtType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				hurtType = reader.GetIntValue(row, col++);

			duration = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				duration = reader.GetIntValue(row, col++);

			jumpTime = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				jumpTime = reader.GetIntValue(row, col++);

			maxPileCount = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				maxPileCount = reader.GetIntValue(row, col++);

			pileType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				pileType = reader.GetIntValue(row, col++);

			actionID = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				actionID = reader.GetIntValue(row, col++);

			actionType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				actionType = reader.GetIntValue(row, col++);

			return col;
		}
	};

IMPL_CONFIG_CREATE(Buff_cfg)

};