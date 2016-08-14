
#pragma once

#include "../BaseConfig.h"

namespace cfg
{
	class Bullet_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(Bullet_cfg)

		virtual int Init(Genius::TabFile& reader, int row, int col);

		int movable;
		int moveType;
		int targetIsEntity;
		int flySpeed;
		int maxLifeTime;
		int boxWidth;
		int boxHeight;
		int bodyAnim;
		string tailAnim;
		int buffTargetStyle;
		int buffTargetRadius;
		int attackValue;
		int attackType;
		int buffs[3];
	};
};