#ifndef _GENIUS_LOGGER_H_
#define _GENIUS_LOGGER_H_

class Log
{
public:
	static void Info(const char* pInfo, ...);
	static void Warning(const char* pInfo, ...);
	static void Error(const char* pInfo, ...);

	static void print(const char* pInfo);
};

#endif