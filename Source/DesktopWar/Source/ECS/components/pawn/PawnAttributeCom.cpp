// d:)
#include "PawnAttributeCom.h"
#include "RoleDataMgr.h"


using namespace Genius;


PawnAttributeCom::PawnAttributeCom(int roleID)
{
	RoleData* roleData = RoleDataMgr::GetSingleton()->GetRoleData(roleID);
	if (roleData)
	{
		curLife = roleData->baseLife;
	}
}

PawnAttributeCom::~PawnAttributeCom()
{
}