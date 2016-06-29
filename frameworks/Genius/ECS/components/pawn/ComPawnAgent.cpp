
#include "ComPawnAgent.h"
#include "RoleDataMgr.h"
#include "pawn/PawnBlackboard.h"
#include "pawn/action/PawnActionFactory.h"


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

void ComPawnAgent::AddAction(int type)
{
	if (m_pBlackboard != nullptr)
	{
		PawnAction* pAction = PawnActionFactory::GetSingleton()->CreatePawnAction(type);

		m_pBlackboard->AddAction(pAction);
	}
}