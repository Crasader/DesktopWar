// d:)
#include "BulletArrowAnimCom.h"
#include "../../core/ECSWorld.h"

using namespace Genius;
using namespace cocostudio;

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