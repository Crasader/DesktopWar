
#pragma once

#include "../../core/IComponent.h"
#include "../../core/Entity.h"
#include "gfx/gfx.h"

namespace Genius
{

	class ComAnimation : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComAnimation);

	public:
		cocos2d::Node*				m_pAvatarRoot;
		cocostudio::Armature*		m_pBodyArmature;

	public:
		ComAnimation(){}
		~ComAnimation();
		void Create(const std::string& fileName);
	};

};
