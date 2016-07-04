
//#include "Genius.h"
#include "PawnBehaviors.h"
#include "ECS/components/pawn/ComPawnBevtree.h"
#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include "ECS/ecs.h"
#include "pawn/PawnDefines.h"
#include "pawn/action/ActionDefine.h"
#include "tinyxml2.h"
#include "Log.h"
#include "app/Config.h"
#include "app/GameDefine.h"
#include "RoleDataMgr.h"
#include "RandUtility.h"

USING_NS_BHTREE
using namespace Genius;

/************************************************************************/
/*                                                          PawnIdle            */
/************************************************************************/

PawnIdle::PawnIdle() :
m_totalDuration(1.0f),
m_changeDirDuration(0.5f)
{}

eBehaviorStatus PawnIdle::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	m_timeCounter += data.timeDelta;
	m_changeDirTimeCounter += data.timeDelta;

	if (m_changeDirTimeCounter > m_changeDirDuration)
	{
		m_changeDirTimeCounter = 0;
		EventManager::GetSingleton()->FireEvent(TurnBackEvent(data.pEntity));
	}

	if (m_timeCounter > m_totalDuration)
		return BH_Success;
	else
		return BH_Running;
}

void PawnIdle::OnInitialize(BHUpdateContext& context)
{
	m_timeCounter = 0;
	m_changeDirTimeCounter = 0;

	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnAgent* agentCom = data.pEntity->GetComponent<ComPawnAgent>();
	m_totalDuration = RandUtility::RandomScale(agentCom->m_pRoleData->IdleDuration, 0.3f);
	m_changeDirDuration = RandUtility::RandomScale(agentCom->m_pRoleData->IdleTurnFaceTime, 0.3f);

	agentCom->AddAction(PAT_Idle);
	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_pawnStopMove, data.pEntity));
}

void PawnIdle::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_timeCounter = 0;
}

bool PawnIdle::LoadFromXml(XMLElement* xml)
{
	return true;
}

/************************************************************************/
/*                                                          PawnMove            */
/************************************************************************/
eBehaviorStatus PawnMove::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnNavigation* navCom = data.pEntity->GetComponent<ComPawnNavigation>();
	if (navCom && navCom->arrived)
		return BH_Success;

	m_uiTimeCounter += data.timeDelta;
	if (m_uiTimeCounter > m_uiMaxTime)
		return BH_Success;
	else
		return BH_Running;

	return BH_Running;
}

void PawnMove::OnInitialize(BHUpdateContext& context)
{
	m_uiTimeCounter = 0;
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	float randx = (float)(rand() % 1000);
	float randy = (float)(rand() % 600);
	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_navigateTo, data.pEntity, randx, randy));

	ComPawnAgent* agentCom = data.pEntity->GetComponent<ComPawnAgent>();
	agentCom->AddAction(PAT_Move);
}

void PawnMove::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_uiTimeCounter = 0;
}

bool PawnMove::LoadFromXml(XMLElement* xml)
{
	return true;
}

/************************************************************************/
/*                                                          PawnDie            */
/************************************************************************/
eBehaviorStatus PawnDie::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	m_timeCounter += data.timeDelta;
	if (m_timeCounter > m_duration)
	{
		ECSWorld::GetSingleton()->DeleteEntity(data.pEntity);

		// temp
		/*ComPawnFight* fightCom = data.pEntity->getComponent<ComPawnFight>();
		int team = fightCom->team;
		CGeniusApp::GetSingleton().SpawnOne(team);*/

		return BH_Success;
	}
	else
		return BH_Running;
}

void PawnDie::OnInitialize(BHUpdateContext& context)
{
	m_timeCounter = 0;
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnAgent* agentCom = data.pEntity->GetComponent<ComPawnAgent>();
	m_duration = agentCom->m_pRoleData->DeadBodyTime;

	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_pawnStopMove, data.pEntity));
	agentCom->AddAction(PAT_Die);
}

void PawnDie::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_timeCounter = 0;
}

bool PawnDie::LoadFromXml(XMLElement* xml)
{
	//m_duration = (float)atof(xml->Attribute("totalDuration"));

	return true;
}

/************************************************************************/
/*                                                          PawnWander            */
/************************************************************************/

PawnWander::PawnWander() :
m_totalDuration(5),
m_changeDirDuration(2),
m_wanderType(eWanderAround)
{}

eBehaviorStatus PawnWander::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnNavigation* navCom = data.pEntity->GetComponent<ComPawnNavigation>();
	if (navCom && navCom->arrived)
	{
		GoToSomewhere(context);
	}

	m_timeCounter += data.timeDelta;
	if (m_timeCounter > m_totalDuration)
		return BH_Success;
	else
		return BH_Running;

	return BH_Running;
}

