#include "Skill_cfg.hpp"

using namespace cfg;

IMPL_CONFIG_CREATE(Skill_cfg);

		int Skill_cfg::Init(Genius::TabFile& reader, int row, int col)
		{
			col = BaseConfig::Init(reader, row, col);

			logicId = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				logicId = reader.GetIntValue(row, col);
			col++;

			targetType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				targetType = reader.GetIntValue(row, col);
			col++;

			radius = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				radius = reader.GetIntValue(row, col);
			col++;

			targetTeam = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				targetTeam = reader.GetIntValue(row, col);
			col++;

			costType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				costType = reader.GetIntValue(row, col);
			col++;

			costNum = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				costNum = reader.GetIntValue(row, col);
			col++;

			coolTime = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				coolTime = reader.GetIntValue(row, col);
			col++;

			bulletID = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				bulletID = reader.GetIntValue(row, col);
			col++;

			for(int i=0; i<3; i++)
				buffs[i] = 0;
			vector<string> buffsArray = reader.Split(reader.GetStringValue(row, col++), cfg::BaseConfig::Separator);
			int buffsCount = buffsArray.size();
			for(int i=0; i<3; i++)
			{
				if(i < buffsCount && buffsArray[i].length() > 0)
					buffs[i] = reader.ToInt(buffsArray[i]);
				else
					buffs[i] = 0;
			}

			return col;
		}
