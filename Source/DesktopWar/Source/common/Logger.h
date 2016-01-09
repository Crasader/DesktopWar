#ifndef _GENIUS_LOGGER_H_
#define _GENIUS_LOGGER_H_

class Logger
{
public:
	static void LogInfo(const char* pInfo, ...);
	static void LogWarning(const char* pInfo, ...);
	static void LogError(const char* pInfo, ...);
};

#endif