
#pragma once

#include "BulletBaseAnimCom.h"
#include <string>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

namespace Genius
{
	class BulletArrowAnimCom : public BulletBaseAnimCom
	{
	public:
		const static std::string stopAnimName;

	public:
		BulletArrowAnimCom(const std::string& bodyFileName);
		
		void StayStill();
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};
};

