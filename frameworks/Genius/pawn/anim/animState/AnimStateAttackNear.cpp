
#include "AnimStateAttackNear.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/common/ComTransform.h"


using namespace Genius;

AnimStateAttackNear::AnimStateAttackNear(ComPawnAnim* comAnim) :
AnimState(comAnim)
{

}

AnimStateAttackNear::~AnimStateAttackNear()
{

}

void AnimStateAttackNear::OnActive()
{
	AnimState::OnActive();
}

void AnimStateAttackNear::OnDeactive()
{
	AnimState::OnDeactive();
}

void AnimStateAttackNear::Update()
{

}

void AnimStateAttackNear::Initialize()
{
	AnimState::Initialize();

	PlayAnim();
}

void AnimStateAttackNear::PlayAnim()
{
	ComTransform* pComPawnDir = m_pComPawnAnim->GetOwner()->GetComponent<ComTransform>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetAttackNearAnim(pComPawnDir->curDir);
	m_pComPawnAnim->PlayAnimation(name);
}