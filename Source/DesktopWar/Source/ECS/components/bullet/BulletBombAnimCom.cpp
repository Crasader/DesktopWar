// d:)
#include "BulletBombAnimCom.h"
#include "gfx/gfx.h"
#include "../../core/ECSWorld.h"
#include "event/EventManager.h"
#include "Logger.h"
#include "../../EntityEvents.h"

using namespace Genius;
using namespace cocostudio;

const std::string BulletBombAnimCom::explodeAnimName = "explode";

BulletBombAnimCom::BulletBombAnimCom(const std::string& bodyFileName, const std::string& tailFileName):
	BulletBaseAnimCom(bodyFileName)
{
	m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(BulletBombAnimCom::AnimationFrameCallback, this, std::placeholders::_4));
	m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(BulletBombAnimCom::AnimationMovementCallback, this));

	// 粒子轨迹
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