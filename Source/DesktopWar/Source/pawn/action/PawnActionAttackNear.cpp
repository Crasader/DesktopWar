
#include "PawnActionAttackNear.h"
#include "ActionDefine.h"

using namespace Genius;

PawnActionAttackNear::PawnActionAttackNear()
{
	m_actionType = PAT_AttackNear;
}

void PawnActionAttackNear::Reset()
{
	PawnAction::Reset();
}