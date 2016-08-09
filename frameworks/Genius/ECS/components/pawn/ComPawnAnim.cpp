
#include "ComPawnAnim.h"
#include "ComPawnAgent.h"
#include "ecs/components/common/ComRenderRoot.h"
#include "pawn/PawnDefines.h"
#include "data/auto/Role_cfg.hpp"
#include "data/ConfigPool.h"
#include "gfx/gfx.h"
#include "data/auto/Animation_cfg.hpp"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "skill/SkillManager.h"
#include "skill/BuffManager.h"
#include "../../core/Entity.h"
#include "pawn/PawnBlackboard.h"
#include "scripting/JSInvoker.h"
#include "Log.h"


USING_NS_CC;
using namespace Genius;
using namespace cfg;


COM_CREATE_FN_IMPL(ComPawnAnim);

/************************************************************************/
/*                              ComPawnAnim                                        */
/************************************************************************/
void ComPawnAnim::Create(int roleID)
{
	m_curAnimName = "";

	auto render = GetEntity()->GetComponent<ComRenderRoot>();
	if (nullptr == render)
	{
		Log::Error("ComPawnAnim.create : ComRenderRoot required .");
		return;
	}

	auto roleCfg = FIND_CFG(Role_cfg, roleID);
	if (roleCfg)
	{
		//root node
		m_pAvatarRoot = cocos2d::Node::create();
		render->AddChild(m_pAvatarRoot);
		
		// life bar
		m_pLifeBar = UIBar::create(roleCfg->lifeBarType);
		m_pLifeBar->setPosition(0, 0 + roleCfg->lifeBarHeight);
		m_pAvatarRoot->addChild(m_pLifeBar);
		//anim
		auto animCfg = FIND_CFG(Animation_cfg, roleCfg->animSetId);
		if (animCfg)
		{
			m_pBodyArmature = cocostudio::Armature::create(animCfg->name);
			m_pAvatarRoot->addChild(m_pBodyArmature);
			m_pBodyArmature->getAnimation()->setFrameEventCallFunc(CC_CALLBACK_3(ComPawnAnim::AnimationFrameCallback, this, std::placeholders::_4));
			m_pBodyArmature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_3(ComPawnAnim::AnimationMovementCallback, this));
			PlayAnimation("idle_left");
		}
		//debug label
		m_pDebugLabel = Label::createWithBMFont("res/font/arial16.fnt", "- -", TextHAlignment::LEFT);
		m_pDebugLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
		m_pDebugLabel->setScale(0.8f);
		m_pDebugLabel->setColor(Color3B(0, 255, 0));
		m_pDebugLabel->setPosition(0, -10);
		m_pAvatarRoot->addChild(m_pDebugLabel);
	}

	GetEntity()->GetComponent<ComPawnAgent>()->GetBlackboard()->AddActionHandler(this);

}

ComPawnAnim::~ComPawnAnim()
{
	
}

void	ComPawnAnim::OnAwake()
{

}

void ComPawnAnim::OnDestroy()
{

	GetEntity()->GetComponent<ComPawnAgent>()->GetBlackboard()->RemoveActionHandler(this);
}

void ComPawnAnim::HandleAction(PawnAction* pAction)
{
	
}

void ComPawnAnim::PlayAnimation(const std::string& name)
{
	m_curAnimName = name;
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

bool ComPawnAnim::ContainAnim(std::string name)
{
	return m_pBodyArmature->getAnimation()->getAnimationData()->getMovement(name) != nullptr;
}

void ComPawnAnim::AnimationMovementCallback(cocostudio::Armature *cca, cocostudio::MovementEventType movType, const std::string& animName)
{
	JSInvoker::Invoke_ArmatureMovementEvent(this->GetEntity()->GetId(), (int)movType, animName.c_str());

	switch (movType)
	{
	case cocostudio::START:
		//printf("START\n");
		break;
	case cocostudio::COMPLETE:
		EventManager::GetSingleton()->FireEvent(AnimationMovementEvent(animName, (int)movType, this->GetEntity()->GetId()));
		//printf("COMPLETE\n");
		break;
	case cocostudio::LOOP_COMPLETE:
		EventManager::GetSingleton()->FireEvent(AnimationMovementEvent(animName, (int)movType, this->GetEntity()->GetId()));
		break;
	default:
		break;
	}
}

void ComPawnAnim::AnimationFrameCallback(cocostudio::Bone* bone, const std::string& eventName, int oriIdx, int currentIdx)
{
	if (eventName == "")
		return;

	JSInvoker::Invoke_ArmatureFrameEvent(this->GetEntity()->GetId(), eventName.c_str());

	if (eventName == "attack")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetEntity(), UseSkillEvent::NormalSkill1));
	}
	else if (eventName == "attack2")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetEntity(), UseSkillEvent::NormalSkill2));
	}
	else if (eventName == "skill")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetEntity(), UseSkillEvent::SpecialSkill1));
	}
	else if (eventName == "skill2")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetEntity(), UseSkillEvent::SpecialSkill2));
	}
	else if (eventName == "skill3")
	{
		EventManager::GetSingleton()->FireEvent(UseSkillEvent(this->GetEntity(), UseSkillEvent::SpecialSkill3));
	}
	else
	{
		Log::Warning("unknown frame event : %s", eventName.c_str());
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



