
#include "ComBulletAnimArrow.h"
#include "../../core/ECSWorld.h"

using namespace Genius;
using namespace cocostudio;

const std::string ComBulletAnimArrow::stopAnimName = "stop";

void ComBulletAnimArrow::StayStill()
{
	if (m_pBodyArmature)
	{
		ArmatureAnimation* pAnim = m_pBodyArmature->getAnimation();
		if (pAnim)
			pAnim->play(stopAnimName);
	}
}

void ComBulletAnimArrow::Create(const std::string& bodyFileName)
{
	ComBulletAnimBase::Create(bodyFileName);
	m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(ComBulletAnimArrow::AnimationFrameCallback, this, std::placeholders::_4));
	m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(ComBulletAnimArrow::AnimationMovementCallback, this));
}

void ComBulletAnimArrow::AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName)
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

void ComBulletAnimArrow::AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx)
{
	/*if (eventName == "buff")
		EventManager::GetSingleton()->FireEvent(BulletHitEvent(this->GetOwner()));*/
}