void PawnWander::OnInitialize(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnAgent* tmpCom = data.pEntity->GetComponent<ComPawnAgent>();
	m_totalDuration = tmpCom->m_pRoleData->WanderDuration;
	m_changeDirDuration = tmpCom->m_pRoleData->WanderChangeDirTime;

	m_timeCounter = 0;
	GoToSomewhere(context);
	//LogInfo("enter PawnWander");
}

void PawnWander::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_timeCounter = 0;
	//LogInfo("exit PawnWander");
}

bool PawnWander::LoadFromXml(XMLElement* xml)
{
	int wanderType = eWanderNone;
	wanderType = xml->IntAttribute("type");
	if (wanderType > eWanderNone && wanderType < eWanderNum)
		m_wanderType = wanderType;
	else
		m_wanderType = eWanderAround;

	return true;
}

void PawnWander::GoToSomewhere(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPosition* posCom = data.pEntity->GetComponent<ComPosition>();
	ComTeam* pComTeam = data.pEntity->GetComponent<ComTeam>();

	int width = GameDefine::viewWidth;
	int height = GameDefine::viewHeight;
	bool tooLeft = pComTeam->team == Team_Human ? false : true;
	bool tooTop = posCom->y < height - posCom->y;
	int maxDistance = 200;

	float destX = posCom->x;
	float destY = posCom->y;
	
	switch (m_wanderType)
	{
	case eWanderAround:
		destX = (float)(rand() % maxDistance) + posCom->x + (tooLeft ? 1 : -1)*maxDistance;
		destY = (float)(rand() % maxDistance - 0.5f*maxDistance) + posCom->y;// +(tooTop ? 1 : -1) * 100;
		// bounds
		if (destX < 20)
			destX = 20;
		else if (destX > width - 20)
			destX = width - 20;
		if (destY < 20)
			destY = 20;
		else if (destY > height - 50)
			destY = height - 50;
		break;
	case eWanderLeft:
		destX = posCom->x - maxDistance;
		destY = posCom->y;
		break;
	case eWanderRight:
		destX = posCom->x + maxDistance;
		destY = posCom->y;
		break;
	default:
		destX = posCom->x;
		destY = posCom->y;
		break;
	}

	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_navigateTo, data.pEntity, destX, destY));

	ComPawnAgent* agentCom = data.pEntity->GetComponent<ComPawnAgent>();
	agentCom->AddAction(PAT_Move);
}



/************************************************************************/
/*                                                          PawnChase            */
/************************************************************************/

PawnChase::PawnChase() :
m_relocateInterval(1)
{}

eBehaviorStatus PawnChase::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnFight* myFightCom = data.pEntity->GetComponent<ComPawnFight>();
	if (myFightCom && myFightCom->haveTarget)
	{
		m_timeCounter += data.timeDelta;
		if (m_timeCounter > m_relocateInterval)
		{
			ComPawnFight* eneCom = data.pEntity->GetComponent<ComPawnFight>();
			EventManager::GetSingleton()->FireEvent(MoveToEntityEvent(data.pEntity, eneCom->enemyID));
			m_timeCounter = 0;
		}
		return BH_Running;
	}
	else
		return BH_Failed;

	return BH_Running;
}

void PawnChase::OnInitialize(BHUpdateContext& context)
{
	m_timeCounter = 0;
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	//LogInfo("enter PawnChase");
}

void PawnChase::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_timeCounter = 0;
	//LogInfo("exit PawnChase");
}

bool PawnChase::LoadFromXml(XMLElement* xml)
{
	return true;
}

void PawnChase::GoToTarget(BHUpdateContext& context)
{

}


/************************************************************************/
/*                                                          近程普攻            */
/************************************************************************/

PawnAttackNear::PawnAttackNear() :
ownerEntityID(-1),
attackAnimCount(0)
{}

PawnAttackNear::~PawnAttackNear()
{
	EventManager::GetSingleton()->RemoveListener(this, Event_animMovement);
}

eBehaviorStatus PawnAttackNear::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	ComPawnAgent* tempCom = data.pEntity->GetComponent<ComPawnAgent>();

	ComPawnAnim* animCom = data.pEntity->GetComponent<ComPawnAnim>();
	animCom->SetDebugLabel("a1u");

	if (attackAnimCount >= tempCom->m_pRoleData->maxAttack1Times)
		return BH_Success;
	else
		return BH_Running;
}

