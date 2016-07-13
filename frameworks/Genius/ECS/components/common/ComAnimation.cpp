
#include "ComAnimation.h"
#include "../../core/ECSWorld.h"

using namespace Genius;
using namespace cocos2d;


void ComAnimation::Create(const std::string& fileName)
{
	m_pAvatarRoot = cocos2d::Node::create();
	m_pBodyArmature = cocostudio::Armature::create(fileName);
	m_pAvatarRoot->addChild(m_pBodyArmature);
	SceneManager::GetSingleton()->AddToMapLayer(m_pAvatarRoot);
	m_pBodyArmature->getAnimation()->playWithIndex(0);
}

ComAnimation::~ComAnimation()
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->removeFromParent();
		m_pAvatarRoot = nullptr;
	}
}

