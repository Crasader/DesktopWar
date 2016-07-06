
#pragma once

#include "../BaseConfig.h"

namespace cfg
{
	class Skill_cfg : public BaseConfig
	{
	public:

		DECLARE_CONFIG_CREATE(Skill_cfg)

		virtual int Init(Genius::TabFile& reader, int row, int col);

		int findTargetStyle;
		int findTargetRadius;
		int targetTeam;
		int costType;
		int costNum;
		int coolTime;
		int bulletID;
		int buffs[3];
	};
};