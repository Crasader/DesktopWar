
#pragma once


#include "../../core/IComponent.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComParticle : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComParticle);

	public:
		cocos2d::Node*					m_pAvatarRoot;

	public:
		void Create(const std::string& fileName);
		~ComParticle();
	};

};
