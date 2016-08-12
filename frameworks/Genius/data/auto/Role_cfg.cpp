#include "Role_cfg.hpp"

using namespace cfg;

IMPL_CONFIG_CREATE(Role_cfg);

		int Role_cfg::Init(Genius::TabFile& reader, int row, int col)
		{
			col = BaseConfig::Init(reader, row, col);

			nameID = "";
			if(reader.GetStringValue(row, col).length() > 0)
				nameID = reader.GetStringValue(row, col);
			col++;

			nameCN = "";
			if(reader.GetStringValue(row, col).length() > 0)
				nameCN = reader.GetStringValue(row, col);
			col++;

			animSetId = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				animSetId = reader.GetIntValue(row, col);
			col++;

			moveSpeed = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				moveSpeed = reader.GetIntValue(row, col);
			col++;

			viewRange = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				viewRange = reader.GetIntValue(row, col);
			col++;

			fightRangeNear = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				fightRangeNear = reader.GetIntValue(row, col);
			col++;

			fightRangeFar = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				fightRangeFar = reader.GetIntValue(row, col);
			col++;

			baseLife = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				baseLife = reader.GetIntValue(row, col);
			col++;

			attackValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				attackValue = reader.GetIntValue(row, col);
			col++;

			attackType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				attackType = reader.GetIntValue(row, col);
			col++;

			antiPhysicValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				antiPhysicValue = reader.GetIntValue(row, col);
			col++;

			antiMagicValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				antiMagicValue = reader.GetIntValue(row, col);
			col++;

			dodgeValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				dodgeValue = reader.GetIntValue(row, col);
			col++;

			normalSkill1 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				normalSkill1 = reader.GetIntValue(row, col);
			col++;

			normalSkill2 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				normalSkill2 = reader.GetIntValue(row, col);
			col++;

			specialSkill1 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				specialSkill1 = reader.GetIntValue(row, col);
			col++;

			specialSkill2 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				specialSkill2 = reader.GetIntValue(row, col);
			col++;

			specialSkill3 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				specialSkill3 = reader.GetIntValue(row, col);
			col++;

			lifeBarType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				lifeBarType = reader.GetIntValue(row, col);
			col++;

			lifeBarHeight = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				lifeBarHeight = reader.GetIntValue(row, col);
			col++;

			bulletX = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				bulletX = reader.GetIntValue(row, col);
			col++;

			bulletY = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				bulletY = reader.GetIntValue(row, col);
			col++;

			return col;
		}
