// d:)
#include "PawnAnimSystem.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/PawnDefines.h"

using namespace Genius;

void PawnAnimSystem::Initialize()
{
	positionMapper.init(*world);
	pawnAnimMapper.init(*world);
	pawnDirectionMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_startAction);
	EventManager::GetInstance().AddListener(this, Event_updateAction);
}

void PawnAnimSystem::ProcessEntity(Entity* e)
{
	PawnAnimCom* render = pawnAnimMapper.get(e);
	PositionCom* pos = positionMapper.get(e);
	if (render && render->m_pAvatarRoot)
		render->m_pAvatarRoot->setPosition(pos->x, pos->y);
};

bool PawnAnimSystem::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	switch (eType)
	{
	case Event_startAction:
	{
		const ActionEvent & actionEvent = static_cast<const ActionEvent &>(event);
		PawnAnimCom* animCom = pawnAnimMapper.get(actionEvent.entity);
		PawnDirectionCom* dirCom = pawnDirectionMapper.get(actionEvent.entity);
		this->PlayAnimation(animCom, dirCom, actionEvent.action);
	}
		break;
	case Event_updateAction:
	{
		const UpdateActionEvent & actionEvent = static_cast<const UpdateActionEvent &>(event);
		PawnAnimCom* animCom = pawnAnimMapper.get(actionEvent.entity);
		PawnDirectionCom* dirCom = pawnDirectionMapper.get(actionEvent.entity);
		this->PlayAnimation(animCom, dirCom, (ActionType)animCom->m_curAction);
	}
		break;
	}

	return true;
}

void PawnAnimSystem::PlayAnimation(PawnAnimCom* animCom, PawnDirectionCom* dirCom, ActionType act)
{
	if (nullptr == animCom || nullptr == dirCom)
		return;

	if (act <= Action_Min || act >= Action_Max)
	{
		printf("invalid act\n");
		return;
	}

	animCom->m_curAction = act;

	if (nullptr == animCom->m_pAvatarRoot)
		return;

	

	switch (act)
	{
	case Action_Idle:
		PlayIdle(animCom, dirCom);
		break;
	case Action_Move:
		PlayMove(animCom, dirCom);
		break;
	case Action_Attack_Near:
		PlayAtkNear(animCom, dirCom);
		break;
	case Action_Attack_Near2:
		PlayAtkNear2(animCom, dirCom);
		break;
	case Action_Attack_Far:
		PlayAtkFar(animCom, dirCom);
		break;
	case Action_Skill1:
		PlaySkill1(animCom, dirCom);
		break;
	case Action_Skill2:
		PlaySkill2(animCom, dirCom);
		break;
	case Action_Skill3:
		PlaySkill3(animCom, dirCom);
		break;
	case Action_Die:
		PlayDie(animCom, dirCom);
		break;
	default:
		printf("unknown action\n");
		break;
	}
}

void PawnAnimSystem::PlayIdle(PawnAnimCom* animCom, PawnDirectionCom* dirCom)
{
	if (dirCom->m_faceDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::IdleLeft);
	else
		animCom->PlayAnimation(PawnAnimName::IdleRight);
}

void PawnAnimSystem::PlayDie(PawnAnimCom* animCom, PawnDirectionCom* dirCom)
{
	if (dirCom->m_faceDir & Face_Left)
		animCom->PlayAnimation("die_left");
	else
		animCom->PlayAnimation("die_right");
}

void PawnAnimSystem::PlayMove(PawnAnimCom* animCom, PawnDirectionCom* dirCom)
{
	bool needAdjust = false;

	if (dirCom->m_faceDir == Face_Left)
	{
		animCom->PlayAnimation(PawnAnimName::MoveLeft);
	}
	else if (dirCom->m_faceDir == Face_Right)
	{
		animCom->PlayAnimation(PawnAnimName::MoveRight);
	}
	else if (dirCom->m_faceDir == Face_Up)
	{
		if (animCom->HaveThisAnimation(PawnAnimName::MoveUp))
			animCom->PlayAnimation(PawnAnimName::MoveUp);
		else
			needAdjust = true;
	}
	else if (dirCom->m_faceDir == Face_Down)
	{
		if (animCom->HaveThisAnimation(PawnAnimName::MoveDown))
			animCom->PlayAnimation(PawnAnimName::MoveDown);
		else
			needAdjust = true;
	}
	else if (dirCom->m_faceDir & Face_Up)
	{
		if (animCom->HaveThisAnimation(PawnAnimName::MoveUp))
			animCom->PlayAnimation(PawnAnimName::MoveUp);
		else
		{
			if (dirCom->m_faceDir & Face_Left)
				animCom->PlayAnimation(PawnAnimName::MoveLeft);
			else
				animCom->PlayAnimation(PawnAnimName::MoveRight);
		}
	}
	else if (dirCom->m_faceDir & Face_Down)
	{
		if (animCom->HaveThisAnimation(PawnAnimName::MoveDown))
			animCom->PlayAnimation(PawnAnimName::MoveDown);
		else
		{
			if (dirCom->m_faceDir & Face_Right)
				animCom->PlayAnimation(PawnAnimName::MoveRight);
			else
				animCom->PlayAnimation(PawnAnimName::MoveLeft);
		}
	}
	// 没有对应动画，也没播放替代动作。
	if (needAdjust)
	{
		if (dirCom->m_lastFaceDir & Face_Left)
			animCom->PlayAnimation(PawnAnimName::MoveLeft);
		else
			animCom->PlayAnimation(PawnAnimName::MoveRight);
	}
}

void PawnAnimSystem::PlayAtkNear(PawnAnimCom* animCom, PawnDirectionCom* dirCom)
{
	if (dirCom->m_faceDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Attack1Left);
	else
		animCom->PlayAnimation(PawnAnimName::Attack1Right);
}

void PawnAnimSystem::PlayAtkNear2(PawnAnimCom* animCom, PawnDirectionCom* dirCom)
{
	if (dirCom->m_faceDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Attack2Left);
	else
		animCom->PlayAnimation(PawnAnimName::Attack2Right);
}

void PawnAnimSystem::PlayAtkFar(PawnAnimCom* animCom, PawnDirectionCom* dirCom)
{
	if (dirCom->m_faceDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Attack3Left);
	else
		animCom->PlayAnimation(PawnAnimName::Attack3Right);
}

void PawnAnimSystem::PlaySkill1(PawnAnimCom* animCom, PawnDirectionCom* dirCom)
{
	if (dirCom->m_faceDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Skill1Left);
	else
		animCom->PlayAnimation(PawnAnimName::Skill1Right);
}

void PawnAnimSystem::PlaySkill2(PawnAnimCom* animCom, PawnDirectionCom* dirCom)
{
	if (dirCom->m_faceDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Skill2Left);
	else
		animCom->PlayAnimation(PawnAnimName::Skill2Right);
}

void PawnAnimSystem::PlaySkill3(PawnAnimCom* animCom, PawnDirectionCom* dirCom)
{
	if (dirCom->m_faceDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Skill3Left);
	else
		animCom->PlayAnimation(PawnAnimName::Skill3Right);
}
