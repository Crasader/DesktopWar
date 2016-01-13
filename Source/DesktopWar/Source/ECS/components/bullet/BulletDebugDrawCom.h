
#pragma once

#include "../../core/Component.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

namespace Genius
{
	class BulletDebugDrawCom : public Component
	{
	public:
		cocos2d::Node*			pRoot;
		cocos2d::DrawNode*	pNodeBoxCollider;
		cocos2d::DrawNode*	pNodeHurtRange;

	public:
		BulletDebugDrawCom();
		~BulletDebugDrawCom();
		void Clear();
	};
};

