
#pragma once

#include <string>
#include "../../core/IComponent.h"
#include "pawn/PawnDefines.h"
#include "common/2Ddef.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComPawnDebugDraw : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComPawnDebugDraw);

	public:
		cocos2d::Node*			pRoot;
		cocos2d::DrawNode*	pNodeBoxCollider;
		cocos2d::DrawNode*	pNodeNearRange;
		cocos2d::DrawNode*	pNodeFarRange;

	public:
		void Create();
		~ComPawnDebugDraw();
		void Clear();
	};

	

};
