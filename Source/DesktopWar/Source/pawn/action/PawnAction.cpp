
#include "PawnAction.h"

using namespace Genius;

PawnAction::PawnAction() :
m_currentState(PAS_Active)
{
	
}

PawnAction::~PawnAction()
{

}

void PawnAction::Reset()
{
	m_currentState = PAS_Unused;
}