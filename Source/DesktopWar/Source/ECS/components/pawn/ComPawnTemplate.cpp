// d:)
#include "ComPawnTemplate.h"
#include "RoleDataMgr.h"


using namespace Genius;


ComPawnTemplate::ComPawnTemplate(int roleID)
{
	RoleData* info = RoleDataMgr::GetSingleton()->GetRoleData(roleID);
	pRoleData = info;
}