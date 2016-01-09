
#include "Performance.h"
#include "windows.h"

using namespace Genius;

int Performance::m_tickCountBegin = 0;

void Performance::Begin()
{
	m_tickCountBegin = GetTickCount();
}

float Performance::End()
{
	int tickCountNow = GetTickCount();
	float deltaSeconds = 0.001f*(tickCountNow - m_tickCountBegin);
	m_tickCountBegin = tickCountNow;
	return deltaSeconds;
}