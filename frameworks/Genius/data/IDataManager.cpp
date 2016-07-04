
#include "IDataManager.h"
#include "TabFile.h"
#include "Log.h"

using namespace Genius;


bool IDataManager::Init()
{
	TabFile tabFileReader;
	std::string filePath = GetName();
	if (!tabFileReader.LoadFile(filePath))
	{
		Log::Error("load file failed : %s", filePath.c_str());
		return false;
	}

	int rowCount = tabFileReader.GetRowCount();
	int colCount = tabFileReader.GetColCount();
	if (rowCount < 1 || colCount < 1)
	{
		Log::Error("load file failed : %s", filePath.c_str());
		return false;
	}

	for (int i = 0; i < rowCount; ++i)
	{
		bool ret = LoadData(tabFileReader, i);
		if (!ret)
		{
			Log::Error("load data failed, file %s, row %d", filePath.c_str(), rowCount);
			return false;
		}
	}

	Log::Info("Load file done : %s", filePath.c_str());

	return true;
}