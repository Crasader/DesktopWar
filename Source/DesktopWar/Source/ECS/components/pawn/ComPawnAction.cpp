// d:)
#include "ComPawnAction.h"
#include "pawn/PawnDefines.h"

using namespace Genius;


ComPawnAction::ComPawnAction(unsigned int act)
{
	m_curAction = Action_Idle;
	if (act > Action_Min && act < Action_Max)
		m_curAction = act;
};

void ComPawnAction::StartAction(unsigned int act)
{
	if (act <= Action_Min || act >= Action_Max)
		return;

	m_curAction = act;
	/*switch (act)
	{
	case Action_Idle:
		break;
	case Action_Move:
		break;
	case Action_Attack_Near:
		break;
	case Action_Skill1:
		break;
	case Action_Die:
		break;
	default:
		printf("unknown action\n");
		break;
	}*/
}