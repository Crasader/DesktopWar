
#pragma once


#include "../../core/Component.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ParticleCom : public Component
	{
	public:
		cocos2d::Node*					m_pAvatarRoot;

	public:
		ParticleCom(const std::string& fileName);
		~ParticleCom();
	};

};
