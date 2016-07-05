#pragma once

#include "../BaseConfig.h"

namespace cfg
{
	class Bullet_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(Bullet_cfg)

		int movable;
		int moveType;
		int targetIsEntity;
		int flySpeed;
		int findTargetDelay;
		int maxLifeTime;
		int boxWidth;
		int boxHeight;
		string bodyAnim;
		string tailAnim;
		int buffTargetStyle;
		int buffTargetRadius;
		int attackValue;
		int attackType;
		int buffs[3];

		virtual int Init(Genius::TabFile& reader, int row, int col)
		{
			movable = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				movable = reader.GetIntValue(row, col++);

			moveType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				moveType = reader.GetIntValue(row, col++);

			targetIsEntity = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				targetIsEntity = reader.GetIntValue(row, col++);

			flySpeed = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				flySpeed = reader.GetIntValue(row, col++);

			findTargetDelay = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				findTargetDelay = reader.GetIntValue(row, col++);

			maxLifeTime = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				maxLifeTime = reader.GetIntValue(row, col++);

			boxWidth = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				boxWidth = reader.GetIntValue(row, col++);

			boxHeight = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				boxHeight = reader.GetIntValue(row, col++);

			bodyAnim = "";
			if(reader.GetStringValue(row, col).length() > 0)
				bodyAnim = reader.GetStringValue(row, col++);

			tailAnim = "";
			if(reader.GetStringValue(row, col).length() > 0)
				tailAnim = reader.GetStringValue(row, col++);

			buffTargetStyle = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				buffTargetStyle = reader.GetIntValue(row, col++);

			buffTargetRadius = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				buffTargetRadius = reader.GetIntValue(row, col++);

			attackValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				attackValue = reader.GetIntValue(row, col++);

			attackType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				attackType = reader.GetIntValue(row, col++);

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
	IMPL_CONFIG_CREATE(Bullet_cfg)
};