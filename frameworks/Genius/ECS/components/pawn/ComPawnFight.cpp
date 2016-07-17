
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


COM_CREATE_FN_IMPL(ComPawnFight);

ComPawnFight::ComPawnFight() :
enemyID(-1),
haveTarget(false),
isTargetInNearRange(false),
isTargetInFarRange(false)
{}

ComPawnFight::~ComPawnFight()
{
	int id = GetEntity()->GetId();
	SkillManager::GetSingleton()->ClearSkill(id);
	BuffManager::GetSingleton()->RemoveBuff(id);
}

void ComPawnFight::OnAwake()
{
	Entity* ent = this->GetEntity();
	ComPawnAgent* tempCom = ent->GetComponent<ComPawnAgent>();
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_roleCfg->normalSkill1);
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_roleCfg->normalSkill2);
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_roleCfg->specialSkill1);
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_roleCfg->specialSkill2);
	SkillManager::GetSingleton()->LoadSkill(ent->GetId(), tempCom->m_roleCfg->specialSkill3);
	
}
