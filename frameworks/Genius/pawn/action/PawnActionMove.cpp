
#include "PawnActionMove.h"
#include "ActionDefine.h"

using namespace Genius;

PawnActionMove::PawnActionMove()
{
	m_actionType = PAT_Move;
}

void PawnActionMove::Reset()
{
	PawnAction::Reset();
}