
#pragma once

#include "SkillLogic.h"

namespace Genius
{
	class SL_Buff : public SkillLogic
	{
	public:
		virtual void OnActive(Skill* skill);
		virtual void OnDeactive(Skill* skill);

		DECLARE_SKILLLOGIC_CREATOR(SL_Buff)

	};

}