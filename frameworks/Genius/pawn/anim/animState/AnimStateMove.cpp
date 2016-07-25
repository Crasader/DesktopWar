
#include "AnimStateMove.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/common/ComTransform.h"


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
	ComTransform* pComPawnDir = m_pComPawnAnim->GetEntity()->GetComponent<ComTransform>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetMoveAnim(pComPawnDir->curDir);
	if (m_pComPawnAnim->m_curAnimName != name)
		m_pComPawnAnim->PlayAnimation(name);
}