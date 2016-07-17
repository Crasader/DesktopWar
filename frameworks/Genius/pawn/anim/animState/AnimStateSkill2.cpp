
#include "AnimStateSkill2.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/common/ComTransform.h"


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
	ComTransform* pComPawnDir = m_pComPawnAnim->GetEntity()->GetComponent<ComTransform>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetSkill2Anim(pComPawnDir->curDir);
	m_pComPawnAnim->PlayAnimation(name);
}