// d:)
#include "ComPawnAttribute.h"
#include "RoleDataMgr.h"


using namespace Genius;


ComPawnAttribute::ComPawnAttribute(int roleID)
{
	RoleData* roleData = RoleDataMgr::GetSingleton()->GetRoleData(roleID);
	if (roleData)
	{
		curLife = roleData->baseLife;
	}
}

ComPawnAttribute::~ComPawnAttribute()
{
}