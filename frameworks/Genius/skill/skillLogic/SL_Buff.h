
#pragma once

#include "SkillLogic.h"

namespace Genius
{
	class SL_Buff : public SkillLogic
	{
	public:
		virtual void OnActive(){}
		virtual void OnDeactive(){}

		DECLARE_SKILLLOGIC_CREATOR(SL_Buff)

	};

}