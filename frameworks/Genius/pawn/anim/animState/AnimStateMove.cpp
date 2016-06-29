
#include "AnimStateMove.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/pawn/ComPawnDirection.h"


using namespace Genius;

AnimStateMove::AnimStateMove(ComPawnAnim* comAnim) :
AnimState(comAnim)
{

}

AnimStateMove::~AnimStateMove()
{

}

void AnimStateMove::OnActive()
{
	AnimState::OnActive();
}

void AnimStateMove::OnDeactive()
{
	AnimState::OnDeactive();
}

void AnimStateMove::Update()
{

}

void AnimStateMove::Initialize()
{
	AnimState::Initialize();

	PlayAnim();
}

void AnimStateMove::PlayAnim()
{
	ComPawnDirection* pComPawnDir = m_pComPawnAnim->GetOwner()->GetComponent<ComPawnDirection>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetMoveAnim(pComPawnDir->m_currentDir);
	m_pComPawnAnim->PlayAnimation(name);
}