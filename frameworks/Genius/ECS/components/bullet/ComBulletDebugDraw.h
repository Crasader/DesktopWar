
#pragma once

#include "../../core/IComponent.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

namespace Genius
{
	class ComBulletDebugDraw : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComBulletDebugDraw);

	public:
		cocos2d::Node*			pRoot;
		cocos2d::DrawNode*	pNodeBoxCollider;
		cocos2d::DrawNode*	pNodeHurtRange;

	public:
		ComBulletDebugDraw();
		~ComBulletDebugDraw();
		void Clear();
	};
};

