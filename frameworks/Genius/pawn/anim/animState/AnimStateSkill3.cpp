
#include "AnimStateSkill3.h"
#include "../animSet/AnimSet.h"
#include "ECS/core/Entity.h"
#include "ECS/components/pawn/ComPawnAnim.h"
#include "ECS/components/common/ComTransform.h"


using namespace Genius;

AnimStateSkill3::AnimStateSkill3(ComPawnAnim* comAnim) :
AnimState(comAnim)
{

}

AnimStateSkill3::~AnimStateSkill3()
{

}

void AnimStateSkill3::OnActive()
{
	AnimState::OnActive();
}

void AnimStateSkill3::OnDeactive()
{
	AnimState::OnDeactive();
}

void AnimStateSkill3::Update()
{

}

void AnimStateSkill3::Initialize()
{
	AnimState::Initialize();

	PlayAnim();
}

void AnimStateSkill3::PlayAnim()
{
	ComTransform* pComPawnDir = m_pComPawnAnim->GetOwner()->GetComponent<ComTransform>();
	if (nullptr == pComPawnDir)
		return;

	auto name = m_pComPawnAnim->m_pAnimSet->GetSkill3Anim(pComPawnDir->curDir);
	m_pComPawnAnim->PlayAnimation(name);
}