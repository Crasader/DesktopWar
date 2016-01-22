
#include "AnimFSMSimple.h"
#include "../animState/AnimStateIdle.h"
#include "../animState/AnimStateDie.h"
#include "../animState/AnimStateMove.h"
#include "../animState/AnimStateAttackNear.h"
#include "../animState/AnimStateAttackFar.h"
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
	m_animStateList.insert(std::make_pair(PAT_Die, new AnimStateDie(m_pComPawnAnim)));
	m_animStateList.insert(std::make_pair(PAT_Move, new AnimStateMove(m_pComPawnAnim)));
	m_animStateList.insert(std::make_pair(PAT_AttackNear, new AnimStateAttackNear(m_pComPawnAnim)));
	m_animStateList.insert(std::make_pair(PAT_AttackFar, new AnimStateAttackFar(m_pComPawnAnim)));

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
		case PAT_Die:
			m_pNextState = m_animStateList[actType];
			break;
		case PAT_Move:
			m_pNextState = m_animStateList[actType];
			break;
		case PAT_AttackNear:
			m_pNextState = m_animStateList[actType];
			break;
		case PAT_AttackFar:
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