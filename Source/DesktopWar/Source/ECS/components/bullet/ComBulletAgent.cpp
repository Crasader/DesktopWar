// d:)
#include "ComBulletAgent.h"
#include "BulletDataMgr.h"
#include "pawn/PawnBlackboard.h"


using namespace Genius;


ComBulletAgent::ComBulletAgent(int roleID)
{
	BulletData* info = BulletDataMgr::GetSingleton()->GetBulletData(roleID);
	pBulletData = info;
}