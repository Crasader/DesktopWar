#include "Buff_cfg.hpp"

using namespace cfg;

IMPL_CONFIG_CREATE(Buff_cfg);

		int Buff_cfg::Init(Genius::TabFile& reader, int row, int col)
		{
			col = BaseConfig::Init(reader, row, col);

			logicId = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				logicId = reader.GetIntValue(row, col);
			col++;

			attrType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				attrType = reader.GetIntValue(row, col);
			col++;

			modType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				modType = reader.GetIntValue(row, col);
			col++;

			calType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				calType = reader.GetIntValue(row, col);
			col++;

			value = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				value = reader.GetIntValue(row, col);
			col++;

			duration = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				duration = reader.GetIntValue(row, col);
			col++;

			jumpTime = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				jumpTime = reader.GetIntValue(row, col);
			col++;

			series = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				series = reader.GetIntValue(row, col);
			col++;

			pileType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				pileType = reader.GetIntValue(row, col);
			col++;

			maxPileCount = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				maxPileCount = reader.GetIntValue(row, col);
			col++;

			return col;
		}
