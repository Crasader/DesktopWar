

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

using namespace Genius;
using namespace cfg;


int EntityCreator::CreatePawn(int id, float x, float y, const std::string& tag)
{
	Role_cfg* roleInfo = FIND_CFG(Role_cfg, id);
	if (nullptr == roleInfo)
	{
		Log::Warning("error role type : %d", id);
		return 0;
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
	box->Create(false, 0, height*0.5f, width, height);
	ent->AddComponent(box);

	auto han = new ComColliderHandler();
	han->Create(nullptr, nullptr);
	ent->AddComponent(han);

	auto bev = new ComPawnBevtree();
	bev->Create(roleInfo->bevTreeFile);
	ent->AddComponent(bev);

	ent->AddComponent(new ComPawnNavigation());

	ent->AddComponent(new ComPawnFight());

	if (cfg_EnableDebugDraw)
	{
		auto dd = new ComPawnDebugDraw();
		dd->Create();
		ent->AddComponent(dd);
	}

	/*if (tag == GameDefine::Tag_Soldier)
	{
		ECSWorld::GetSingleton()->GetGroupManager()->Set(GameDefine::Tag_Soldier, ent);
	}
	else if (tag == GameDefine::Tag_Soldier)
	{
		ECSWorld::GetSingleton()->GetGroupManager()->Set(GameDefine::Tag_Monster, ent);
	}*/
	
	ent->Refresh();

	return ent->GetId();
}

int EntityCreator::CreateBullet(int bulletID, int targetEntityID, float x, float y, const std::string& tag, float destX, float destY)
{
	Bullet_cfg* bulletCfg = FIND_CFG(Bullet_cfg, bulletID);
	if (nullptr == bulletCfg)
	{
		Log::Warning("error bullet id : %d", bulletID);
		return 0;
	}

	auto anim_cfg = FIND_CFG(Animation_cfg, bulletCfg->bodyAnim);
	if (nullptr == anim_cfg)
	{
		Log::Warning("error bullet anim id : %d", bulletID);
		return 0;
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
	box->Create(true, 0, 0, bulletCfg->boxWidth, bulletCfg->boxHeight);
	ent->AddComponent(box);

	if (cfg_EnableDebugDraw) ent->AddComponent(new ComBulletDebugDraw());
	
	if (bulletCfg->moveType == BulletMoveType::BMT_Line)
	{
		pos->vx = 0; pos->vy = 0;
		ent->AddComponent(new ComBulletDamageNone());

		auto baegg = new ComBulletAnimEgg();
		ent->AddComponent(baegg);
		baegg->Create(anim_cfg->name);
		
	}
	else if (bulletCfg->moveType == BulletMoveType::BMT_Bezier)
	{
		pos->vx = 0; pos->vy = 0;
// 		auto targ = new ComTarget();
// 		targ->Create(Target_Location, 0, destX, destY);
// 		ent->AddComponent(targ);
		auto bez = new ComBezierMovement();
		ent->AddComponent(bez);
		bez->Create(x, y, destX, destY, (abs(x - destX) + abs(y - destY)) / bulletCfg->flySpeed);
		
		auto dmgs = new ComBulletDamageSingle();
		ent->AddComponent(dmgs);
		dmgs->targetID = targetEntityID;
		
		auto banim = new ComBulletAnimArrow();
		ent->AddComponent(banim);
		banim->Create(anim_cfg->name);
		
		SystemBulletDamageSingle* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemBulletDamageSingle>();
		auto han = new ComColliderHandler();
		ent->AddComponent(han);
		han->Create(std::bind(&SystemBulletDamageSingle::collisionHandler, atkSys, std::placeholders::_1, std::placeholders::_2), nullptr);
		
	}
	else if(bulletCfg->moveType == BulletMoveType::BMT_Tracking)
	{
		SystemPawnFight* fightSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemPawnFight>();
		int tarEntityID = fightSys->FindRandTargetByTag(tag);
		pos->vx = 0; pos->vy = bulletCfg->flySpeed;

// 		auto targ = new ComTarget();
// 		targ->Create(Target_Entity, tarEntityID);
// 		ent->AddComponent(targ);
		auto delayTrack = new ComDelayTrackMoving();
		ent->AddComponent(delayTrack);
		delayTrack->Create(tarEntityID, bulletCfg->findTargetDelay);
		
		ent->AddComponent(new ComBulletDamageScope());

		auto bom = new ComBulletAnimBomb();
		ent->AddComponent(bom);
		bom->Create(anim_cfg->name, bulletCfg->tailAnim);
		
		SystemBulletDamageScope* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemBulletDamageScope>();
		auto han = new ComColliderHandler();
		ent->AddComponent(han);
		han->Create(std::bind(&SystemBulletDamageScope::OnCollision, atkSys, std::placeholders::_1, std::placeholders::_2), nullptr);
		
	}
	
	ent->Refresh();
	return ent->GetId();
}