void PawnAttackNear::OnInitialize(BHUpdateContext& context)
{
	EventManager::GetSingleton()->AddListener(this, Event_animMovement);

	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	
	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_pawnStopMove, data.pEntity));
	EventManager::GetSingleton()->FireEvent(AttackNearEvent(data.pEntity));

	ownerEntityID = data.pEntity->GetId();
	attackAnimCount = 0;
	//LogInfo("enter attack");
	ComPawnAnim* animCom = data.pEntity->GetComponent<ComPawnAnim>();
	animCom->SetDebugLabel("a1in");
}

void PawnAttackNear::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	ComPawnAnim* animCom = data.pEntity->GetComponent<ComPawnAnim>();
	animCom->SetDebugLabel("a1o");
	//LogInfo("exit PawnAttack");
}

bool PawnAttackNear::LoadFromXml(XMLElement* xml)
{
	return true;
}

bool PawnAttackNear::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_animMovement:
	{
							   const AnimationMovementEvent & animEvent = static_cast<const AnimationMovementEvent &>(event);
							   if (ownerEntityID == animEvent.entityID
								   && (animEvent.animName == PawnAnimName::Attack1Left || animEvent.animName == PawnAnimName::Attack1Right)
								   && (animEvent.moveType == cocostudio::LOOP_COMPLETE)
								   )
							   {
								   attackAnimCount ++;
							   }
	}
		break;
	}
	return true;
}


/************************************************************************/
/*                                                          近程普攻2            */
/************************************************************************/

PawnAttackNear2::PawnAttackNear2() :
ownerEntityID(-1),
ComAnimationpleted(false)
{}

PawnAttackNear2::~PawnAttackNear2()
{
	EventManager::GetSingleton()->RemoveListener(this, Event_animMovement);
}

eBehaviorStatus PawnAttackNear2::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	//ComPawnNavigation* navCom = data.entity->getComponent<ComPawnNavigation>();
	ComPawnAnim* animCom = data.pEntity->GetComponent<ComPawnAnim>();
	animCom->SetDebugLabel("a2u");

	if (ComAnimationpleted)
		return BH_Success;
	else
		return BH_Running;
}

void PawnAttackNear2::OnInitialize(BHUpdateContext& context)
{
	EventManager::GetSingleton()->AddListener(this, Event_animMovement);

	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_pawnStopMove, data.pEntity));
	EventManager::GetSingleton()->FireEvent(AttackNear2Event(data.pEntity));

	ownerEntityID = data.pEntity->GetId();
	ComAnimationpleted = false;
	//LogInfo("enter attack");
	ComPawnAnim* animCom = data.pEntity->GetComponent<ComPawnAnim>();
	animCom->SetDebugLabel("a2i");
}

void PawnAttackNear2::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	//LogInfo("exit PawnAttack");
	ComPawnAnim* animCom = data.pEntity->GetComponent<ComPawnAnim>();
	animCom->SetDebugLabel("a2o");
}

bool PawnAttackNear2::LoadFromXml(XMLElement* xml)
{
	return true;
}

bool PawnAttackNear2::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_animMovement:
	{
							   const AnimationMovementEvent & animEvent = static_cast<const AnimationMovementEvent &>(event);
							   if (ownerEntityID == animEvent.entityID
								   && (animEvent.animName == PawnAnimName::Attack2Left || animEvent.animName == PawnAnimName::Attack2Right)
								   && (animEvent.moveType == cocostudio::COMPLETE || animEvent.moveType == cocostudio::LOOP_COMPLETE)
								   )
							   {
								   ComAnimationpleted = true;
							   }
	}
		break;
	}
	return true;
}

/************************************************************************/
/*                                                          PawnAttackFar            */
/************************************************************************/

PawnAttackFar::PawnAttackFar() :
ownerEntityID(-1)
{}

PawnAttackFar::~PawnAttackFar()
{
	EventManager::GetSingleton()->RemoveListener(this, Event_animMovement);
}

eBehaviorStatus PawnAttackFar::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	return BH_Running;
}

void PawnAttackFar::OnInitialize(BHUpdateContext& context)
{
	EventManager::GetSingleton()->AddListener(this, Event_animMovement);

	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_pawnStopMove, data.pEntity));
	ComPawnFight* fightCom = data.pEntity->GetComponent<ComPawnFight>();
	Entity* pTargetEntity = ECSWorld::GetSingleton()->GetEntity(fightCom->enemyID);
	if (nullptr != pTargetEntity)
	{
		ComPosition* tarPosCom = pTargetEntity->GetComponent<ComPosition>();
		EventManager::GetSingleton()->FireEvent(TurnToEvent(data.pEntity, tarPosCom->x, tarPosCom->y));
	}
	
	//EventManager::GetSingleton()->FireEvent(ActionEvent(data.pEntity, Action_Skill1));
	ComPawnAgent* agentCom = data.pEntity->GetComponent<ComPawnAgent>();
	agentCom->AddAction(PAT_Skill1);

	ownerEntityID = data.pEntity->GetId();
	//LogInfo("enter attack far");
}

