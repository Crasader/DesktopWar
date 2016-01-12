
#pragma once

#include "../../core/Component.h"
#include "../../core/Entity.h"
#include "gfx/gfx.h"

namespace Genius
{

	class AnimationCom : public Component
	{
	public:
		cocos2d::Node*					m_pAvatarRoot;
		cocostudio::Armature*		m_pBodyArmature;

	public:
		AnimationCom(const std::string& fileName);
		~AnimationCom();
	};

};
