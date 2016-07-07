
#include "ComPawnFight.h"
#include "pawn/PawnDefines.h"
#include "data/auto/Role_cfg.hpp"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "skill/SkillManager.h"
#include "skill/BuffManager.h"
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
	SkillManager::GetSingleton()->ClearSkill(id);
	BuffManager::GetSingleton()->RemoveBuff(id);
}

bool ComPawnFight::Init()
{
	Entity* ent = this->GetOwner();
	ComPawnAgent* tempCom = ent->GetComponent<ComPawnAgent>();
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_pRoleData->normalSkill1);
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_pRoleData->normalSkill2);
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_pRoleData->specialSkill1);
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_pRoleData->specialSkill2);
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_pRoleData->specialSkill3);
	return true;
}
