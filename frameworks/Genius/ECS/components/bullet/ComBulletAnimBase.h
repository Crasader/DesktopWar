
#pragma once

#include "../../core/IComponent.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

namespace Genius
{
	class ComBulletAnimBase : public IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComBulletAnimBase);

	public:
		cocos2d::Node*				m_pAvatarRoot;
		cocostudio::Armature*		m_pBodyArmature;

	public:
		void Create(const std::string& bodyFileName);
		virtual ~ComBulletAnimBase();
	};
};

