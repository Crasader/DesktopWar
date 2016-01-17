
#include "PawnActionIdle.h"
#include "ActionDefine.h"

using namespace Genius;

PawnActionIdle::PawnActionIdle()
{
	m_actionType = PAT_Idle;
}

void PawnActionIdle::Reset()
{
	PawnAction::Reset();
}