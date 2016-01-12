
#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocostudio;

namespace Genius
{
	class AnimSet
	{
	public:

		AnimSet(Armature* armature);

		virtual ~AnimSet();

		virtual bool HaveAnim(const char* name);

		virtual const char* GetIdleAnim(int direction) = 0;

		virtual const char* GetMoveAnim(int direction) = 0;

		virtual const char* GetDieAnim(int direction) = 0;

		virtual const char* GetAttackNearAnim(int direction) = 0;

		virtual const char* GetAttackFarAnim(int direction) = 0;

		virtual const char* GetSkill1Anim(int direction) = 0;

		virtual const char* GetSkill2Anim(int direction) = 0;

		virtual const char* GetSkill3Anim(int direction) = 0;

	protected:
		cocostudio::Armature*	m_pArmature;

	};
}
