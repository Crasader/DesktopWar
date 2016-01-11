
#pragma once

#include "AnimSet.h"

namespace Genius
{
	class AnimSetSimple : public AnimSet
	{
	public:
		AnimSetSimple();
		virtual ~AnimSetSimple();

		virtual const char* GetIdleAnim();
		virtual const char* GetMoveAnim();
		virtual const char* GetDieAnim() = 0;
		virtual const char* GetAttackNearAnim();
		virtual const char* GetAttackFarAnim();
		virtual const char* GetSkill1Anim();
		virtual const char* GetSkill2Anim();
		virtual const char* GetSkill3Anim();

	};
}
