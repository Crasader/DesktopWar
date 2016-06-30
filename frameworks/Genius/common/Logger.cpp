
#include "Logger.h"
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <windows.h>

void Logger::LogInfo(const char* pInfo, ...)
{
	char buffer[10240] = "";
	time_t t = time(nullptr);
	tm* pTm = localtime(&t);
	int pos = sprintf(buffer, "[Info]%02d:%02d:%02d : ", pTm->tm_hour, pTm->tm_min, pTm->tm_sec);

	va_list ap;
	va_start(ap, pInfo);
	vsprintf(buffer + pos, pInfo, ap);
	va_end(ap);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("%s\n", buffer);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Logger::LogWarning(const char* pInfo, ...)
{
	char buffer[10240] = "";
	time_t t = time(nullptr);
	tm* pTm = localtime(&t);
	int pos = sprintf(buffer, "[Warning]%02d:%02d:%02d : ", pTm->tm_hour, pTm->tm_min, pTm->tm_sec);

	va_list ap;
	va_start(ap, pInfo);
	vsprintf(buffer + pos, pInfo, ap);
	va_end(ap);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
	printf("%s\n", buffer);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Logger::LogError(const char* pInfo, ...)
{
	char buffer[10240] = "";
	time_t t = time(nullptr);
	tm* pTm = localtime(&t);
	int pos = sprintf(buffer, "[Error]%02d:%02d:%02d : ", pTm->tm_hour, pTm->tm_min, pTm->tm_sec);

	va_list ap;
	va_start(ap, pInfo);
	vsprintf(buffer + pos, pInfo, ap);
	va_end(ap);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("%s\n", buffer);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Logger::print(const char* pInfo)
{
	LogWarning(pInfo);
}


