
#pragma once

#include "AnimSet.h"

namespace Genius
{
	class AnimSetSimple : public AnimSet
	{
	public:
		AnimSetSimple(Armature* armature);
		virtual ~AnimSetSimple();

		virtual const char* GetIdleAnim(int direction);
		virtual const char* GetMoveAnim(int direction);
		virtual const char* GetDieAnim(int direction);
		virtual const char* GetAttackNearAnim(int direction);
		virtual const char* GetAttackFarAnim(int direction);
		virtual const char* GetSkill1Anim(int direction);
		virtual const char* GetSkill2Anim(int direction);
		virtual const char* GetSkill3Anim(int direction);

	};
}
