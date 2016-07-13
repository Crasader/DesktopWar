
#pragma once

#include "ComBulletAnimBase.h"
#include <string>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

namespace Genius
{
	class ComBulletAnimArrow : public ComBulletAnimBase
	{
	public:
		const static std::string stopAnimName;

	public:
		void Create(const std::string& bodyFileName);
		
		void StayStill();
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};
};

