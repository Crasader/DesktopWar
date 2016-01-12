
// d:)
#include "EntityCreators.h"
#include "ECS/ECSHeaders.h"
#include "RoleDataMgr.h"
#include "BulletDataMgr.h"
#include "BulletDefines.h"
#include "Logger.h"
#include "Config.h"
#include "GameDefine.h"

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
	ent->AddComponent(new VelocityCom(0, 0));
	ent->AddComponent(new PositionCom(x, y));
	ent->AddComponent(new TeamCom(team));
	ent->AddComponent(new TargetCom(Target_Entity));
	PawnAnimCom* paCom = new PawnAnimCom(id);
	ent->AddComponent(paCom);
	float width = paCom->GetWidth()*0.5f;
	float height = paCom->GetHeight()*0.7f;
	ent->AddComponent(new BoxColliderCom(false, 0, height*0.5f, width, height));
	ent->AddComponent(new ColliderHandlerCom(nullptr, nullptr));
	ent->AddComponent(new PawnActionCom(Action_Idle));
	ent->AddComponent(new PawnDirectionCom());
	ent->AddComponent(new PawnTemplateCom(roleInfo->id));
	ent->AddComponent(new BevtreeCom(roleInfo->bevTreeFile));
	ent->AddComponent(new PawnNavigationCom());
	ent->AddComponent(new PawnAttributeCom(roleInfo->id));
	ent->AddComponent(new PawnFightCom());
	if (cfg_EnableDebugDraw) ent->AddComponent(new PawnDebugDrawCom());

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
	ent->AddComponent(new PositionCom(x, y));
	ent->AddComponent(new TeamCom(team));
	ent->AddComponent(new BoxColliderCom(true, 0, 0, bulletInfo->boxWidth, bulletInfo->boxHeight));
	ent->AddComponent(new BulletTemplateCom(bulletInfo));
	if (cfg_EnableDebugDraw) ent->AddComponent(new BulletDebugDrawCom());
	
	if (bulletInfo->moveType == BulletMoveType::BMT_Line)
	{
		ent->AddComponent(new VelocityCom(0, 0));
		ent->AddComponent(new BulletDamageNoneCom());
		ent->AddComponent(new BulletEggAnimCom(bulletInfo->bodyAnim));
	}
	else if (bulletInfo->moveType == BulletMoveType::BMT_Bezier)
	{
		ent->AddComponent(new VelocityCom(0, 0));
		ent->AddComponent(new TargetCom(Target_Location, 0, destX, destY));
		ent->AddComponent(new BezierMovementCom(x, y, destX, destY, (abs(x - destX) + abs(y - destY)) / bulletInfo->flySpeed));
		ent->AddComponent(new BulletDamageSingleCom());
		ent->AddComponent(new BulletArrowAnimCom(bulletInfo->bodyAnim));
		BulletDamageSingleSystem* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<BulletDamageSingleSystem>();
		ent->AddComponent(new ColliderHandlerCom(std::bind(&BulletDamageSingleSystem::collisionHandler, atkSys, std::placeholders::_1, std::placeholders::_2),nullptr));
	}
	else if(bulletInfo->moveType == BulletMoveType::BMT_Tracking)
	{
		PawnFightSystem* fightSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<PawnFightSystem>();
		int tarEntityID = fightSys->FindFirstTargetByTeam(team);
		ent->AddComponent(new VelocityCom(0, bulletInfo->flySpeed));
		ent->AddComponent(new TargetCom(Target_Entity, tarEntityID));
		ent->AddComponent(new DelayTrackMovingCom(tarEntityID, bulletInfo->findTargetDelay));
		ent->AddComponent(new BulletDamageScopeCom());
		ent->AddComponent(new BulletBombAnimCom(bulletInfo->bodyAnim, bulletInfo->tailAnim));
		BulletDamageScopeSystem* atkSys = ECSWorld::GetSingleton()->GetSystemManager()->GetSystem<BulletDamageScopeSystem>();
		ent->AddComponent(new ColliderHandlerCom(std::bind(&BulletDamageScopeSystem::OnCollision, atkSys, std::placeholders::_1, std::placeholders::_2),nullptr));
	}
	
	ent->Refresh();
	return ent;
}

Entity* EntityCreator::CreateBornPoint(float x, float y, int team)
{
	Entity* ent = ECSWorld::GetSingleton()->GetEntityManager()->Create();
	ent->AddComponent(new PositionCom(x, y));
	ent->AddComponent(new TeamCom(team));
	if (team == Team_Human)
	{
		ent->AddComponent(new AnimationCom("BornPointHuman"));
		ent->AddComponent(new HumanGameControlCom());
		ECSWorld::GetSingleton()->GetTagManager()->Subscribe(GameDefine::Tag_HumanBornPoint, ent);
	}
	else if (team == Team_Monster)
	{
		ent->AddComponent(new AnimationCom("BornPointMonster"));
		ent->AddComponent(new MonsterGameControlCom());
		ECSWorld::GetSingleton()->GetTagManager()->Subscribe(GameDefine::Tag_MonsterBornPoint, ent);
	}

	ent->Refresh();
	return ent;
}