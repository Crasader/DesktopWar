// d:)
#include "AnimationCom.h"
#include "../../core/ECSWorld.h"

using namespace Genius;
using namespace cocos2d;


AnimationCom::AnimationCom(const std::string& fileName)
{
	m_pAvatarRoot = cocos2d::Node::create();
	m_pBodyArmature = cocostudio::Armature::create(fileName);
	m_pAvatarRoot->addChild(m_pBodyArmature);
	SceneManager::GetInstance().AddToMapLayer(m_pAvatarRoot);
	m_pBodyArmature->getAnimation()->playWithIndex(0);
}

AnimationCom::~AnimationCom()
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->removeFromParent();
		m_pAvatarRoot = nullptr;
	}
}

