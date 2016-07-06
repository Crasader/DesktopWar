
#pragma once

#include "../BaseConfig.h"

namespace cfg
{
	class Role_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(Role_cfg)

		virtual int Init(Genius::TabFile& reader, int row, int col);

		string nameID;
		string nameCN;
		string animSetName;
		string bevTreeFile;
		int moveSpeed;
		int viewRange;
		int fightRangeNear;
		int fightRangeFar;
		int baseLife;
		int attackValue;
		int attackType;
		int antiPhysicValue;
		int antiMagicValue;
		int dodgeValue;
		int normalSkill1;
		int maxAttack1Times;
		int normalSkill2;
		int specialSkill1;
		int specialSkill2;
		int specialSkill3;
		int lifeBarType;
		int lifeBarHeight;
		int IdleDuration;
		int IdleTurnFaceTime;
		int WanderDuration;
		int WanderChangeDirTime;
		int DeadBodyTime;
		int bulletX;
		int bulletY;
	};
};