#ifndef _GENIUS_SKILL_H_
#define _GENIUS_SKILL_H_

namespace Genius
{
	// ¹¥»÷(Ë÷µÐ)·½Ê½
	enum FindingTargetStyle
	{
		FTS_Unknown,
		FTS_One,
		FTS_Scope,
		FTS_Entire,
		FTS_Bullet,
	};

	enum TargetTeamType
	{
		TTT_Unknown,
		TTT_Enemy,
		TTT_Self,
	};

	class SkillData;
	class Skill
	{
	public:
		Skill(int owner) :
			m_ownerID(owner),
			m_skillData(nullptr)
		{}
		void		SetSkillType(int tp);
		bool		CanTrigger(int target);
		bool		Trigger(int owner, int target);

	private:
		bool TargetOne(int owner, int target);
		bool TargetScope(int owner, int target);
		bool TargetEntire(int owner);
		bool TargetBullet(int owner, int target);

	private:
		SkillData* m_skillData;
		int			m_ownerID;
	};

}

#endif