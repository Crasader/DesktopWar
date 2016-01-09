// d:)
#include "IDataManager.h"
#include "TabFile.h"
#include "Logger.h"

using namespace Genius;


bool IDataManager::Init()
{
	TabFile tabFileReader;
	std::string filePath = GetName();
	if (!tabFileReader.LoadFile(filePath))
	{
		Logger::LogError("load file failed : %s", filePath.c_str());
		return false;
	}

	int rowCount = tabFileReader.GetMaxRowCount();
	int colCount = tabFileReader.GetMaxColCount();
	if (rowCount < 1 || colCount < 1)
	{
		Logger::LogError("load file failed : %s", filePath.c_str());
		return false;
	}

	for (int i = 0; i < rowCount; ++i)
	{
		bool ret = LoadData(tabFileReader, i);
		if (!ret)
		{
			Logger::LogError("load data failed, file %s, row %d", filePath.c_str(), rowCount);
			return false;
		}
	}

	Logger::LogInfo("Load file done : %s", filePath.c_str());

	return true;
}