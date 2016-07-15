
#include "AnimStateIdle.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/common/ComTransform.h"


using namespace Genius;

AnimStateIdle::AnimStateIdle(ComPawnAnim* comAnim) :
AnimState(comAnim)
{

}

AnimStateIdle::~AnimStateIdle()
{

}

void AnimStateIdle::OnActive()
{
	AnimState::OnActive();
}

void AnimStateIdle::OnDeactive()
{
	AnimState::OnDeactive();
}

void AnimStateIdle::Update()
{

}

void AnimStateIdle::Initialize()
{
	AnimState::Initialize();

	PlayAnim();
}

void AnimStateIdle::PlayAnim()
{
	ComTransform* pComPawnDir = m_pComPawnAnim->GetOwner()->GetComponent<ComTransform>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetIdleAnim(pComPawnDir->curDir);
	m_pComPawnAnim->PlayAnimation(name);
}