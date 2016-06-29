
#include "PawnActionDie.h"
#include "ActionDefine.h"

using namespace Genius;

PawnActionDie::PawnActionDie()
{
	m_actionType = PAT_Die;
}

void PawnActionDie::Reset()
{
	PawnAction::Reset();
}