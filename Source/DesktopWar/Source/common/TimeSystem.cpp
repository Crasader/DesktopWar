
#include "TimeSystem.h"

using namespace Genius;

TimeSystem& TimeSystem::GetInstance()
{
	static TimeSystem inst;
	return inst;
}

bool TimeSystem::Init()
{
	return true;
}

void TimeSystem::Tick(float time)
{
	m_lastTickTime = time;
}

float TimeSystem::GetLastTickSecond()
{
	return m_lastTickTime;
}