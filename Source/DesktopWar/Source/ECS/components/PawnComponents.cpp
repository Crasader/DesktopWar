// d:)
#include "PawnComponents.h"
#include "../../pawn/PawnDefines.h"
#include "RoleDataMgr.h"
#include "gfx/gfx.h"
#include "AnimDataMgr.h"
#include "event/EventManager.h"
#include "../EntityEvents.h"
#include "skill/SkillSystem.h"
#include "skill/BuffSystem.h"
#include "../core/Entity.h"
#include "Logger.h"


using namespace Genius;


/************************************************************************/
/*                              PawnAnimCom                                        */
/************************************************************************/
PawnAnimCom::PawnAnimCom(int roleID) :
m_curAction(Action_Idle)
{
	RoleData* roleData = RoleDataMgr::GetSingleton()->GetRoleData(roleID);
	if (roleData)
	{
		m_pAvatarRoot = cocos2d::Node::create();
		m_pBodyArmature = cocostudio::Armature::create(roleData->animSetName);
		m_pAvatarRoot->addChild(m_pBodyArmature);
		m_pLifeBar = UIBar::create(roleData->lifeBarType);
		m_pLifeBar->setPosition(0, 0 + roleData->lifeBarHeight);
		m_pAvatarRoot->addChild(m_pLifeBar);
		SceneManager::GetInstance().AddToMapLayer(m_pAvatarRoot);

		m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(PawnAnimCom::AnimationFrameCallback, this, std::placeholders::_4));
		m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(PawnAnimCom::AnimationMovementCallback, this));

		PlayAnimation(PawnAnimName::IdleLeft);

		m_pDebugLabel = Label::createWithBMFont("res/font/arial16.fnt", "- -", TextHAlignment::LEFT);
		m_pDebugLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		m_pDebugLabel->setScale(0.8f);
		m_pDebugLabel->setColor(Color3B(0, 255, 0));
		m_pDebugLabel->setPosition(0, -10);
		m_pAvatarRoot->addChild(m_pDebugLabel);
	}
}

PawnAnimCom::~PawnAnimCom()
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->removeFromParent();
		m_pAvatarRoot = nullptr;
	}
}

void PawnAnimCom::PlayAnimation(std::string name)
{
	m_pBodyArmature->getAnimation()->play(name);
}

void PawnAnimCom::SetPosition(float x, float y)
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->setPosition(x, y);
	}
}

float PawnAnimCom::GetWidth()
{
	return m_pBodyArmature ? m_pBodyArmature->getContentSize().width : 20;
}

float PawnAnimCom::GetHeight()
{
	return m_pBodyArmature ? m_pBodyArmature->getContentSize().height : 20;
}

bool PawnAnimCom::HaveThisAnimation(std::string name)
{
	return m_pBodyArmature->getAnimation()->getAnimationData()->getMovement(name) != nullptr;
}

void PawnAnimCom::AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName)
{
	switch (movType)
	{
	case cocostudio::START:
		//printf("START\n");
		break;
	case cocostudio::COMPLETE:
		EventManager::GetInstance().FireEvent(AnimationMovementEvent(animName, (int)movType, this->GetOwner()->GetId()));
		//printf("COMPLETE\n");
		break;
	case cocostudio::LOOP_COMPLETE:
		EventManager::GetInstance().FireEvent(AnimationMovementEvent(animName, (int)movType, this->GetOwner()->GetId()));
		break;
	default:
		break;
	}
}

void PawnAnimCom::AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx)
{
	if (eventName == "")
		return;

	if (eventName == "attack")
	{
		EventManager::GetInstance().FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::NormalSkill1));
	}
	else if (eventName == "attack2")
	{
		EventManager::GetInstance().FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::NormalSkill2));
	}
	else if (eventName == "skill1")
	{
		EventManager::GetInstance().FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::SpecialSkill1));
	}
	else if (eventName == "skill2")
	{
		EventManager::GetInstance().FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::SpecialSkill2));
	}
	else if (eventName == "skill3")
	{
		EventManager::GetInstance().FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::SpecialSkill3));
	}
	else
	{
		Logger::LogWarning("unknown frame event.");
	}
}

void PawnAnimCom::PlayFloatNumber(int number, int y)
{
	char num[16];
	FloatLabel* label;
	if (number > 0)
	{
		sprintf_s(num, 16, "%d", number);
		label = FloatLabel::create(num);
		label->setColor(Color3B::GREEN);
	}
	else if (number < 0)
	{
		sprintf_s(num, 16, "%d", number);
		label = FloatLabel::create(num);
		label->setColor(Color3B::RED);
	}
	m_pAvatarRoot->addChild(label, 1);
	label->setPositionY(y);
}

void PawnAnimCom::SetDebugLabel(std::string text)
{
	m_pDebugLabel->setString(text);
}

/************************************************************************/
/*                              PawnActionCom                                        */
/************************************************************************/
PawnActionCom::PawnActionCom(unsigned int act)
{
	m_curAction = Action_Idle;
	if (act > Action_Min && act < Action_Max)
		m_curAction = act;
};

void PawnActionCom::StartAction(unsigned int act)
{
	if (act <= Action_Min || act >= Action_Max)
		return;

	m_curAction = act;
	/*switch (act)
	{
	case Action_Idle:
		break;
	case Action_Move:
		break;
	case Action_Attack_Near:
		break;
	case Action_Skill1:
		break;
	case Action_Die:
		break;
	default:
		printf("unknown action\n");
		break;
	}*/
}


/************************************************************************/
/*                                         PawnTemplateCom                             */
/************************************************************************/
PawnTemplateCom::PawnTemplateCom(int roleID)
{
	RoleData* info = RoleDataMgr::GetSingleton()->GetRoleData(roleID);
	pRoleData = info;
}


/************************************************************************/
/*                                         PawnAttributeCom                             */
/************************************************************************/
PawnAttributeCom::PawnAttributeCom(int roleID)
{
	RoleData* roleData = RoleDataMgr::GetSingleton()->GetRoleData(roleID);
	if (roleData)
	{
		curLife = roleData->baseLife;
	}
}

PawnAttributeCom::~PawnAttributeCom()
{
}

/************************************************************************/
/*                                           PawnFightCom                           */
/************************************************************************/
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

/************************************************************************/
/*                                     PawnDebugDrawCom                                 */
/************************************************************************/
PawnDebugDrawCom::PawnDebugDrawCom()
{
	pRoot = Node::create();
	pNodeBoxCollider = DrawNode::create();
	pNodeNearRange = DrawNode::create();
	pNodeFarRange = DrawNode::create();
	pRoot->addChild(pNodeBoxCollider);
	pRoot->addChild(pNodeNearRange);
	pRoot->addChild(pNodeFarRange);
	SceneManager::GetInstance().AddToMapLayer(pRoot);
}

PawnDebugDrawCom::~PawnDebugDrawCom()
{
	pRoot->removeFromParent();
}

void PawnDebugDrawCom::Clear()
{
	pNodeBoxCollider->clear();
	pNodeNearRange->clear();
	pNodeFarRange->clear();
}