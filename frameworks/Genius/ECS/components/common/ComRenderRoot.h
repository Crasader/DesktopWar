
#pragma once

#include "../../core/IComponent.h"
#include "../../core/Entity.h"
#include "cocos2d.h"

namespace Genius
{

	class ComRenderRoot : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComRenderRoot);

	public:
		cocos2d::Node*				rootNode;

	public:
		virtual void OnAwake();
		virtual void OnDestroy();
		ComRenderRoot();
		~ComRenderRoot();
		void AddChild(cocos2d::Node* node);
	};

};
