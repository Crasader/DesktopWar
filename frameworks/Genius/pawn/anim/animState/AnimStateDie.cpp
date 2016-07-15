
#include "AnimStateDie.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/common/ComTransform.h"


using namespace Genius;

AnimStateDie::AnimStateDie(ComPawnAnim* comAnim) :
AnimState(comAnim)
{

}

AnimStateDie::~AnimStateDie()
{

}

void AnimStateDie::OnActive()
{
	AnimState::OnActive();
}

void AnimStateDie::OnDeactive()
{
	AnimState::OnDeactive();
}

void AnimStateDie::Update()
{

}

void AnimStateDie::Initialize()
{
	AnimState::Initialize();

	PlayAnim();
}

void AnimStateDie::PlayAnim()
{
	ComTransform* pComPawnDir = m_pComPawnAnim->GetOwner()->GetComponent<ComTransform>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetDieAnim(pComPawnDir->curDir);
	m_pComPawnAnim->PlayAnimation(name);
}