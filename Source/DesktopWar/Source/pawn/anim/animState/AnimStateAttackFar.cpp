
#include "AnimStateAttackFar.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/pawn/ComPawnDirection.h"


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
	ComPawnDirection* pComPawnDir = m_pComPawnAnim->GetOwner()->GetComponent<ComPawnDirection>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetAttackFarAnim(pComPawnDir->m_currentDir);
	m_pComPawnAnim->PlayAnimation(name);
}