void PawnAttackFar::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	//LogInfo("exit PawnAttack far");
}

bool PawnAttackFar::LoadFromXml(XMLElement* xml)
{
	return true;
}

bool PawnAttackFar::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_animMovement:
	{
							 /*  const AnimationMovementEvent & animEvent = static_cast<const AnimationMovementEvent &>(event);
							   if (ownerEntityID == animEvent.entityID
								   && (animEvent.animName == PawnAnimName::Skill1Left || animEvent.animName == PawnAnimName::Skill2Right)
								   && (animEvent.moveType == cocostudio::COMPLETE || animEvent.moveType == cocostudio::LOOP_COMPLETE)
								   )
							   {
								   ComAnimationpleted = true;
							   }*/
	}
		break;
	}
	return true;
}


/************************************************************************/
/*                                                          技能1           */
/************************************************************************/

PawnSkill1::PawnSkill1() :
ownerEntityID(-1)
{}

PawnSkill1::~PawnSkill1()
{
	EventManager::GetSingleton()->RemoveListener(this, Event_animMovement);
}

eBehaviorStatus PawnSkill1::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	if (ComAnimationpleted)
		return BH_Success;
	else
		return BH_Running;
}

void PawnSkill1::OnInitialize(BHUpdateContext& context)
{
	EventManager::GetSingleton()->AddListener(this, Event_animMovement);

	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_pawnStopMove, data.pEntity));
	//EventManager::GetSingleton()->FireEvent(ActionEvent(data.pEntity, Action_Skill1));
	ComPawnAgent* agentCom = data.pEntity->GetComponent<ComPawnAgent>();
	agentCom->AddAction(PAT_Skill1);

	ComAnimationpleted = false;
	ownerEntityID = data.pEntity->GetId();
	//LogInfo("enter useskill");
}

void PawnSkill1::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	EventManager::GetSingleton()->RemoveListener(this, Event_animMovement);

	//LogInfo("exit useskill");
}

bool PawnSkill1::LoadFromXml(XMLElement* xml)
{
	return true;
}

bool PawnSkill1::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();
	
	switch (eType)
	{
	case Event_animMovement:
	{
		const AnimationMovementEvent & animEvent = static_cast<const AnimationMovementEvent &>(event);
		if (ownerEntityID == animEvent.entityID
			&& (animEvent.animName == PawnAnimName::Skill1Left || animEvent.animName == PawnAnimName::Skill1Right)
			&& (animEvent.moveType == cocostudio::COMPLETE || animEvent.moveType == cocostudio::LOOP_COMPLETE)
			)
			{
				ComAnimationpleted = true;
			}
	}
		break;
	}
	return true;
}


/************************************************************************/
/*                                                          技能2           */
/************************************************************************/

PawnSkill2::PawnSkill2() :
ownerEntityID(-1)
{}

PawnSkill2::~PawnSkill2()
{
	EventManager::GetSingleton()->RemoveListener(this, Event_animMovement);
}

eBehaviorStatus PawnSkill2::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	if (ComAnimationpleted)
		return BH_Success;
	else
		return BH_Running;
}

void PawnSkill2::OnInitialize(BHUpdateContext& context)
{
	EventManager::GetSingleton()->AddListener(this, Event_animMovement);

	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_pawnStopMove, data.pEntity));
	//EventManager::GetSingleton()->FireEvent(ActionEvent(data.pEntity, Action_Skill2));
	ComPawnAgent* agentCom = data.pEntity->GetComponent<ComPawnAgent>();
	agentCom->AddAction(PAT_Skill2);

	ComAnimationpleted = false;
	ownerEntityID = data.pEntity->GetId();
	//LogInfo("enter useskill");
}

void PawnSkill2::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	EventManager::GetSingleton()->RemoveListener(this, Event_animMovement);

	//LogInfo("exit useskill");
}

bool PawnSkill2::LoadFromXml(XMLElement* xml)
{
	return true;
}

