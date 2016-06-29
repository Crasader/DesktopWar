#ifndef _TIME_SYSTEM_H_
#define _TIME_SYSTEM_H_

namespace Genius
{
	class TimeSystem
	{
	public:
		static TimeSystem&	GetInstance();
		virtual ~TimeSystem(){}

		bool		Init();

		void		Tick(float time);

		float	GetLastTickSecond();

	private:
		TimeSystem() :
			m_lastTickTime(0)
		{}

	private:
		float		m_lastTickTime;
	};
};
#endif