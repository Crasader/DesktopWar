
#pragma once

#include <string>
#include "../../core/Component.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComPawnDebugDraw : public Component
	{
	public:
		cocos2d::Node*			pRoot;
		cocos2d::DrawNode*	pNodeBoxCollider;
		cocos2d::DrawNode*	pNodeNearRange;
		cocos2d::DrawNode*	pNodeFarRange;

	public:
		ComPawnDebugDraw();
		~ComPawnDebugDraw();
		void Clear();
	};

	

};
