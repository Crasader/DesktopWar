
#include "AnimSetSimple.h"
#include "pawn/PawnDefines.h"

using namespace Genius;

AnimSetSimple::AnimSetSimple(ComPawnAnim*	pComPawnAnim) :
AnimSet(pComPawnAnim)
{

}

AnimSetSimple::~AnimSetSimple()
{

}

const std::string& AnimSetSimple::GetIdleAnim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::IdleLeft;
	else
		return PawnAnimName::IdleRight;
}

const std::string& AnimSetSimple::GetMoveAnim(int direction)
{
	bool needAdjust = false;

	if (direction == Face_Left)
	{
		return PawnAnimName::MoveLeft;
	}
	else if (direction == Face_Right)
	{
		return PawnAnimName::MoveRight;
	}
	else if (direction == Face_Up)
	{
		if (HaveAnim(PawnAnimName::MoveUp.c_str()))
			return PawnAnimName::MoveUp;
		else
			needAdjust = true;
	}
	else if (direction == Face_Down)
	{
		if (HaveAnim(PawnAnimName::MoveDown.c_str()))
			return PawnAnimName::MoveDown;
		else
			needAdjust = true;
	}
	else if (direction & Face_Up)
	{
		if (HaveAnim(PawnAnimName::MoveUp.c_str()))
			return PawnAnimName::MoveUp;
		else
		{
			if (direction & Face_Left)
				return PawnAnimName::MoveLeft;
			else
				return PawnAnimName::MoveRight;
		}
	}
	else if (direction & Face_Down)
	{
		if (HaveAnim(PawnAnimName::MoveDown.c_str()))
			return PawnAnimName::MoveDown;
		else
		{
			if (direction & Face_Right)
				return PawnAnimName::MoveRight;
			else
				return PawnAnimName::MoveLeft;
		}
	}
	// 没有对应动画，也没播放替代动作。
	if (needAdjust)
	{
		if (direction & Face_Left)
			return PawnAnimName::MoveLeft;
		else
			return PawnAnimName::MoveRight;
	}
	
	return PawnAnimName::MoveLeft;
}

const std::string& AnimSetSimple::GetDieAnim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::DieLeft;
	else
		return PawnAnimName::DieRight;
}

const std::string& AnimSetSimple::GetAttackNearAnim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Attack1Left;
	else
		return PawnAnimName::Attack1Right;
}

const std::string& AnimSetSimple::GetAttackFarAnim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Attack2Left;
	else
		return PawnAnimName::Attack2Right;
}

const std::string& AnimSetSimple::GetSkill1Anim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Skill1Left;
	else
		return PawnAnimName::Skill1Right;
}

const std::string& AnimSetSimple::GetSkill2Anim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Skill2Left;
	else
		return PawnAnimName::Skill2Right;
}

const std::string& AnimSetSimple::GetSkill3Anim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Skill3Left;
	else
		return PawnAnimName::Skill3Right;
}
