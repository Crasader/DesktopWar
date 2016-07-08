#ifndef _GENIUS_SKILL_H_
#define _GENIUS_SKILL_H_

#include <vector>

namespace cfg
{
	class Skill_cfg;
}

namespace Genius
{
	// ¹¥»÷(Ë÷µÐ)·½Ê½
	enum FindingTargetStyle
	{
		FTS_Unknown,
		FTS_One,
		FTS_Scope,
		FTS_Entire,
	};

	enum TargetTeamType
	{
		TTT_Unknown,
		TTT_Enemy,
		TTT_Self,
	};

	class Skill
	{
	public:
		static const int BuffCount = 3;
	public:
		Skill(int owner) :
			m_ownerID(owner),
			m_skillData(nullptr)
		{}

		bool		CanTrigger(int target);
		bool		Trigger(int owner, int target);

	private:
		void _TargetOne(int owner, int target);
		void _TargetScope(int owner, int target);
		void _TargetEntire(int owner);

		void _ActiveMe();
		void _DeactiveMe();

	public:
		int GetOwner(){ return m_ownerID; }
		void		SetSkillCfg(int tp);
		cfg::Skill_cfg* GetSkillCfg(){ return m_skillData; }
		std::vector<int>& GetTargetList(){ return targetList; }

	private:
		cfg::Skill_cfg* m_skillData;
		int			m_ownerID;
		std::vector<int> targetList;
	};

}

#endif