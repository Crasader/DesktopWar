// d:)
#include "PawnFightCom.h"
#include "pawn/PawnDefines.h"
#include "RoleDataMgr.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "skill/SkillSystem.h"
#include "skill/BuffSystem.h"
#include "../../core/Entity.h"
#include "Logger.h"

#include "PawnTemplateCom.h"


using namespace Genius;


PawnFightCom::PawnFightCom() :
enemyID(-1),
haveTarget(false),
isTargetInNearRange(false),
isTargetInFarRange(false)
{}

PawnFightCom::~PawnFightCom()
{
	int id = GetOwner()->GetId();
	SkillSystem::GetSingleton().ClearSkill(id);
	BuffSystem::GetSingleton().RemoveBuff(id);
}

bool PawnFightCom::Init()
{
	Entity* ent = this->GetOwner();
	PawnTemplateCom* tempCom = ent->GetComponent<PawnTemplateCom>();
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->pRoleData->normalSkill1);
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->pRoleData->normalSkill2);
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->pRoleData->specialSkill1);
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->pRoleData->specialSkill2);
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->pRoleData->specialSkill3);
	return true;
}
