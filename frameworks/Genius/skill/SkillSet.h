#ifndef _GENIUS_SKILLSET_H_
#define _GENIUS_SKILLSET_H_

#include <map>
#include "Skill.h"

namespace Genius
{
	class SkillSet
	{
	public:
		SkillSet(int owner) :
			m_ownerID(owner)
		{}

		void		Update(float elpase);
		bool		CanUseSkill(int owner, int target, int skill);
		bool		UseSkill(int owner, int target, int skill);
		void		AddSkill(int skill);
		void		Clear();

	private:
		std::map<int, Skill>		m_skills;
		int								m_ownerID;
	};

}

#endif