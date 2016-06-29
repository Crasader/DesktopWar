
#include "AnimFSM.h"
#include "../animState/AnimState.h"
#include "pawn/action/ActionDefine.h"
#include "pawn/action/PawnAction.h"

using namespace Genius;

AnimFSM::AnimFSM(ComPawnAnim* pComAnim) :
m_pCurrentState(nullptr),
m_pNextState(nullptr),
m_pDefaultState(nullptr),
m_pComPawnAnim(pComAnim)
{
	
}

AnimFSM::~AnimFSM()
{
	Release();
}

void AnimFSM::Initialize()
{
	m_pDefaultState = m_animStateList.find(PAT_Idle) == m_animStateList.end() ? nullptr : m_animStateList[PAT_Idle];
	m_pCurrentState = m_pDefaultState;
}

void AnimFSM::Release()
{
	for (auto iter = m_animStateList.begin(); iter != m_animStateList.end(); ++iter)
	{
		if (iter->second != nullptr)
			delete iter->second;
	}
	m_animStateList.clear();
}

void AnimFSM::UpdateCurrentState()
{
	if (m_pCurrentState != nullptr)
	{
		if (m_pCurrentState->GetFinished())
		{
			m_pCurrentState->OnDeactive();

			m_pCurrentState = m_pDefaultState;

			if (m_pCurrentState != nullptr)
				m_pCurrentState->OnActive();
		}

		m_pCurrentState->Update();
	}
}

void AnimFSM::SwitchToNextState(PawnAction* pAction)
{
	if (m_pCurrentState != nullptr)
		m_pCurrentState->OnDeactive();

	m_pCurrentState = m_pNextState;

	if (m_pCurrentState != nullptr)
		m_pCurrentState->OnActive();
}