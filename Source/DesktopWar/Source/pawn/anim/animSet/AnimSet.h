
#pragma once

namespace Genius
{
	class AnimSet
	{
	public:

		AnimSet();

		virtual ~AnimSet();

		virtual const char* GetIdleAnim() = 0;

		virtual const char* GetMoveAnim() = 0;

		virtual const char* GetDieAnim() = 0;

		virtual const char* GetAttackNearAnim() = 0;

		virtual const char* GetAttackFarAnim() = 0;

		virtual const char* GetSkill1Anim() = 0;

		virtual const char* GetSkill2Anim() = 0;

		virtual const char* GetSkill3Anim() = 0;

	};
}
