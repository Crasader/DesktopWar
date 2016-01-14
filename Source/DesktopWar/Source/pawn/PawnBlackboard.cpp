
#include "PawnBlackboard.h"
#include "ECS/components/pawn/ComPawnAgent.h"

using namespace Genius;

PawnBlackboard::PawnBlackboard(ComPawnAgent* agent)
{
	m_pAgent = agent;
	m_currentHP = agent->m_pRoleData->baseLife;
}

PawnBlackboard::~PawnBlackboard()
{

}
















