#ifndef _GENIUS_SKILLSYSTEM_H_
#define _GENIUS_SKILLSYSTEM_H_

#include <map>
#include "SkillSet.h"

namespace Genius
{
	class SkillSystem
	{
	public:
		static SkillSystem& GetSingleton();
	private:
		SkillSystem();

	public:
		void		Update(float elapse);
		bool		LoadSkill(int owner, int skillID);
		bool		SaveSkill(int owner);
		void		ClearSkill(int owner);
		void		ClearAllSkill();
		bool		CanUseSkill(int owner, int target, int skill);
		bool		UseSkill(int owner, int target, int skill);

	private:
		std::map<int, SkillSet>		m_skillSets;
		float		m_timeCounter;
	};

}

#endif