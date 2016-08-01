#ifndef _TIME_SYSTEM_H_
#define _TIME_SYSTEM_H_

#include "common/Singleton.h"

namespace Genius
{
	class TimeSystem : public Genius::Singleton<TimeSystem>
	{
	public:
		TimeSystem() :
			m_startTime(0),
			m_lastTickTime(0),
			m_timeSinceStartup(0)
		{}
		virtual ~TimeSystem()
		{}

		bool		Init();
		void		Tick(float time);
		float		GetLastTickSecond();
		float		GetTimeSinceStart();

		static float TimeSinceStart();

	private:
		unsigned long m_startTime;
		float		m_lastTickTime;
		float		m_timeSinceStartup;
	};
};
#endif