
#include "ComPawnFight.h"
#include "pawn/PawnDefines.h"
#include "RoleDataMgr.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "skill/SkillSystem.h"
#include "skill/BuffSystem.h"
#include "../../core/Entity.h"
#include "Log.h"

#include "ComPawnAgent.h"


using namespace Genius;


ComPawnFight::ComPawnFight() :
enemyID(-1),
haveTarget(false),
isTargetInNearRange(false),
isTargetInFarRange(false)
{}

ComPawnFight::~ComPawnFight()
{
	int id = GetOwner()->GetId();
	SkillSystem::GetSingleton().ClearSkill(id);
	BuffSystem::GetSingleton().RemoveBuff(id);
}

bool ComPawnFight::Init()
{
	Entity* ent = this->GetOwner();
	ComPawnAgent* tempCom = ent->GetComponent<ComPawnAgent>();
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->m_pRoleData->normalSkill1);
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->m_pRoleData->normalSkill2);
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->m_pRoleData->specialSkill1);
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->m_pRoleData->specialSkill2);
	SkillSystem::GetSingleton().LoadSkill(ent->GetId(), tempCom->m_pRoleData->specialSkill3);
	return true;
}
