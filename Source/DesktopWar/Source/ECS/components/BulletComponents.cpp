// d:)
#include "BulletComponents.h"
#include "data/BulletDataMgr.h"
#include "../Entity.h"
#include "../ECSWorld.h"
#include "Logger.h"
#include "../EntityEvents.h"
#include "event/EventManager.h"

USING_NS_CC;
using namespace cocostudio;
using namespace Genius;

/************************************************************************/
/*                                                BulletNormalAnimCom                      */
/************************************************************************/
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

/************************************************************************/
/*                                                BulletArrowAnimCom                      */
/************************************************************************/
const std::string BulletArrowAnimCom::stopAnimName = "stop";

void BulletArrowAnimCom::StayStill()
{
	if (m_pBodyArmature)
	{
		ArmatureAnimation* pAnim = m_pBodyArmature->getAnimation();
		if (pAnim)
			pAnim->play(stopAnimName);
	}
}

BulletArrowAnimCom::BulletArrowAnimCom(const std::string& bodyFileName):
	BulletBaseAnimCom(bodyFileName)
{
	m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(BulletArrowAnimCom::AnimationFrameCallback, this, std::placeholders::_4));
	m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(BulletArrowAnimCom::AnimationMovementCallback, this));
}

void BulletArrowAnimCom::AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName)
{
	switch (movType)
	{
	case cocostudio::START:
		break;
	case cocostudio::COMPLETE:
		if (animName == stopAnimName)
			ECSWorld::GetSingleton()->DeleteEntity(GetOwner());
		break;
	case cocostudio::LOOP_COMPLETE:
		if (animName == stopAnimName)
			ECSWorld::GetSingleton()->DeleteEntity(GetOwner());
		break;
	default:
		break;
	}
}

void BulletArrowAnimCom::AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx)
{
	/*if (eventName == "buff")
		EventManager::GetInstance().FireEvent(BulletHitEvent(this->GetOwner()));*/
}

/************************************************************************/
/*                                                BulletBombAnimCom                      */
/************************************************************************/
const std::string BulletBombAnimCom::explodeAnimName = "explode";

BulletBombAnimCom::BulletBombAnimCom(const std::string& bodyFileName, const std::string& tailFileName):
	BulletBaseAnimCom(bodyFileName)
{
	m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(BulletBombAnimCom::AnimationFrameCallback, this, std::placeholders::_4));
	m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(BulletBombAnimCom::AnimationMovementCallback, this));

	// Á£×Ó¹ì¼£
	if (tailFileName != "0" && tailFileName != "")
	{
		auto particle = ParticleTail::createWithTotalParticles(30);
		m_pBodyArmature->addChild(particle);
		particle->setTexture(Director::getInstance()->getTextureCache()->addImage(tailFileName));
		particle->setPositionX(-15);
	}
}

void BulletBombAnimCom::StartExplode()
{
	if (m_pBodyArmature)
	{
		ArmatureAnimation* pAnim = m_pBodyArmature->getAnimation();
		if (pAnim)
		{
			m_pBodyArmature->setRotation(0);
			pAnim->play("explode");
		}
	}
}

void BulletBombAnimCom::AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName)
{
	switch (movType)
	{
	case cocostudio::START:
		break;
	case cocostudio::COMPLETE:
		if (animName == explodeAnimName)
			ECSWorld::GetSingleton()->DeleteEntity(GetOwner());
		break;
	case cocostudio::LOOP_COMPLETE:
		if (animName == explodeAnimName)
			ECSWorld::GetSingleton()->DeleteEntity(GetOwner());
		break;
	default:
		break;
	}
}

void BulletBombAnimCom::AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx)
{
	if (eventName == "buff")
	{
		EventManager::GetInstance().FireEvent(BulletTriggerEvent(GetOwner()));
	}
	else
	{
		Logger::LogWarning("unknown frame event.");
	}
}

/************************************************************************/
/*                                                BulletEggAnimCom                      */
/************************************************************************/
BulletEggAnimCom::BulletEggAnimCom(const std::string& bodyFileName):
	BulletBaseAnimCom(bodyFileName)
{
	m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(BulletEggAnimCom::AnimationFrameCallback, this, std::placeholders::_4));
	m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(BulletEggAnimCom::AnimationMovementCallback, this));
}

void BulletEggAnimCom::AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName)
{
	switch (movType)
	{
	case cocostudio::START:
		break;
	case cocostudio::COMPLETE:
		ECSWorld::GetSingleton()->DeleteEntity(GetOwner());
		break;
	case cocostudio::LOOP_COMPLETE:
		ECSWorld::GetSingleton()->DeleteEntity(GetOwner());
		break;
	default:
		break;
	}
}

void BulletEggAnimCom::AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx)
{
	if (eventName == "buff")
	{
		EventManager::GetInstance().FireEvent(BulletTriggerEvent(GetOwner()));
	}
	else
	{
		Logger::LogWarning("unknown frame event.");
	}
}

/************************************************************************/
/*                                                BulletTemplateCom                      */
/************************************************************************/
BulletTemplateCom::BulletTemplateCom(BulletData* _bulletInfo):
pBulletData(_bulletInfo)
{}

/************************************************************************/
/*                                     BulletDebugDrawCom                                 */
/************************************************************************/
BulletDebugDrawCom::BulletDebugDrawCom()
{
	pRoot = Node::create();
	pNodeBoxCollider = DrawNode::create();
	pNodeHurtRange = DrawNode::create();
	pRoot->addChild(pNodeBoxCollider);
	pRoot->addChild(pNodeHurtRange);
	SceneManager::GetInstance().AddToMapLayer(pRoot);
}

BulletDebugDrawCom::~BulletDebugDrawCom()
{
	pRoot->removeFromParent();
}

void BulletDebugDrawCom::Clear()
{
	pNodeBoxCollider->clear();
	pNodeHurtRange->clear();
}