#ifndef _PAWN_DEFINE_H_
#define _PAWN_DEFINE_H_

#include <string>

namespace Genius
{
	// 属性类别
	enum AttrType
	{
		ATNone = 0,
		HP = 1,
		MoveSpeed = 2,
		AttackSpeed = 3,
		AttackStren = 4,
		DefencePhy = 5,
		DefenceMag = 6,
		Dodge = 7,

		Count,
	};

	// 伤害类别
	enum HurtType
	{
		HTNone = 0,
		Phy = 1,
		Mag = 2,
	};

	//属性计算方式(固定值、百分比、npc自适应、bullet自适应)
	enum CalcType
	{
		CTNone = 0,
		Fixed = 1,
		Percent = 2,
		NPC = 3,
		Bullet = 4,
	};

	enum ActionType
	{
		Action_Min,
		Action_Idle,
		Action_Move,
		Action_Attack_Near,			// 近距离攻击
		Action_Attack_Near2,		// 近距离攻击2
		Action_Attack_Far,			// 远距离攻击
		Action_Skill1,
		Action_Skill2,
		Action_Skill3,
		Action_Die,
		Action_Max,
	};

	

	enum TargetType
	{
		Target_Entity,			// 以某entity做目标
		Target_Location,		// 以某位置做目标
	};
	
};

#endif