
#include "AnimState.h"

using namespace Genius;

AnimState::AnimState(ComPawnAnim* comAnim) :
m_isFinished(false),
m_pComPawnAnim(comAnim)
{

}

AnimState::~AnimState()
{

}

void AnimState::Initialize()
{

}

void AnimState::Release()
{
	SetFinished(true);
}

void AnimState::OnActive()
{
	Initialize();
	SetFinished(false);
}

void AnimState::OnDeactive()
{

}

void AnimState::Update()
{

}

bool AnimState::HandleNewAction(PawnAction* pAction)
{
	return false;
}