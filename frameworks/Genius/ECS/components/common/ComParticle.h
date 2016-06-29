
#pragma once


#include "../../core/Component.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComParticle : public Component
	{
	public:
		cocos2d::Node*					m_pAvatarRoot;

	public:
		ComParticle(const std::string& fileName);
		~ComParticle();
	};

};
