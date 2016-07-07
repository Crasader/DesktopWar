#ifndef _GENIUS_SKILLMGR_H_
#define _GENIUS_SKILLMGR_H_

#include <map>
#include "SkillSet.h"
#include "common/Singleton.h"

namespace Genius
{
	class SkillManager : public Singleton<SkillManager>
	{
	public:
		SkillManager();

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