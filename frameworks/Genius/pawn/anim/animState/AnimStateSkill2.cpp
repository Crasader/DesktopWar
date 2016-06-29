
#include "AnimStateSkill2.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/pawn/ComPawnDirection.h"


using namespace Genius;

AnimStateSkill2::AnimStateSkill2(ComPawnAnim* comAnim) :
AnimState(comAnim)
{

}

AnimStateSkill2::~AnimStateSkill2()
{

}

void AnimStateSkill2::OnActive()
{
	AnimState::OnActive();
}

void AnimStateSkill2::OnDeactive()
{
	AnimState::OnDeactive();
}

void AnimStateSkill2::Update()
{

}

void AnimStateSkill2::Initialize()
{
	AnimState::Initialize();

	PlayAnim();
}

void AnimStateSkill2::PlayAnim()
{
	ComPawnDirection* pComPawnDir = m_pComPawnAnim->GetOwner()->GetComponent<ComPawnDirection>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetSkill2Anim(pComPawnDir->m_currentDir);
	m_pComPawnAnim->PlayAnimation(name);
}