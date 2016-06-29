
#include "AnimStateSkill1.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/pawn/ComPawnDirection.h"


using namespace Genius;

AnimStateSkill1::AnimStateSkill1(ComPawnAnim* comAnim) :
AnimState(comAnim)
{

}

AnimStateSkill1::~AnimStateSkill1()
{

}

void AnimStateSkill1::OnActive()
{
	AnimState::OnActive();
}

void AnimStateSkill1::OnDeactive()
{
	AnimState::OnDeactive();
}

void AnimStateSkill1::Update()
{

}

void AnimStateSkill1::Initialize()
{
	AnimState::Initialize();

	PlayAnim();
}

void AnimStateSkill1::PlayAnim()
{
	ComPawnDirection* pComPawnDir = m_pComPawnAnim->GetOwner()->GetComponent<ComPawnDirection>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetSkill1Anim(pComPawnDir->m_currentDir);
	m_pComPawnAnim->PlayAnimation(name);
}