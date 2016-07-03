
#include "SystemPawnAnim.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "pawn/PawnDefines.h"

using namespace Genius;

void SystemPawnAnim::Initialize()
{
	positionMapper.init(*world);
	pawnAnimMapper.init(*world);
	pawnDirectionMapper.init(*world);

	// register event.
	//EventManager::GetSingleton()->AddListener(this, Event_startAction);
	//EventManager::GetSingleton()->AddListener(this, Event_updateAction);
}

void SystemPawnAnim::ProcessEntity(Entity* e)
{
	ComPawnAnim* render = pawnAnimMapper.get(e);
	ComPosition* pos = positionMapper.get(e);
	if (render && render->m_pAvatarRoot)
		render->m_pAvatarRoot->setPosition(pos->x, pos->y);
};

bool SystemPawnAnim::HandleEvent(IEventData const &event)
{
	EventType eType = event.GetType();

	/*switch (eType)
	{
	case Event_startAction:
	{
		const ActionEvent & actionEvent = static_cast<const ActionEvent &>(event);
		ComPawnAnim* animCom = pawnAnimMapper.get(actionEvent.entity);
		ComPawnDirection* dirCom = pawnDirectionMapper.get(actionEvent.entity);
		this->PlayAnimation(animCom, dirCom, actionEvent.action);
	}
		break;
	case Event_updateAction:
	{
		const UpdateActionEvent & actionEvent = static_cast<const UpdateActionEvent &>(event);
		ComPawnAnim* animCom = pawnAnimMapper.get(actionEvent.entity);
		ComPawnDirection* dirCom = pawnDirectionMapper.get(actionEvent.entity);
		this->PlayAnimation(animCom, dirCom, (ActionType)animCom->m_curAction);
	}
		break;
	}*/

	return true;
}

void SystemPawnAnim::PlayAnimation(ComPawnAnim* animCom, ComPawnDirection* dirCom, ActionType act)
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

void SystemPawnAnim::PlayIdle(ComPawnAnim* animCom, ComPawnDirection* dirCom)
{
	if (dirCom->m_currentDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::IdleLeft);
	else
		animCom->PlayAnimation(PawnAnimName::IdleRight);
}

void SystemPawnAnim::PlayDie(ComPawnAnim* animCom, ComPawnDirection* dirCom)
{
	if (dirCom->m_currentDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::DieLeft);
	else
		animCom->PlayAnimation(PawnAnimName::DieRight);
}

void SystemPawnAnim::PlayMove(ComPawnAnim* animCom, ComPawnDirection* dirCom)
{
	bool needAdjust = false;

	if (dirCom->m_currentDir == Face_Left)
	{
		animCom->PlayAnimation(PawnAnimName::MoveLeft);
	}
	else if (dirCom->m_currentDir == Face_Right)
	{
		animCom->PlayAnimation(PawnAnimName::MoveRight);
	}
	else if (dirCom->m_currentDir == Face_Up)
	{
		if (animCom->HaveThisAnimation(PawnAnimName::MoveUp))
			animCom->PlayAnimation(PawnAnimName::MoveUp);
		else
			needAdjust = true;
	}
	else if (dirCom->m_currentDir == Face_Down)
	{
		if (animCom->HaveThisAnimation(PawnAnimName::MoveDown))
			animCom->PlayAnimation(PawnAnimName::MoveDown);
		else
			needAdjust = true;
	}
	else if (dirCom->m_currentDir & Face_Up)
	{
		if (animCom->HaveThisAnimation(PawnAnimName::MoveUp))
			animCom->PlayAnimation(PawnAnimName::MoveUp);
		else
		{
			if (dirCom->m_currentDir & Face_Left)
				animCom->PlayAnimation(PawnAnimName::MoveLeft);
			else
				animCom->PlayAnimation(PawnAnimName::MoveRight);
		}
	}
	else if (dirCom->m_currentDir & Face_Down)
	{
		if (animCom->HaveThisAnimation(PawnAnimName::MoveDown))
			animCom->PlayAnimation(PawnAnimName::MoveDown);
		else
		{
			if (dirCom->m_currentDir & Face_Right)
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

void SystemPawnAnim::PlayAtkNear(ComPawnAnim* animCom, ComPawnDirection* dirCom)
{
	if (dirCom->m_currentDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Attack1Left);
	else
		animCom->PlayAnimation(PawnAnimName::Attack1Right);
}

void SystemPawnAnim::PlayAtkNear2(ComPawnAnim* animCom, ComPawnDirection* dirCom)
{
	if (dirCom->m_currentDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Attack2Left);
	else
		animCom->PlayAnimation(PawnAnimName::Attack2Right);
}

void SystemPawnAnim::PlayAtkFar(ComPawnAnim* animCom, ComPawnDirection* dirCom)
{
	if (dirCom->m_currentDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Attack3Left);
	else
		animCom->PlayAnimation(PawnAnimName::Attack3Right);
}

void SystemPawnAnim::PlaySkill1(ComPawnAnim* animCom, ComPawnDirection* dirCom)
{
	if (dirCom->m_currentDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Skill1Left);
	else
		animCom->PlayAnimation(PawnAnimName::Skill1Right);
}

void SystemPawnAnim::PlaySkill2(ComPawnAnim* animCom, ComPawnDirection* dirCom)
{
	if (dirCom->m_currentDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Skill2Left);
	else
		animCom->PlayAnimation(PawnAnimName::Skill2Right);
}

void SystemPawnAnim::PlaySkill3(ComPawnAnim* animCom, ComPawnDirection* dirCom)
{
	if (dirCom->m_currentDir & Face_Left)
		animCom->PlayAnimation(PawnAnimName::Skill3Left);
	else
		animCom->PlayAnimation(PawnAnimName::Skill3Right);
}
