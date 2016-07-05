#pragma once

#include "../BaseConfig.h"

namespace cfg
{
	class BuffAction_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(BuffAction_cfg)

		int buffType;
		string function;
		int params[3];

		virtual int Init(Genius::TabFile& reader, int row, int col)
		{
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
	};

IMPL_CONFIG_CREATE(BuffAction_cfg)

};