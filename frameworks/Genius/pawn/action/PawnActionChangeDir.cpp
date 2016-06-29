
#include "PawnActionChangeDir.h"
#include "ActionDefine.h"

using namespace Genius;

PawnActionChangeDir::PawnActionChangeDir()
{
	m_actionType = PAT_ChangeDir;
}

void PawnActionChangeDir::Reset()
{
	PawnAction::Reset();
}