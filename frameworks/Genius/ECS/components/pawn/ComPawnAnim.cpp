
#include "ComPawnAnim.h"
#include "pawn/PawnDefines.h"
#include "data/auto/Role_cfg.hpp"
#include "gfx/gfx.h"
#include "data/auto/Animation_cfg.hpp"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "skill/SkillSystem.h"
#include "skill/BuffSystem.h"
#include "../../core/Entity.h"
#include "ComPawnAgent.h"
#include "pawn/PawnBlackboard.h"
#include "pawn/anim/animFSM/AnimFSM.h"
#include "pawn/anim/animFSM/AnimFSMSimple.h"
#include "pawn/anim/animSet/AnimSetSimple.h"
#include "Log.h"


USING_NS_CC;
using namespace Genius;
using namespace cfg;


/************************************************************************/
/*                              ComPawnAnim                                        */
/************************************************************************/
ComPawnAnim::ComPawnAnim(int roleID) :
m_curAction(Action_Idle),
m_pAnimFsm(nullptr)
{
	Role_cfg* roleData = RoleDataMgr::GetSingleton()->GetRoleData(roleID);
	if (roleData)
	{
		m_pAvatarRoot = cocos2d::Node::create();
		m_pBodyArmature = cocostudio::Armature::create(roleData->animSetName);
		m_pAvatarRoot->addChild(m_pBodyArmature);
		m_pLifeBar = UIBar::create(roleData->lifeBarType);
		m_pLifeBar->setPosition(0, 0 + roleData->lifeBarHeight);
		m_pAvatarRoot->addChild(m_pLifeBar);
		SceneManager::GetSingleton()->AddToMapLayer(m_pAvatarRoot);

		m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(ComPawnAnim::AnimationFrameCallback, this, std::placeholders::_4));
		m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(ComPawnAnim::AnimationMovementCallback, this));

		PlayAnimation(PawnAnimName::IdleLeft);

		m_pDebugLabel = Label::createWithBMFont("res/font/arial16.fnt", "- -", TextHAlignment::LEFT);
		m_pDebugLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		m_pDebugLabel->setScale(0.8f);
		m_pDebugLabel->setColor(Color3B(0, 255, 0));
		m_pDebugLabel->setPosition(0, -10);
		m_pAvatarRoot->addChild(m_pDebugLabel);
	}
}

ComPawnAnim::~ComPawnAnim()
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->removeFromParent();
		m_pAvatarRoot = nullptr;
	}

	if (m_pAnimFsm != nullptr)
		delete m_pAnimFsm;

	if (m_pAnimSet != nullptr)
		delete m_pAnimSet;

	GetOwner()->GetComponent<ComPawnAgent>()->GetBlackboard()->RemoveActionHandler(this);
}

bool	ComPawnAnim::Init()
{
	Component::Init();

	GetOwner()->GetComponent<ComPawnAgent>()->GetBlackboard()->AddActionHandler(this);

	CreateAnimFSM(AFT_Simple);

	m_pAnimSet = new AnimSetSimple(this);

	return true;
}

void ComPawnAnim::HandleAction(PawnAction* pAction)
{
	if (m_pAnimFsm != nullptr)
		m_pAnimFsm->DoAction(pAction);
}

void ComPawnAnim::PlayAnimation(const std::string& name)
{
	m_pBodyArmature->getAnimation()->play(name);
}

void ComPawnAnim::SetPosition(float x, float y)
{
	if (m_pAvatarRoot)
	{
		m_pAvatarRoot->setPosition(x, y);
	}
}

float ComPawnAnim::GetWidth()
{
	return m_pBodyArmature ? m_pBodyArmature->getContentSize().width : 20;
}

float ComPawnAnim::GetHeight()
{
	return m_pBodyArmature ? m_pBodyArmature->getContentSize().height : 20;
}

bool ComPawnAnim::HaveThisAnimation(std::string name)
{
	return m_pBodyArmature->getAnimation()->getAnimationData()->getMovement(name) != nullptr;
}

void ComPawnAnim::AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName)
{
	switch (movType)
	{
	case cocostudio::START:
		//printf("START\n");
		break;
	case cocostudio::COMPLETE:
		EventManager::GetSingleton()->FireEvent(AnimationMovementEvent(animName, (int)movType, this->GetOwner()->GetId()));
		//printf("COMPLETE\n");
		break;
	case cocostudio::LOOP_COMPLETE:
		EventManager::GetSingleton()->FireEvent(AnimationMovementEvent(animName, (int)movType, this->GetOwner()->GetId()));
		break;
	default:
		break;
	}
}

void ComPawnAnim::AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx)
{
	if (eventName == "")
		return;

	if (eventName == "attack")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::NormalSkill1));
	}
	else if (eventName == "attack2")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::NormalSkill2));
	}
	else if (eventName == "skill1")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::SpecialSkill1));
	}
	else if (eventName == "skill2")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::SpecialSkill2));
	}
	else if (eventName == "skill3")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetOwner(), UseSkillEvent::SpecialSkill3));
	}
	else
	{
		Log::Warning("unknown frame event.");
	}
}

void ComPawnAnim::PlayFloatNumber(int number, int y)
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

void ComPawnAnim::SetDebugLabel(std::string text)
{
	m_pDebugLabel->setString(text);
}

void ComPawnAnim::CreateAnimFSM(int fsmType)
{
	if (m_pAnimFsm != nullptr)
		return;

	switch (fsmType)
	{
	case AFT_Simple:
		m_pAnimFsm = new AnimFSMSimple(this);
		break;
	default:
		m_pAnimFsm = new AnimFSMSimple(this);
		break;
	}

	m_pAnimFsm->Initialize();
}