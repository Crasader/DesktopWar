// d:)
#include "ComPawnAgent.h"
#include "RoleDataMgr.h"
#include "pawn/PawnBlackboard.h"


using namespace Genius;


ComPawnAgent::ComPawnAgent(int roleID)
{
	RoleData* info = RoleDataMgr::GetSingleton()->GetRoleData(roleID);
	pRoleData = info;
}