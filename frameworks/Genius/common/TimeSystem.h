#ifndef _TIME_SYSTEM_H_
#define _TIME_SYSTEM_H_

#include "common/Singleton.h"

namespace Genius
{
	class TimeSystem : public Genius::Singleton<TimeSystem>
	{
	public:
		TimeSystem() :
			m_lastTickTime(0){}
		virtual ~TimeSystem(){}

		bool		Init();
		void		Tick(float time);
		float	GetLastTickSecond();

	private:
		float		m_lastTickTime;
	};
};
#endif