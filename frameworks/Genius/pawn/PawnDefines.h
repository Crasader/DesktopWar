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

	namespace PawnAnimName
	{
		const std::string IdleLeft = "idle_left";
		const std::string IdleRight = "idle_right";
		const std::string DieLeft = "die_left";
		const std::string DieRight = "die_right";

		const std::string MoveLeft = "move_left";
		const std::string MoveRight = "move_right";
		const std::string MoveUp = "move_up";
		const std::string MoveDown = "move_down";

		const std::string Attack1Left = "attack_left";
		const std::string Attack1Right = "attack_right";
		const std::string Attack2Left = "attack2_left";
		const std::string Attack2Right = "attack2_right";
		const std::string Attack3Left = "attack3_left";
		const std::string Attack3Right = "attack3_right";
		const std::string Skill1Left = "skill_left";
		const std::string Skill1Right = "skill_right";
		const std::string Skill2Left = "skill2_left";
		const std::string Skill2Right = "skill2_right";
		const std::string Skill3Left = "skill3_left";
		const std::string Skill3Right = "skill3_right";

	}

	enum TargetType
	{
		Target_Entity,			// 以某entity做目标
		Target_Location,		// 以某位置做目标
	};
	
};

#endif