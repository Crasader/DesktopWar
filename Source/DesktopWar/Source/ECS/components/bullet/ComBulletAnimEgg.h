
#pragma once

#include "ComBulletAnimBase.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

namespace Genius
{
	class ComBulletAnimEgg : public ComBulletAnimBase
	{
	public:
		ComBulletAnimEgg(const std::string& bodyFileName);
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};
};

