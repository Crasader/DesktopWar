// d:)
#include "PawnTemplateCom.h"
#include "RoleDataMgr.h"


using namespace Genius;


PawnTemplateCom::PawnTemplateCom(int roleID)
{
	RoleData* info = RoleDataMgr::GetSingleton()->GetRoleData(roleID);
	pRoleData = info;
}