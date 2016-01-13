
#pragma once

#include "../../core/Component.h"
#include "../../core/Entity.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComAnimation : public Component
	{
	public:
		cocos2d::Node*					m_pAvatarRoot;
		cocostudio::Armature*		m_pBodyArmature;

	public:
		ComAnimation(const std::string& fileName);
		~ComAnimation();
	};

};
