
#include "AnimSetSimple.h"
#include "pawn/PawnDefines.h"

using namespace Genius;

AnimSetSimple::AnimSetSimple(Armature* armature) :
AnimSet(armature)
{

}

AnimSetSimple::~AnimSetSimple()
{

}

const char* AnimSetSimple::GetIdleAnim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::IdleLeft.c_str();
	else
		return PawnAnimName::IdleRight.c_str();
}

const char* AnimSetSimple::GetMoveAnim(int direction)
{
	bool needAdjust = false;

	if (direction == Face_Left)
	{
		return PawnAnimName::MoveLeft.c_str();
	}
	else if (direction == Face_Right)
	{
		return PawnAnimName::MoveRight.c_str();
	}
	else if (direction == Face_Up)
	{
		if (HaveAnim(PawnAnimName::MoveUp.c_str()))
			return PawnAnimName::MoveUp.c_str();
		else
			needAdjust = true;
	}
	else if (direction == Face_Down)
	{
		if (HaveAnim(PawnAnimName::MoveDown.c_str()))
			return PawnAnimName::MoveDown.c_str();
		else
			needAdjust = true;
	}
	else if (direction & Face_Up)
	{
		if (HaveAnim(PawnAnimName::MoveUp.c_str()))
			return PawnAnimName::MoveUp.c_str();
		else
		{
			if (direction & Face_Left)
				return PawnAnimName::MoveLeft.c_str();
			else
				return PawnAnimName::MoveRight.c_str();
		}
	}
	else if (direction & Face_Down)
	{
		if (HaveAnim(PawnAnimName::MoveDown.c_str()))
			return PawnAnimName::MoveDown.c_str();
		else
		{
			if (direction & Face_Right)
				return PawnAnimName::MoveRight.c_str();
			else
				return PawnAnimName::MoveLeft.c_str();
		}
	}
	// 没有对应动画，也没播放替代动作。
	if (needAdjust)
	{
		if (direction & Face_Left)
			return PawnAnimName::MoveLeft.c_str();
		else
			return PawnAnimName::MoveRight.c_str();
	}
	else
		PawnAnimName::MoveLeft.c_str();
}

const char* AnimSetSimple::GetDieAnim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::DieLeft.c_str();
	else
		return PawnAnimName::DieRight.c_str();
}

const char* AnimSetSimple::GetAttackNearAnim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Attack1Left.c_str();
	else
		return PawnAnimName::Attack1Right.c_str();
}

const char* AnimSetSimple::GetAttackFarAnim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Attack2Left.c_str();
	else
		return PawnAnimName::Attack2Right.c_str();
}

const char* AnimSetSimple::GetSkill1Anim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Skill1Left.c_str();
	else
		return PawnAnimName::Skill1Right.c_str();
}

const char* AnimSetSimple::GetSkill2Anim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Skill2Left.c_str();
	else
		return PawnAnimName::Skill2Right.c_str();
}

const char* AnimSetSimple::GetSkill3Anim(int direction)
{
	if (direction & Face_Left)
		return PawnAnimName::Skill3Left.c_str();
	else
		return PawnAnimName::Skill3Right.c_str();
}
