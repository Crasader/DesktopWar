// d:)
#include "BulletEggAnimCom.h"
#include "../../core/ECSWorld.h"
#include "event/EventManager.h"
#include "Logger.h"
#include "../../EntityEvents.h"

using namespace Genius;

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