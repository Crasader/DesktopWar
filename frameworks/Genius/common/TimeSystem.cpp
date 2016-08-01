
#include "TimeSystem.h"
#include <windows.h>

using namespace Genius;


bool TimeSystem::Init()
{
	m_startTime = GetTickCount();
	return true;
}

void TimeSystem::Tick(float time)
{
	m_lastTickTime = time;
	m_timeSinceStartup = (GetTickCount() - m_startTime)*0.001f;
}

float TimeSystem::GetLastTickSecond()
{
	return m_lastTickTime;
}

float TimeSystem::TimeSinceStart()
{
	return TimeSystem::GetSingleton()->GetTimeSinceStart();
}

float TimeSystem::GetTimeSinceStart()
{
	return m_timeSinceStartup;
}


