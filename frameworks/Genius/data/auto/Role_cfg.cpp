#include "Role_cfg.hpp"

using namespace cfg;

IMPL_CONFIG_CREATE(Role_cfg);

		int Role_cfg::Init(Genius::TabFile& reader, int row, int col)
		{
			nameID = "";
			if(reader.GetStringValue(row, col).length() > 0)
				nameID = reader.GetStringValue(row, col++);

			nameCN = "";
			if(reader.GetStringValue(row, col).length() > 0)
				nameCN = reader.GetStringValue(row, col++);

			animSetName = "";
			if(reader.GetStringValue(row, col).length() > 0)
				animSetName = reader.GetStringValue(row, col++);

			bevTreeFile = "";
			if(reader.GetStringValue(row, col).length() > 0)
				bevTreeFile = reader.GetStringValue(row, col++);

			moveSpeed = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				moveSpeed = reader.GetIntValue(row, col++);

			viewRange = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				viewRange = reader.GetIntValue(row, col++);

			fightRangeNear = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				fightRangeNear = reader.GetIntValue(row, col++);

			fightRangeFar = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				fightRangeFar = reader.GetIntValue(row, col++);

			baseLife = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				baseLife = reader.GetIntValue(row, col++);

			attackValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				attackValue = reader.GetIntValue(row, col++);

			attackType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				attackType = reader.GetIntValue(row, col++);

			antiPhysicValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				antiPhysicValue = reader.GetIntValue(row, col++);

			antiMagicValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				antiMagicValue = reader.GetIntValue(row, col++);

			dodgeValue = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				dodgeValue = reader.GetIntValue(row, col++);

			normalSkill1 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				normalSkill1 = reader.GetIntValue(row, col++);

			maxAttack1Times = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				maxAttack1Times = reader.GetIntValue(row, col++);

			normalSkill2 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				normalSkill2 = reader.GetIntValue(row, col++);

			specialSkill1 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				specialSkill1 = reader.GetIntValue(row, col++);

			specialSkill2 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				specialSkill2 = reader.GetIntValue(row, col++);

			specialSkill3 = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				specialSkill3 = reader.GetIntValue(row, col++);

			lifeBarType = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				lifeBarType = reader.GetIntValue(row, col++);

			lifeBarHeight = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				lifeBarHeight = reader.GetIntValue(row, col++);

			IdleDuration = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				IdleDuration = reader.GetIntValue(row, col++);

			IdleTurnFaceTime = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				IdleTurnFaceTime = reader.GetIntValue(row, col++);

			WanderDuration = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				WanderDuration = reader.GetIntValue(row, col++);

			WanderChangeDirTime = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				WanderChangeDirTime = reader.GetIntValue(row, col++);

			DeadBodyTime = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				DeadBodyTime = reader.GetIntValue(row, col++);

			bulletX = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				bulletX = reader.GetIntValue(row, col++);

			bulletY = 0;
			if(reader.GetStringValue(row, col).length() > 0)
				bulletY = reader.GetIntValue(row, col++);

			return col;
		}
