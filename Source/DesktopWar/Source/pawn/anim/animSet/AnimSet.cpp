
#include "AnimSet.h"
#include <string>
#include "ECS/ecs.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

using namespace Genius;

AnimSet::AnimSet(ComPawnAnim*	pComPawnAnim) :
m_pComPawnAnim(pComPawnAnim)
{
	 
}

AnimSet::~AnimSet()
{

}

bool AnimSet::HaveAnim(const std::string& name)
{
	return m_pComPawnAnim->m_pBodyArmature != nullptr
		&& m_pComPawnAnim->m_pBodyArmature->getAnimation()
		&& m_pComPawnAnim->m_pBodyArmature->getAnimation()->getAnimationData()
		&& m_pComPawnAnim->m_pBodyArmature->getAnimation()->getAnimationData()->getMovement(name) != nullptr;
}