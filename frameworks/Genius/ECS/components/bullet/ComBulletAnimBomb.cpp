
#include "ComBulletAnimBomb.h"
#include "gfx/gfx.h"
#include "../../core/ECSWorld.h"
#include "event/EventManager.h"
#include "Log.h"
#include "../../EntityEvents.h"

using namespace Genius;
using namespace cocostudio;

const std::string ComBulletAnimBomb::explodeAnimName = "explode";

COM_CREATE_FN_IMPL(ComBulletAnimBomb);

void ComBulletAnimBomb::Create(const std::string& bodyFileName, const std::string& tailFileName)
{
	ComBulletAnimBase::Create(bodyFileName);
	m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(ComBulletAnimBomb::AnimationFrameCallback, this, std::placeholders::_4));
	m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(ComBulletAnimBomb::AnimationMovementCallback, this));

	// 粒子轨迹
	if (tailFileName != "0" && tailFileName != "")
	{
		auto particle = ParticleTail::createWithTotalParticles(30);
		m_pBodyArmature->addChild(particle);
		particle->setTexture(Director::getInstance()->getTextureCache()->addImage(tailFileName));
		particle->setPositionX(-15);
	}
}

void ComBulletAnimBomb::StartExplode()
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

void ComBulletAnimBomb::AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName)
{
	switch (movType)
	{
	case cocostudio::START:
		break;
	case cocostudio::COMPLETE:
		if (animName == explodeAnimName)
			ECSWorld::GetSingleton()->DeleteEntity(GetEntity());
		break;
	case cocostudio::LOOP_COMPLETE:
		if (animName == explodeAnimName)
			ECSWorld::GetSingleton()->DeleteEntity(GetEntity());
		break;
	default:
		break;
	}
}

void ComBulletAnimBomb::AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx)
{
	if (eventName == "buff")
	{
		EventManager::GetSingleton()->FireEvent(BulletTriggerEvent(GetEntity()));
	}
	else
	{
		Log::Warning("unknown frame event.");
	}
}