
#pragma once

#include "BulletBaseAnimCom.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

namespace Genius
{
	class BulletEggAnimCom : public BulletBaseAnimCom
	{
	public:
		BulletEggAnimCom(const std::string& bodyFileName);
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};
};

