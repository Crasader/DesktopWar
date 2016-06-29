

#include "BuffActionDataMgr.h"

using namespace Genius;

bool BuffActionData::ParseBuffer(TabFile& reader, int row)
{
	int col = 1;		// ignore first column.
	id	= reader.GetIntValue(row, col++);
	buffType = reader.GetIntValue(row, col++);
	action = reader.GetStringValue(row, col++);
	for (int i = 0; i < MaxActionParamNum; ++i)
		params[i] = reader.GetIntValue(row, col++);

	return true;
}

/************************************************************************/
/*                                                   BuffActionDataMgr                   */
/************************************************************************/
bool BuffActionDataMgr::Init()
{
	return IDataManager::Init();
}

void BuffActionDataMgr::Destroy()
{
	for (auto iter = m_BuffInfoList.begin(); iter != m_BuffInfoList.end(); ++iter)
	{
		if (iter->second)
			delete iter->second;
	}
	m_BuffInfoList.clear();
}

bool BuffActionDataMgr::LoadData(TabFile& reader, int row)
{
	BuffActionData* BuffInfo = new BuffActionData;
	bool ret = BuffInfo->ParseBuffer(reader, row);
	if (ret)
		m_BuffInfoList.insert(std::make_pair(BuffInfo->id, BuffInfo));

	return true;
}

BuffActionData* BuffActionDataMgr::GetBuffActionData(int id)
{
	static BuffActionData set;
	auto iter = m_BuffInfoList.find(id);
	if (iter != m_BuffInfoList.end())
		return iter->second;
	else
		return nullptr;
}
