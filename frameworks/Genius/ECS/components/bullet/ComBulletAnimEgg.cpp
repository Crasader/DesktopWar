
#include "ComBulletAnimEgg.h"
#include "../../core/ECSWorld.h"
#include "event/EventManager.h"
#include "Log.h"
#include "../../EntityEvents.h"

using namespace Genius;

COM_CREATE_FN_IMPL(ComBulletAnimEgg);

void ComBulletAnimEgg::Create(const std::string& bodyFileName)
{
	ComBulletAnimBase::Create(bodyFileName);
	m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(ComBulletAnimEgg::AnimationFrameCallback, this, std::placeholders::_4));
	m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(ComBulletAnimEgg::AnimationMovementCallback, this));
}

void ComBulletAnimEgg::AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName)
{
	switch (movType)
	{
	case cocostudio::START:
		break;
	case cocostudio::COMPLETE:
		ECSWorld::GetSingleton()->DeleteEntity(GetEntity());
		break;
	case cocostudio::LOOP_COMPLETE:
		ECSWorld::GetSingleton()->DeleteEntity(GetEntity());
		break;
	default:
		break;
	}
}

void ComBulletAnimEgg::AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx)
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