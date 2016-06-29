

#include "BuffDataMgr.h"

using namespace Genius;

bool BuffData::ParseBuffer(TabFile& reader, int row)
{
	int col = 1;		// ignore first column.
	id	= reader.GetIntValue(row, col++);
	series = reader.GetIntValue(row, col++);
	hurtType = reader.GetIntValue(row, col++);
	duration = reader.GetIntValue(row, col++);
	jumpTime = reader.GetIntValue(row, col++);
	maxPileCount = reader.GetIntValue(row, col++);
	pileType = reader.GetIntValue(row, col++);
	
	actionID = reader.GetIntValue(row, col++);
	actionType = reader.GetIntValue(row, col++);
	switch (actionType)
	{
	case EActionType_Begin:
		beginActions.push_back(actionID);
		break;
	case EActionType_Cycle:
		cycleActions.push_back(actionID);
		break;
	case EActionType_Effect:
		effectActions.push_back(actionID);
		break;
	case EActionType_End:
		endActions.push_back(actionID);
		break;
	default:
		break;
	}

	return true;
}

/************************************************************************/
/*                                                   BuffDataMgr                   */
/************************************************************************/
bool BuffDataMgr::Init()
{
	return IDataManager::Init();
}

void BuffDataMgr::Destroy()
{
	for (auto iter = m_BuffInfoList.begin(); iter != m_BuffInfoList.end(); ++iter)
	{
		if (iter->second)
			delete iter->second;
	}
	m_BuffInfoList.clear();
}

bool BuffDataMgr::LoadData(TabFile& reader, int row)
{
	BuffData* BuffInfo = new BuffData;
	bool ret = BuffInfo->ParseBuffer(reader, row);
	if (ret)
		m_BuffInfoList.insert(std::make_pair(BuffInfo->id, BuffInfo));

	return true;
}

BuffData* BuffDataMgr::GetBuffData(int id)
{
	static BuffData set;
	auto iter = m_BuffInfoList.find(id);
	if (iter != m_BuffInfoList.end())
		return iter->second;
	else
		return nullptr;
}
