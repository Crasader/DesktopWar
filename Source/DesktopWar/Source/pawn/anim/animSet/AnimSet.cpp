
#include "AnimSet.h"
#include <string>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace Genius;

AnimSet::AnimSet(Armature* armature):
m_pArmature(armature)
{
	 
}

AnimSet::~AnimSet()
{

}

bool AnimSet::HaveAnim(const char* name)
{
	return m_pArmature != nullptr
		&& m_pArmature->getAnimation()
		&& m_pArmature->getAnimation()->getAnimationData()
		&& m_pArmature->getAnimation()->getAnimationData()->getMovement(name) != nullptr;
}