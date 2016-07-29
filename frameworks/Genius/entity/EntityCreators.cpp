

#include "entityCreators.h"
#include "ECS/ecs.h"
#include "data/auto/Role_cfg.hpp"
#include "data/auto/Bullet_cfg.hpp"
#include "data/auto/Animation_cfg.hpp"
#include "data/ConfigPool.h"
#include "entity/BulletDefines.h"
#include "Log.h"

#include "app/GameDefine.h"
#include "pawn/PawnBlackboard.h"

#include "scripting/js-bindings/manual/ScriptingCore.h"

using namespace Genius;
using namespace cfg;


void EntityCreator::CreatePawn(int id, float x, float y, const std::string& tag)
{
	char excString[256];
	sprintf_s(excString, "SpawnPawn(%d,%f,%f,\"%s\")", id, x, y, tag.c_str());
	ScriptingCore::getInstance()->evalString(excString);
}

void EntityCreator::CreateBullet(int bulletID, int targetEntityID, float x, float y, const std::string& tag, float destX, float destY)
{
	char excString[256];
	sprintf_s(excString, "SpawnBullet(%d,%d,%f,%f,\"%s\",%f,%f)", bulletID, targetEntityID, x, y, tag.c_str(), destX, destY);
	ScriptingCore::getInstance()->evalString(excString);
}

