
#pragma once

#include <string>
#include "../../core/Component.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class PawnAnimCom : public cocos2d::Ref, public Component
	{
	public:
		cocos2d::Node*					m_pAvatarRoot;
		cocostudio::Armature*			m_pBodyArmature;
		UIBar*									m_pLifeBar;
		Label*									m_pDebugLabel;
		int										m_curAction;

	public:
		PawnAnimCom(int roleID);
		virtual ~PawnAnimCom();

		float GetWidth();
		float GetHeight();
		void PlayAnimation(std::string name);
		void SetPosition(float x, float y);
		bool HaveThisAnimation(std::string name);
		void PlayFloatNumber(int number, int y);

		void SetDebugLabel(std::string text);

	public:
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType met, const std::string& cr);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};

	

};
