
#include "AnimStateSkill1.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/common/ComTransform.h"


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
	ComTransform* pComPawnDir = m_pComPawnAnim->GetEntity()->GetComponent<ComTransform>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetSkill1Anim(pComPawnDir->curDir);
	m_pComPawnAnim->PlayAnimation(name);
}