
#include "AnimFSMSimple.h"
#include "../animState/AnimStateIdle.h"

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
	m_animStateList.push_back(new AnimStateIdle(m_pComPawnAnim));
}

void AnimFSMSimple::DoAction(PawnAction* pAction)
{
	if (CurrentAnimState.HandleNewAction(action) == true)
	{
		//Debug.Log("AC - Do Action " + action.ToString());
		NextAnimState = null;
	}
	else
	{
		if (action is AgentActionGoTo)
			NextAnimState = AnimStates[(int)E_MyAnimState.gotoPos];
		if (action is AgentActioCombatMove)
			NextAnimState = AnimStates[(int)E_MyAnimState.combatMove];
		else if (action is AgentActionRotate)
			NextAnimState = AnimStates[(int)E_MyAnimState.Rotate];
		else if (action is AgentActionAttack)
			NextAnimState = AnimStates[(int)E_MyAnimState.attack];
		else if (action is AgentActionWeaponShow)
			NextAnimState = AnimStates[(int)E_MyAnimState.idle];
		else if (action is AgentActionPlayAnim || action is AgentActionPlayIdleAnim)
			NextAnimState = AnimStates[(int)E_MyAnimState.playAnim];
		else if (action is AgentActionInjury)
			NextAnimState = AnimStates[(int)E_MyAnimState.injury];
		else if (action is AgentActionKnockdown)
			NextAnimState = AnimStates[(int)E_MyAnimState.knockdown];
		else if (action is AgentActionDeath)
			NextAnimState = AnimStates[(int)E_MyAnimState.death];


		ProgressToNextStage(action);

	}
}