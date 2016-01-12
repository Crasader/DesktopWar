// d:)
#include "CommonCom.h"
#include "../core/ECSWorld.h"

using namespace Genius;
USING_NS_CC;

/************************************************************************/
/*                                     SimpleAnimationCom                                 */
/************************************************************************/
SimpleAnimationCom::SimpleAnimationCom(const std::string& fileName)
{
	m_pAvatarRoot = cocos2d::Node::create();
	m_pBodyArmature = cocostudio::Armature::create(fileName);
	m_pAvatarRoot->addChild(m_pBodyArmature);
	SceneManager::GetInstance().AddToMapLayer(m_pAvatarRoot);
	m_pBodyArmature->getAnimation()->playWithIndex(0);
}

SimpleAnimationCom::~SimpleAnimationCom()
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->removeFromParent();
		m_pAvatarRoot = nullptr;
	}
}

/************************************************************************/
/*                                     ParticleCom                                 */
/************************************************************************/
ParticleCom::ParticleCom(const std::string& fileName)
{
	auto smoke = ParticleSmoke::create();
	smoke->setTexture(Director::getInstance()->getTextureCache()->addImage(fileName));
	smoke->setPosition(Vec2(0, 0));
	smoke->setTotalParticles(130);
	smoke->setLife(2.0f);

	m_pAvatarRoot = cocos2d::Node::create();
	m_pAvatarRoot->addChild(smoke);

	SceneManager::GetInstance().AddToMapLayer(m_pAvatarRoot);
}

ParticleCom::~ParticleCom()
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->removeFromParent();
		m_pAvatarRoot = nullptr;
	}
}

/************************************************************************/
/*                                     DelayTrackMovingCom                                 */
/************************************************************************/
bool DelayTrackMovingCom::Init()
{
	Entity* pTarEntity = ECSWorld::GetSingleton()->GetEntity(targetEntityID);
	if (pTarEntity)
	{
		PositionCom* pTarPosCom = pTarEntity->GetComponent<PositionCom>();
		if (pTarPosCom)
		{
			targetCachePosX = pTarPosCom->x;
			targetCachePosY = pTarPosCom->y;
		}
	}
	return Component::Init();
}