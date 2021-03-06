#include "Bullet_cfg.hpp"

using namespace cfg;

IMPL_CONFIG_CREATE(Bullet_cfg);

		int Bullet_cfg::Init(Genius::TabFile& reader, int row, int col)
		{
			col = BaseConfig::Init(reader, row, col);

			movable = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				movable = reader.GetIntValue(row, col);
			col++;

			moveType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				moveType = reader.GetIntValue(row, col);
			col++;

			targetIsEntity = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				targetIsEntity = reader.GetIntValue(row, col);
			col++;

			flySpeed = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				flySpeed = reader.GetIntValue(row, col);
			col++;

			maxLifeTime = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				maxLifeTime = reader.GetIntValue(row, col);
			col++;

			boxWidth = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				boxWidth = reader.GetIntValue(row, col);
			col++;

			boxHeight = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				boxHeight = reader.GetIntValue(row, col);
			col++;

			bodyAnim = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				bodyAnim = reader.GetIntValue(row, col);
			col++;

			tailAnim = "";
			if(reader.GetStringValue(row, col).length() > 0)
				tailAnim = reader.GetStringValue(row, col);
			col++;

			buffTargetStyle = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				buffTargetStyle = reader.GetIntValue(row, col);
			col++;

			buffTargetRadius = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				buffTargetRadius = reader.GetIntValue(row, col);
			col++;

			attackValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				attackValue = reader.GetIntValue(row, col);
			col++;

			attackType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				attackType = reader.GetIntValue(row, col);
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
