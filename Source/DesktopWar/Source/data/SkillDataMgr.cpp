
// d:)
#include "SkillDataMgr.h"

using namespace Genius;

bool SkillData::ParseBuffer(TabFile& reader, int row)
{
	int col = 1;		// ignore first column.
	id								= reader.GetIntValue(row, col++);
	findTargetStyle		= reader.GetIntValue(row, col++);
	findTargetRadius	= reader.GetIntValue(row, col++);
	targetTeam			= reader.GetIntValue(row, col++);
	costType				= reader.GetIntValue(row, col++);
	costNum				= reader.GetIntValue(row, col++);
	coolTime				= reader.GetFloatValue(row, col++);
	bulletID = reader.GetIntValue(row, col++);
	for (int i = 0; i < MaxBuffNum; ++i)
		buffs[i]						= reader.GetIntValue(row, col++);

	return true;
}

/************************************************************************/
/*                                                   SkillDataMgr                   */
/************************************************************************/
bool SkillDataMgr::Init()
{
	return IDataManager::Init();
}

void SkillDataMgr::Destroy()
{
	for (auto iter = m_SkillInfoList.begin(); iter != m_SkillInfoList.end(); ++iter)
	{
		if (iter->second)
			delete iter->second;
	}
	m_SkillInfoList.clear();
}

bool SkillDataMgr::LoadData(TabFile& reader, int row)
{
	SkillData* SkillInfo = new SkillData;
	bool ret = SkillInfo->ParseBuffer(reader, row);
	if (ret)
		m_SkillInfoList.insert(std::make_pair(SkillInfo->id, SkillInfo));

	return true;
}

SkillData* SkillDataMgr::GetSkillData(int id)
{
	static SkillData set;
	auto iter = m_SkillInfoList.find(id);
	if (iter != m_SkillInfoList.end())
		return iter->second;
	else
		return nullptr;
}