bool PawnSkill2::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_animMovement:
	{
							   const AnimationMovementEvent & animEvent = static_cast<const AnimationMovementEvent &>(event);
							   if (ownerEntityID == animEvent.entityID
								   && (animEvent.animName == PawnAnimName::Skill2Left || animEvent.animName == PawnAnimName::Skill2Right)
								   && (animEvent.moveType == cocostudio::COMPLETE || animEvent.moveType == cocostudio::LOOP_COMPLETE)
								   )
							   {
								   ComAnimationpleted = true;
							   }
	}
		break;
	}
	return true;
}


/************************************************************************/
/*                                                          技能3           */
/************************************************************************/

PawnSkill3::PawnSkill3() :
ownerEntityID(-1)
{}

PawnSkill3::~PawnSkill3()
{
	EventManager::GetSingleton()->RemoveListener(this, Event_animMovement);
}

eBehaviorStatus PawnSkill3::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	if (ComAnimationpleted)
		return BH_Success;
	else
		return BH_Running;
}

void PawnSkill3::OnInitialize(BHUpdateContext& context)
{
	EventManager::GetSingleton()->AddListener(this, Event_animMovement);

	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_pawnStopMove, data.pEntity));
	//EventManager::GetSingleton()->FireEvent(ActionEvent(data.pEntity, Action_Skill3));
	ComPawnAgent* agentCom = data.pEntity->GetComponent<ComPawnAgent>();
	agentCom->AddAction(PAT_Skill3);

	ComAnimationpleted = false;
	ownerEntityID = data.pEntity->GetId();
	//LogInfo("enter useskill");
}

void PawnSkill3::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	EventManager::GetSingleton()->RemoveListener(this, Event_animMovement);

	//LogInfo("exit useskill");
}

bool PawnSkill3::LoadFromXml(XMLElement* xml)
{
	return true;
}

bool PawnSkill3::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_animMovement:
	{
							   const AnimationMovementEvent & animEvent = static_cast<const AnimationMovementEvent &>(event);
							   if (ownerEntityID == animEvent.entityID
								   && (animEvent.animName == PawnAnimName::Skill3Left || animEvent.animName == PawnAnimName::Skill3Right)
								   && (animEvent.moveType == cocostudio::COMPLETE || animEvent.moveType == cocostudio::LOOP_COMPLETE)
								   )
							   {
								   ComAnimationpleted = true;
							   }
	}
		break;
	}
	return true;
}



/************************************************************************/
/*                                                       sheep bevs							        */
/************************************************************************/
/************************************************************************/
/*                                                          SheepIdle            */
/************************************************************************/
/*eBehaviorStatus SheepIdle::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	m_uiIdleTimeCounter += data.timeDelta;
	if (m_uiIdleTimeCounter > m_uiMaxIdleTime)
		return BH_Success;
	else
		return BH_Running;
}

void SheepIdle::OnInitialize(BHUpdateContext& context)
{
	m_uiIdleTimeCounter = 0;
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();

	EventManager::GetSingleton()->FireEvent(TransformEvent(Event_pawnStopMove, data.pEntity));
}

void SheepIdle::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_uiIdleTimeCounter = 0;
}

bool SheepIdle::LoadFromXml(XMLElement* xml)
{
	return true;
}

/************************************************************************/
/*                                                          SheepEat            */
/************************************************************************/
/*eBehaviorStatus SheepEat::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	m_uiIdleTimeCounter += data.timeDelta;
	if (m_uiIdleTimeCounter > m_uiMaxIdleTime)
		return BH_Success;
	else
		return BH_Running;
}

void SheepEat::OnInitialize(BHUpdateContext& context)
{
	m_uiIdleTimeCounter = 0;
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	//EventManager::GetSingleton()->FireEvent(ActionEvent(data.pEntity, Action_Eat));
}

void SheepEat::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_uiIdleTimeCounter = 0;
}

bool SheepEat::LoadFromXml(XMLElement* xml)
{
	return true;
}

/************************************************************************/
/*                                                          SheepDie            */
/************************************************************************/
/*eBehaviorStatus SheepDie::Update(BHUpdateContext& context)
{
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	m_uiIdleTimeCounter += data.timeDelta;
	if (m_uiIdleTimeCounter > m_uiMaxIdleTime)
		return BH_Success;
	else
		return BH_Running;
}

void SheepDie::OnInitialize(BHUpdateContext& context)
{
	m_uiIdleTimeCounter = 0;
	EntityBevInputData& data = context.GetRealDataType<EntityBevInputData>();
	EventManager::GetSingleton()->FireEvent(ActionEvent(data.pEntity, Action_Die));
}

void SheepDie::OnTerminate(BHUpdateContext& context, eBehaviorStatus state)
{
	m_uiIdleTimeCounter = 0;
}

bool SheepDie::LoadFromXml(XMLElement* xml)
{
	return true;
}*/

