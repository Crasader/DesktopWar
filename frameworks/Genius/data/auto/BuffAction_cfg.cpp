#include "BuffAction_cfg.hpp"

using namespace cfg;

IMPL_CONFIG_CREATE(BuffAction_cfg);

		int BuffAction_cfg::Init(Genius::TabFile& reader, int row, int col)
		{
			col = BaseConfig::Init(reader, row, col);

			buffType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				buffType = reader.GetIntValue(row, col++);

			function = "";
			if(reader.GetStringValue(row, col).length() > 0)
				function = reader.GetStringValue(row, col++);

			for(int i=0; i<3; i++)
				params[i] = 0;
			vector<string> paramsArray = reader.Split(reader.GetStringValue(row, col++), cfg::BaseConfig::Separator);
			int paramsCount = paramsArray.size();
			for(int i=0; i<3; i++)
			{
				if(i < paramsCount)
					params[i] = reader.ToInt(paramsArray[i]);
				else
					params[i] = 0;
			}

			return col;
		}
