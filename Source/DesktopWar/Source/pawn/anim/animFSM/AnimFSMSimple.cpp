
#include "AnimFSMSimple.h"
#include "../animState/AnimStateIdle.h"
#include "pawn/action/ActionDefine.h"
#include "pawn/action/PawnAction.h"

using namespace Genius;

AnimFSMSimple::AnimFSMSimple(ComPawnAnim* pComPawnAnim) :
AnimFSM(pComPawnAnim)
{
	
}

AnimFSMSimple::~AnimFSMSimple()
{

}

void AnimFSMSimple::Initialize()
{
	Release();

	m_animStateList.insert(std::make_pair(PAT_Idle, new AnimStateIdle(m_pComPawnAnim)));

	AnimFSM::Initialize();
}

void AnimFSMSimple::DoAction(PawnAction* pAction)
{
	if (m_pCurrentState->HandleNewAction(pAction))
	{
		m_pNextState = nullptr;
	}
	else
	{
		int actType = pAction->GetType();

		switch (actType)
		{
		case PAT_Idle:
			m_pNextState = m_animStateList[actType];
			break;

		default:
			break;
		}

		if (m_pNextState != nullptr)
		{
			SwitchToNextState(pAction);
		}

	}
}