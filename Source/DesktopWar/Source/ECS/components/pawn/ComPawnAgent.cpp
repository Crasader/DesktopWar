
#include "ComPawnAgent.h"
#include "RoleDataMgr.h"
#include "pawn/PawnBlackboard.h"


using namespace Genius;


ComPawnAgent::ComPawnAgent(RoleData* pData)
{
	m_pRoleData = pData;

	m_pBlackboard = new PawnBlackboard(this);
}

ComPawnAgent::~ComPawnAgent()
{
	if (m_pBlackboard)
		delete m_pBlackboard;
}