#ifndef _PAWN_DEFINE_H_
#define _PAWN_DEFINE_H_

#include <string>

namespace Genius
{
	// �������
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

	// �˺����
	enum HurtType
	{
		HTNone = 0,
		Phy = 1,
		Mag = 2,
	};

	//���Լ��㷽ʽ(�̶�ֵ���ٷֱȡ�npc����Ӧ��bullet����Ӧ)
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
		Action_Attack_Near,			// �����빥��
		Action_Attack_Near2,		// �����빥��2
		Action_Attack_Far,			// Զ���빥��
		Action_Skill1,
		Action_Skill2,
		Action_Skill3,
		Action_Die,
		Action_Max,
	};

	enum FaceType
	{
		Face_Min		= 1 << 0,
		Face_Left		= 1 << 1,
		Face_Right	= 1 << 2,
		Face_Up			= 1 << 3,
		Face_Down	= 1 << 4,
		Face_Turn		= 1 << 5,
		Face_Max		= 1 << 6,
	};

	/*enum PawnTeam
	{
		Team_None,
		Team_Human,
		Team_Monster,
	};*/

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
		Target_Entity,			// ��ĳentity��Ŀ��
		Target_Location,		// ��ĳλ����Ŀ��
	};
	
};

#endif