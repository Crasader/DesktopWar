
#pragma once

#include "AnimSet.h"

namespace Genius
{
	class AnimSetSimple : public AnimSet
	{
	public:
		AnimSetSimple(ComPawnAnim*	pComPawnAnim);
		virtual ~AnimSetSimple();

		virtual const std::string& GetIdleAnim(int direction);
		virtual const std::string& GetMoveAnim(int direction);
		virtual const std::string& GetDieAnim(int direction);
		virtual const std::string& GetAttackNearAnim(int direction);
		virtual const std::string& GetAttackFarAnim(int direction);
		virtual const std::string& GetSkill1Anim(int direction);
		virtual const std::string& GetSkill2Anim(int direction);
		virtual const std::string& GetSkill3Anim(int direction);

	};
}
