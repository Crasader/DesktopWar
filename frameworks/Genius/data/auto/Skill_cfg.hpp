#include "../BaseConfig.h"

namespace cfg
{
	class Skill_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(Skill_cfg)

		int findTargetStyle;
		int findTargetRadius;
		int targetTeam;
		int costType;
		int costNum;
		int coolTime;
		int bulletID;
		int buffs[3];

		virtual int Init(Genius::TabFile& reader, int row, int col)
		{
			findTargetStyle = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				findTargetStyle = reader.GetIntValue(row, col++);

			findTargetRadius = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				findTargetRadius = reader.GetIntValue(row, col++);

			targetTeam = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				targetTeam = reader.GetIntValue(row, col++);

			costType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				costType = reader.GetIntValue(row, col++);

			costNum = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				costNum = reader.GetIntValue(row, col++);

			coolTime = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				coolTime = reader.GetIntValue(row, col++);

			bulletID = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				bulletID = reader.GetIntValue(row, col++);

			for(int i=0; i<3; i++)
				buffs[i] = 0;
			vector<string> buffsArray = reader.Split(reader.GetStringValue(row, col++), cfg::BaseConfig::Separator);
			int buffsCount = buffsArray.size();
			for(int i=0; i<3; i++)
			{
				if(i < buffsCount)
					buffs[i] = reader.ToInt(buffsArray[i]);
				else
					buffs[i] = 0;
			}

			return col;
		}
	};

IMPL_CONFIG_CREATE(Skill_cfg)

};