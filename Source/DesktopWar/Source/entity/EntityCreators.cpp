

#include "entityCreators.h"
#include "ECS/ecs.h"
#include "RoleDataMgr.h"
#include "BulletDataMgr.h"
#include "bullet/BulletDefines.h"
#include "Logger.h"
#include "app/Config.h"
#include "app/GameDefine.h"

using namespace Genius;

Entity* EntityCreator::CreatePawn(std::string id, float x, float y, int team)
{
	RoleData* roleInfo = RoleDataMgr::GetSingleton()->GetRoleData(id);
	if (nullptr == roleInfo)
	{
		Logger::LogWarning("error role type : %s", id.c_str());
		return nullptr;
	}
	return CreatePawn(roleInfo->id, x, y, team);
}

Entity* EntityCreator::CreatePawn(int id, float x, float y, int team)
{
	RoleData* roleInfo = RoleDataMgr::GetSingleton()->GetRoleData(id);
	if (nullptr == roleInfo)
	{
		Logger::LogWarning("error role type : %d", id);
		return nullptr;
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
	ent->AddComponent(new ComPawnAction(Action_Idle));
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

	return ent;
}

Entity* EntityCreator::CreateBullet(int bulletID, int targetEntityID, float x, float y, int team, float destX, float destY)
{
	BulletData* bulletInfo = BulletDataMgr::GetSingleton()->GetBulletData(bulletID);
	if (nullptr == bulletInfo)
	{
		Logger::LogWarning("error bullet type : %d", bulletID);
		return nullptr;
	}

	Entity* ent = ECSWorld::GetSingleton()->GetEntityManager()->Create();
	ent->AddComponent(new ComBulletAgent(bulletInfo));
	ent->AddComponent(new ComPosition(x, y));
	ent->AddComponent(new ComTeam(team));
	ent->AddComponent(new ComBoxCollider(true, 0, 0, bulletInfo->boxWidth, bulletInfo->boxHeight));
	if (cfg_EnableDebugDraw) ent->AddComponent(new ComBulletDebugDraw());
	
	if (bulletInfo->moveType == BulletMoveType::BMT_Line)
	{
		ent->AddComponent(new ComVelocity(0, 0));
		ent->AddComponent(new ComBulletDamageNone());
		ent->AddComponent(new ComBulletAnimEgg(bulletInfo->bodyAnim));
	}
	else if (bulletInfo->moveType == BulletMoveType::BMT_Bezier)
	{
		ent->AddComponent(new ComVelocity(0, 0));
		ent->AddComponent(new ComTarget(Target_Location, 0, destX, destY));
		ent->AddComponent(new ComBezierMovement(x, y, destX, destY, (abs(x - destX) + abs(y - destY)) / bulletInfo->flySpeed));
		ent->AddComponent(new ComBulletDamageSingle());
		ent->AddComponent(new ComBulletAnimArrow(bulletInfo->bodyAnim));
		SystemBulletDamageSingle* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemBulletDamageSingle>();
		ent->AddComponent(new ComColliderHandler(std::bind(&SystemBulletDamageSingle::collisionHandler, atkSys, std::placeholders::_1, std::placeholders::_2),nullptr));
	}
	else if(bulletInfo->moveType == BulletMoveType::BMT_Tracking)
	{
		SystemPawnFight* fightSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemPawnFight>();
		int tarEntityID = fightSys->FindFirstTargetByTeam(team);
		ent->AddComponent(new ComVelocity(0, bulletInfo->flySpeed));
		ent->AddComponent(new ComTarget(Target_Entity, tarEntityID));
		ent->AddComponent(new ComDelayTrackMoving(tarEntityID, bulletInfo->findTargetDelay));
		ent->AddComponent(new ComBulletDamageScope());
		ent->AddComponent(new ComBulletAnimBomb(bulletInfo->bodyAnim, bulletInfo->tailAnim));
		SystemBulletDamageScope* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<SystemBulletDamageScope>();
		ent->AddComponent(new ComColliderHandler(std::bind(&SystemBulletDamageScope::OnCollision, atkSys, std::placeholders::_1, std::placeholders::_2),nullptr));
	}
	
	ent->Refresh();
	return ent;
}

Entity* EntityCreator::CreateBornPoint(float x, float y, int team)
{
	Entity* ent = ECSWorld::GetSingleton()->GetEntityManager()->Create();
	ent->AddComponent(new ComPosition(x, y));
	ent->AddComponent(new ComTeam(team));
	if (team == Team_Human)
	{
		ent->AddComponent(new ComAnimation("BornPointHuman"));
		ent->AddComponent(new HumanGameControlCom());
		ECSWorld::GetSingleton()->GetTagManager()->Subscribe(GameDefine::Tag_HumanBornPoint, ent);
	}
	else if (team == Team_Monster)
	{
		ent->AddComponent(new ComAnimation("BornPointMonster"));
		ent->AddComponent(new MonsterGameControlCom());
		ECSWorld::GetSingleton()->GetTagManager()->Subscribe(GameDefine::Tag_MonsterBornPoint, ent);
	}

	ent->Refresh();
	return ent;
}