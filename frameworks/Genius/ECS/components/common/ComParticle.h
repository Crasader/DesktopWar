
#pragma once


#include "../../core/IComponent.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComParticle : public IComponent
	{
	public:
		cocos2d::Node*					m_pAvatarRoot;

	public:
		void Create(const std::string& fileName);
		~ComParticle();
	};

};
