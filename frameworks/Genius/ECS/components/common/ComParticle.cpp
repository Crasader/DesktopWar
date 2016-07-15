
#include "ComParticle.h"
#include "../../core/ECSWorld.h"

using namespace Genius;
USING_NS_CC;


COM_CREATE_FN_IMPL(ComParticle);

void ComParticle::Create(const std::string& fileName)
{
	auto smoke = ParticleSmoke::create();
	smoke->setTexture(Director::getInstance()->getTextureCache()->addImage(fileName));
	smoke->setPosition(Vec2(0, 0));
	smoke->setTotalParticles(130);
	smoke->setLife(2.0f);

	m_pAvatarRoot = cocos2d::Node::create();
	m_pAvatarRoot->addChild(smoke);

	SceneManager::GetSingleton()->AddToMapLayer(m_pAvatarRoot);
}

ComParticle::~ComParticle()
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->removeFromParent();
		m_pAvatarRoot = nullptr;
	}
}
