
#include "TimeSystem.h"

using namespace Genius;


bool TimeSystem::Init()
{
	return true;
}

void TimeSystem::Tick(float time)
{
	m_lastTickTime = time;
	m_timeSinceStartup += time;
}

float TimeSystem::GetLastTickSecond()
{
	return m_lastTickTime;
}

float TimeSystem::GetTime()
{
	return m_timeSinceStartup;
}


