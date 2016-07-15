
#include "ComBulletAgent.h"
#include "data/auto/Bullet_cfg.hpp"
#include "pawn/PawnBlackboard.h"


using namespace Genius;
using namespace cfg;


COM_CREATE_FN_IMPL(ComBulletAgent);

void ComBulletAgent::Create(Bullet_cfg* pData)
{
	pBulletData = pData;
}