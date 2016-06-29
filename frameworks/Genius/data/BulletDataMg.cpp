

#include "BulletDataMgr.h"

using namespace Genius;

bool BulletData::ParseBuffer(TabFile& reader, int row)
{
	int col = 1;		// ignore first column.
	id = reader.GetIntValue(row, col++);
	movable = reader.GetIntValue(row, col++);
	moveType = reader.GetIntValue(row, col++);
	targetIsEntity = reader.GetIntValue(row, col++) > 0;
	flySpeed = reader.GetIntValue(row, col++);
	findTargetDelay = reader.GetFloatValue(row, col++);
	maxLifeTime = reader.GetFloatValue(row, col++);
	boxWidth = reader.GetIntValue(row, col++);
	boxHeight = reader.GetIntValue(row, col++);
	bodyAnim = reader.GetStringValue(row, col++);
	tailAnim = reader.GetStringValue(row, col++);

	buffTargetStyle = reader.GetIntValue(row, col++);
	buffTargetRadius = reader.GetIntValue(row, col++);
	attackValue = reader.GetIntValue(row, col++);
	attackType = reader.GetIntValue(row, col++);
	for (int i = 0; i < BuffNum; ++i)
		buffs[i] = reader.GetIntValue(row, col++);

	return true;
}

/************************************************************************/
/*                                                   BulletDataMgr                   */
/************************************************************************/
bool BulletDataMgr::Init()
{
	return IDataManager::Init();
}

void BulletDataMgr::Destroy()
{
	for (auto iter = m_BulletInfoList.begin(); iter != m_BulletInfoList.end(); ++iter)
	{
		if (iter->second)
			delete iter->second;
	}
	m_BulletInfoList.clear();
}

bool BulletDataMgr::LoadData(TabFile& reader, int row)
{
	BulletData* BulletInfo = new BulletData;
	bool ret = BulletInfo->ParseBuffer(reader, row);
	if (ret)
		m_BulletInfoList.insert(std::make_pair(BulletInfo->id, BulletInfo));

	return true;
}

BulletData* BulletDataMgr::GetBulletData(int id)
{
	static BulletData set;
	auto iter = m_BulletInfoList.find(id);
	if (iter != m_BulletInfoList.end())
		return iter->second;
	else
		return nullptr;
}
