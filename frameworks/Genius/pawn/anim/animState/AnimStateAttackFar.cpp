
#include "AnimStateAttackFar.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/common/ComTransform.h"


using namespace Genius;

AnimStateAttackFar::AnimStateAttackFar(ComPawnAnim* comAnim) :
AnimState(comAnim)
{

}

AnimStateAttackFar::~AnimStateAttackFar()
{

}

void AnimStateAttackFar::OnActive()
{
	AnimState::OnActive();
}

void AnimStateAttackFar::OnDeactive()
{
	AnimState::OnDeactive();
}

void AnimStateAttackFar::Update()
{

}

void AnimStateAttackFar::Initialize()
{
	AnimState::Initialize();

	PlayAnim();
}

void AnimStateAttackFar::PlayAnim()
{
	ComTransform* pComPawnDir = m_pComPawnAnim->GetEntity()->GetComponent<ComTransform>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetAttackFarAnim(pComPawnDir->curDir);
	m_pComPawnAnim->PlayAnimation(name);
}