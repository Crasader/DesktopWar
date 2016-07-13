
#include "ComBulletAnimBase.h"
#include "gfx/gfx.h"

using namespace Genius;

void ComBulletAnimBase::Create(const std::string& bodyFileName)
{
	m_pAvatarRoot = nullptr;
	m_pBodyArmature = nullptr;

	m_pAvatarRoot = cocos2d::Node::create();
	SceneManager::GetSingleton()->AddToMapLayer(m_pAvatarRoot);
	
	m_pBodyArmature = cocostudio::Armature::create(bodyFileName);
	m_pBodyArmature->getAnimation()->playWithIndex(0);
	m_pAvatarRoot->addChild(m_pBodyArmature);
}

ComBulletAnimBase::~ComBulletAnimBase()
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->removeFromParent();
		m_pAvatarRoot = nullptr;
	}
}