

#include "entityCreators.h"
#include "ECS/ecs.h"
#include "data/auto/Role_cfg.hpp"
#include "data/auto/Bullet_cfg.hpp"
#include "data/auto/Animation_cfg.hpp"
#include "data/ConfigPool.h"
#include "bullet/BulletDefines.h"
#include "Log.h"
#include "app/Config.h"
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

	/*Role_cfg* roleInfo = FIND_CFG(Role_cfg, id);
	if (nullptr == roleInfo)
	{
		Log::Warning("error role type : %d", id);
		return;
	}

	Entity* ent = ECSWorld::GetSingleton()->GetEntityManager()->Create();

	auto agent = new ComPawnAgent();
	agent->Create(id, true);
	ent->AddComponent(agent);

	auto pos = new ComTransform();
	pos->x = x; pos->y = y;
	pos->vx = 0; pos->vy = 0;
	ent->AddComponent(pos);

	auto render = new ComRenderRoot();
	ent->AddComponent(render);

	ComPawnAnim* paCom = new ComPawnAnim();
	ent->AddComponent(paCom);
	paCom->Create(id);

	float width = paCom->GetWidth()*0.5f;
	float height = paCom->GetHeight()*0.7f;
	auto box = new ComBoxCollider();
	box->Create(true, 0, height*0.5f, width, height);
	ent->AddComponent(box);

	auto bev = new ComPawnBevtree();
	bev->Create(roleInfo->bevTreeFile);
	ent->AddComponent(bev);

	ent->AddComponent(new ComPawnNavigation());

	ent->AddComponent(new ComPawnFight());

	//if (cfg_EnableDebugDraw)
	//{
		auto dd = new ComPawnDebugDraw();
		ent->AddComponent(dd);
		dd->Create();
	//}

	ECSWorld::GetSingleton()->AddTag(ent, tag);
	
	ent->Refresh();
	*/

}

void EntityCreator::CreateBullet(int bulletID, int targetEntityID, float x, float y, const std::string& tag, float destX, float destY)
{
	char excString[256];
	sprintf_s(excString, "SpawnBullet(%d,%d,%f,%f,\"%s\",%f,%f)", bulletID, targetEntityID, x, y, tag.c_str(), destX, destY);
	ScriptingCore::getInstance()->evalString(excString);

	/*Bullet_cfg* bulletCfg = FIND_CFG(Bullet_cfg, bulletID);
	if (nullptr == bulletCfg)
	{
		Log::Warning("error bullet id : %d", bulletID);
		return;
	}

	auto anim_cfg = FIND_CFG(Animation_cfg, bulletCfg->bodyAnim);
	if (nullptr == anim_cfg)
	{
		Log::Warning("error bullet anim id : %d", bulletID);
		return;
	}

	Entity* ent = ECSWorld::GetSingleton()->GetEntityManager()->Create();

	auto agent = new ComPawnAgent();
	agent->Create(bulletID, false);
	ent->AddComponent(agent);

	auto pos = new ComTransform();
	pos->x = x; pos->y = y;
	ent->AddComponent(pos);

	auto render = new ComRenderRoot();
	ent->AddComponent(render);

	auto box = new ComBoxCollider();
	box->Create(false, 0, 0, bulletCfg->boxWidth, bulletCfg->boxHeight);
	ent->AddComponent(box);

	auto damage = new ComBulletDamage();
	ent->AddComponent(damage);

	if (cfg_EnableDebugDraw) ent->AddComponent(new ComBulletDebugDraw());
	
	if (bulletCfg->moveType == BulletMoveType::BMT_Line)
	{
		pos->vx = 0; pos->vy = 0;

		auto baegg = new ComBulletAnimEgg();
		ent->AddComponent(baegg);
		baegg->Create(anim_cfg->name);
		
	}
	else if (bulletCfg->moveType == BulletMoveType::BMT_Bezier)
	{
		pos->vx = 0; pos->vy = 0;

		ent->AddComponent(new ComDirection());

		auto bez = new ComBezierMovement();
		ent->AddComponent(bez);
		bez->Create(x, y, destX, destY, (abs(x - destX) + abs(y - destY)) / bulletCfg->flySpeed);
		
		damage->targetID = targetEntityID;
		
		auto banim = new ComBulletAnimArrow();
		ent->AddComponent(banim);
		banim->Create(anim_cfg->name);

		agent->GetBlackboard()->targetType = Target_Location;
		agent->GetBlackboard()->targetX = destX;
		agent->GetBlackboard()->targetY = destY;

	}
	else if(bulletCfg->moveType == BulletMoveType::BMT_Tracking)
	{
		ent->AddComponent(new ComDirection());

		SystemPawnFight* fightSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemPawnFight>();
		string targetTag = GameDefine::Tag_Soldier;
		int tarEntityID = fightSys->FindRandTargetByTag(targetTag);
		pos->vx = 0; pos->vy = bulletCfg->flySpeed;

		auto delayTrack = new ComDelayTrackMoving();
		delayTrack->Create(tarEntityID, bulletCfg->findTargetDelay);
		ent->AddComponent(delayTrack);

		auto bom = new ComBulletAnimBomb();
		ent->AddComponent(bom);
		bom->Create(anim_cfg->name, bulletCfg->tailAnim);
		
		agent->GetBlackboard()->targetType = Target_Entity;
		agent->GetBlackboard()->targetID = tarEntityID;
	}
	
	ent->Refresh();
	*/
}

