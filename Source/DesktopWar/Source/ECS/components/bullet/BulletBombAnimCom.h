
#pragma once

#include "BulletBaseAnimCom.h"
#include <string>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

namespace Genius
{
	class BulletBombAnimCom : public BulletBaseAnimCom
	{
	public:
		const static std::string explodeAnimName;

	public:
		BulletBombAnimCom(const std::string& bodyFileName, const std::string& tailFileName);
		
		void StartExplode();
		void AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName);
		void AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx);
	};
};

