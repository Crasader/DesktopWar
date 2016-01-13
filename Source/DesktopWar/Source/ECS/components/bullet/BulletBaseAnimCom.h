
#pragma once

#include "../../core/Component.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

namespace Genius
{
	class BulletBaseAnimCom : public Component
	{
	public:
		cocos2d::Node*				m_pAvatarRoot;
		cocostudio::Armature*		m_pBodyArmature;

	public:
		BulletBaseAnimCom(const std::string& bodyFileName);
		virtual ~BulletBaseAnimCom();
	};
};

