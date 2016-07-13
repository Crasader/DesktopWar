

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
	ent->AddComponent(new ComPawnAgent(roleInfo));
	ent->AddComponent(new ComVelocity(0, 0));
	ent->AddComponent(new ComPosition(x, y));
	ent->AddComponent(new ComTeam(team));
	ent->AddComponent(new ComTarget(Target_Entity));
	ComPawnAnim* paCom = new ComPawnAnim(id);
	ent->AddComponent(paCom);
	float width = paCom->GetWidth()*0.5f;
	float height = paCom->GetHeight()*0.7f;
	ent->AddComponent(new ComBoxCollider(false, 0, height*0.5f, width, height));
	ent->AddComponent(new ComColliderHandler(nullptr, nullptr));
	ent->AddComponent(new ComPawnDirection());
	ent->AddComponent(new ComPawnBevtree(roleInfo->bevTreeFile));
	ent->AddComponent(new ComPawnNavigation());
	ent->AddComponent(new ComPawnFight());
	if (cfg_EnableDebugDraw) ent->AddComponent(new ComPawnDebugDraw());

	if (team == Team_Human)
	{
		ECSWorld::GetSingleton()->GetGroupManager()->Set(GameDefine::Group_Human, ent);
	}
	else if (team == Team_Monster)
	{
		ECSWorld::GetSingleton()->GetGroupManager()->Set(GameDefine::Group_Monster, ent);
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
	ent->AddComponent(new ComBulletAgent(bulletCfg));
	ent->AddComponent(new ComPosition(x, y));
	ent->AddComponent(new ComTeam(team));
	ent->AddComponent(new ComBoxCollider(true, 0, 0, bulletCfg->boxWidth, bulletCfg->boxHeight));
	if (cfg_EnableDebugDraw) ent->AddComponent(new ComBulletDebugDraw());
	
	if (bulletCfg->moveType == BulletMoveType::BMT_Line)
	{
		ent->AddComponent(new ComVelocity(0, 0));
		ent->AddComponent(new ComBulletDamageNone());
		ent->AddComponent(new ComBulletAnimEgg(anim_cfg->name));
	}
	else if (bulletCfg->moveType == BulletMoveType::BMT_Bezier)
	{
		ent->AddComponent(new ComVelocity(0, 0));
		ent->AddComponent(new ComTarget(Target_Location, 0, destX, destY));
		ent->AddComponent(new ComBezierMovement(x, y, destX, destY, (abs(x - destX) + abs(y - destY)) / bulletCfg->flySpeed));
		ent->AddComponent(new ComBulletDamageSingle());
		ent->AddComponent(new ComBulletAnimArrow(anim_cfg->name));
		SystemBulletDamageSingle* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemBulletDamageSingle>();
		ent->AddComponent(new ComColliderHandler(std::bind(&SystemBulletDamageSingle::collisionHandler, atkSys, std::placeholders::_1, std::placeholders::_2),nullptr));
	}
	else if(bulletCfg->moveType == BulletMoveType::BMT_Tracking)
	{
		SystemPawnFight* fightSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemPawnFight>();
		int tarEntityID = fightSys->FindFirstTargetByTeam(team);
		ent->AddComponent(new ComVelocity(0, bulletCfg->flySpeed));
		ent->AddComponent(new ComTarget(Target_Entity, tarEntityID));
		ent->AddComponent(new ComDelayTrackMoving(tarEntityID, bulletCfg->findTargetDelay));
		ent->AddComponent(new ComBulletDamageScope());
		ent->AddComponent(new ComBulletAnimBomb(anim_cfg->name, bulletCfg->tailAnim));
		SystemBulletDamageScope* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemBulletDamageScope>();
		ent->AddComponent(new ComColliderHandler(std::bind(&SystemBulletDamageScope::OnCollision, atkSys, std::placeholders::_1, std::placeholders::_2),nullptr));
	}
	
	ent->Refresh();
	return ent->GetId();
}

int EntityCreator::CreateBornPoint(float x, float y, int team)
{
	Entity* ent = ECSWorld::GetSingleton()->GetEntityManager()->Create();
	ent->AddComponent(new ComPosition(x, y));
	ent->AddComponent(new ComTeam(team));
	if (team == Team_Human)
	{
		auto anim = new ComAnimation();
		anim->Create("BornPointHuman");
		ent->AddComponent(anim);
		ent->AddComponent(new HumanGameControlCom());
		ECSWorld::GetSingleton()->GetTagManager()->Subscribe(GameDefine::Tag_HumanBornPoint, ent);
	}
	else if (team == Team_Monster)
	{
		auto anim = new ComAnimation();
		anim->Create("BornPointMonster");
		ent->AddComponent(anim);
		ent->AddComponent(new MonsterGameControlCom());
		ECSWorld::GetSingleton()->GetTagManager()->Subscribe(GameDefine::Tag_MonsterBornPoint, ent);
	}

	ent->Refresh();
	return ent->GetId();
}