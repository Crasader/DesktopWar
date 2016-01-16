
#include "AnimFSM.h"
#include "../animState/AnimState.h"

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
	m_pCurrentState = m_pDefaultState;
}

void AnimFSM::Release()
{
	for (auto iter = m_animStateList.begin(); iter != m_animStateList.end(); ++iter)
	{
		if (*iter != nullptr)
			delete *iter;
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

void AnimFSM::SwitchToNextState()
{
	if (m_pCurrentState != nullptr)
		m_pCurrentState->OnDeactive();

	m_pCurrentState = m_pNextState;

	if (m_pCurrentState != nullptr)
		m_pCurrentState->OnActive();
}