// d:)
#include "BulletBaseAnimCom.h"
#include "gfx/gfx.h"

using namespace Genius;

BulletBaseAnimCom::BulletBaseAnimCom(const std::string& bodyFileName)
{
	m_pAvatarRoot = nullptr;
	m_pBodyArmature = nullptr;

	m_pAvatarRoot = cocos2d::Node::create();
	SceneManager::GetInstance().AddToMapLayer(m_pAvatarRoot);
	
	m_pBodyArmature = cocostudio::Armature::create(bodyFileName);
	m_pBodyArmature->getAnimation()->playWithIndex(0);
	m_pAvatarRoot->addChild(m_pBodyArmature);
}

BulletBaseAnimCom::~BulletBaseAnimCom()
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->removeFromParent();
		m_pAvatarRoot = nullptr;
	}
}