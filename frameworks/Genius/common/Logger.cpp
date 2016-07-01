
#include "Logger.h"
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <windows.h>

#define BUFFER_LEN 1024

void Logger::LogInfo(const char* pInfo, ...)
{
	char buffer[BUFFER_LEN] = "";
	time_t t = time(nullptr);
	tm* pTm = localtime(&t);
	int pos = _snprintf(buffer, strlen(pInfo) + strlen("[Info]00:00:00 : "), "[Info]%02d:%02d:%02d : ", pTm->tm_hour, pTm->tm_min, pTm->tm_sec);

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
	char buffer[BUFFER_LEN] = "";
	time_t t = time(nullptr);
	tm* pTm = localtime(&t);
	int pos = _snprintf(buffer, strlen(pInfo) + strlen("[Warning]00:00:00 : "), "[Warning]%02d:%02d:%02d : ", pTm->tm_hour, pTm->tm_min, pTm->tm_sec);

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
	char buffer[BUFFER_LEN] = "";
	time_t t = time(nullptr);
	tm* pTm = localtime(&t);
	int pos = _snprintf(buffer, strlen(pInfo) + strlen("[Error]00:00:00 : "), "[Error]%02d:%02d:%02d : ", pTm->tm_hour, pTm->tm_min, pTm->tm_sec);

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
	char buffer[BUFFER_LEN] = "";
	time_t t = time(nullptr);
	tm* pTm = localtime(&t);
	int pos = _snprintf(buffer, strlen(pInfo) + strlen("[Script]00:00:00 : "), "[Script]%02d:%02d:%02d : %s", pTm->tm_hour, pTm->tm_min, pTm->tm_sec, pInfo);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
	printf("%s\n", buffer);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


