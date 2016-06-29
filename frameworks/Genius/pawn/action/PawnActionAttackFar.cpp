
#include "PawnActionAttackFar.h"
#include "ActionDefine.h"

using namespace Genius;

PawnActionAttackFar::PawnActionAttackFar()
{
	m_actionType = PAT_AttackFar;
}

void PawnActionAttackFar::Reset()
{
	PawnAction::Reset();
}