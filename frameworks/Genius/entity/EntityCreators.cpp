

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


int EntityCreator::CreatePawn(int id, float x, float y, int team)
{
	Role_cfg* roleInfo = FIND_CFG(Role_cfg, id);
	if (nullptr == roleInfo)
	{
		Log::Warning("error role type : %d", id);
		return 0;
	}

	Entity* ent = ECSWorld::GetSingleton()->GetEntityManager()->Create();
	auto agent = new ComPawnAgent();
	agent->Create(id);
	ent->AddComponent(agent);

	auto pos = new ComTransform();
	pos->x = x; pos->y = y;
	pos->vx = 0; pos->vy = 0;
	ent->AddComponent(pos);
	//auto tm = new ComTeam();
	//tm->team = team;
	//ent->AddComponent(tm);
// 	auto targ = new ComTarget();
// 	targ->Create(Target_Entity);
// 	ent->AddComponent(targ);
	ComPawnAnim* paCom = new ComPawnAnim();
	paCom->Create(id);
	ent->AddComponent(paCom);
	float width = paCom->GetWidth()*0.5f;
	float height = paCom->GetHeight()*0.7f;
	auto box = new ComBoxCollider();
	box->Create(false, 0, height*0.5f, width, height);
	ent->AddComponent(box);
	auto han = new ComColliderHandler();
	han->Create(nullptr, nullptr);
	ent->AddComponent(han);
	ent->AddComponent(new ComTransform());
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

	if (team == Team_Human)
	{
		ECSWorld::GetSingleton()->GetGroupManager()->Set(GameDefine::Tag_Soldier, ent);
	}
	else if (team == Team_Monster)
	{
		ECSWorld::GetSingleton()->GetGroupManager()->Set(GameDefine::Tag_Monster, ent);
	}
	
	ent->Refresh();

	return ent->GetId();
}

int EntityCreator::CreateBullet(int bulletID, int targetEntityID, float x, float y, int team, float destX, float destY)
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
// 	auto bagent = new ComPawnAgent();
// 	bagent->Create(bulletCfg);
// 	ent->AddComponent(bagent);
	auto pos = new ComTransform();
	pos->x = x; pos->y = y;
	ent->AddComponent(pos);
// 	auto tm = new ComTeam();
// 	tm->team = team;
//	ent->AddComponent(tm);
	auto box = new ComBoxCollider();
	box->Create(true, 0, 0, bulletCfg->boxWidth, bulletCfg->boxHeight);
	ent->AddComponent(box);
	if (cfg_EnableDebugDraw) ent->AddComponent(new ComBulletDebugDraw());
	
	if (bulletCfg->moveType == BulletMoveType::BMT_Line)
	{
		pos->vx = 0; pos->vy = 0;

		ent->AddComponent(new ComBulletDamageNone());
		auto baegg = new ComBulletAnimEgg();
		baegg->Create(anim_cfg->name);
		ent->AddComponent(baegg);
	}
	else if (bulletCfg->moveType == BulletMoveType::BMT_Bezier)
	{
		pos->vx = 0; pos->vy = 0;
// 		auto targ = new ComTarget();
// 		targ->Create(Target_Location, 0, destX, destY);
// 		ent->AddComponent(targ);
		auto bez = new ComBezierMovement();
		bez->Create(x, y, destX, destY, (abs(x - destX) + abs(y - destY)) / bulletCfg->flySpeed);
		ent->AddComponent(bez);
		auto dmgs = new ComBulletDamageSingle();
		dmgs->targetID = targetEntityID;
		ent->AddComponent(dmgs);
		auto banim = new ComBulletAnimArrow();
		banim->Create(anim_cfg->name);
		ent->AddComponent(banim);
		SystemBulletDamageSingle* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemBulletDamageSingle>();
		auto han = new ComColliderHandler();
		han->Create(std::bind(&SystemBulletDamageSingle::collisionHandler, atkSys, std::placeholders::_1, std::placeholders::_2), nullptr);
		ent->AddComponent(han);
	}
	else if(bulletCfg->moveType == BulletMoveType::BMT_Tracking)
	{
		SystemPawnFight* fightSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemPawnFight>();
		int tarEntityID = fightSys->FindFirstTargetByTeam(team);
		pos->vx = 0; pos->vy = bulletCfg->flySpeed;

// 		auto targ = new ComTarget();
// 		targ->Create(Target_Entity, tarEntityID);
// 		ent->AddComponent(targ);
		auto delayTrack = new ComDelayTrackMoving();
		delayTrack->Create(tarEntityID, bulletCfg->findTargetDelay);
		ent->AddComponent(delayTrack);
		ent->AddComponent(new ComBulletDamageScope());
		auto bom = new ComBulletAnimBomb();
		bom->Create(anim_cfg->name, bulletCfg->tailAnim);
		ent->AddComponent(bom);
		SystemBulletDamageScope* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemBulletDamageScope>();
		auto han = new ComColliderHandler();
		han->Create(std::bind(&SystemBulletDamageScope::OnCollision, atkSys, std::placeholders::_1, std::placeholders::_2), nullptr);
		ent->AddComponent(han);
	}
	
	ent->Refresh();
	return ent->GetId();
}

int EntityCreator::CreateBornPoint(float x, float y, int team)
{
	/*Entity* ent = ECSWorld::GetSingleton()->GetEntityManager()->Create();
	auto pos = new ComTransform();
	pos->x = x; pos->y = y;
	ent->AddComponent(pos);
// 	auto tm = new ComTeam();
// 	tm->team = team;
// 	ent->AddComponent(tm);
	if (team == Team_Human)
	{
		auto anim = new ComAnimation();
		anim->Create("BornPointHuman");
		ent->AddComponent(anim);
		//ent->AddComponent(new HumanGameControlCom());
		ECSWorld::GetSingleton()->AddTag(ent, GameDefine::Tag_HumanBornPoint);
	}
	else if (team == Team_Monster)
	{
		auto anim = new ComAnimation();
		anim->Create("BornPointMonster");
		ent->AddComponent(anim);
		//ent->AddComponent(new MonsterGameControlCom());
		ECSWorld::GetSingleton()->AddTag(ent, GameDefine::Tag_MonsterBornPoint);
	}

	ent->Refresh();
	return ent->GetId();*/
	return 0;
}