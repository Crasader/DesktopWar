
// d:)
#include "RoleDataMgr.h"

using namespace Genius;

bool RoleData::ParseBuffer(TabFile& reader, int row)
{
	int col = 0;
	id = reader.GetIntValue(row, col++);
	nameID = reader.GetStringValue(row, col++);
	nameCN = reader.GetStringValue(row, col++);
	animSetName = reader.GetStringValue(row, col++);
	bevTreeFile = reader.GetStringValue(row, col++);
	moveSpeed = reader.GetFloatValue(row, col++);
	viewRange = reader.GetFloatValue(row, col++);
	fightRangeNear = reader.GetIntValue(row, col++);
	fightRangeFar = reader.GetIntValue(row, col++);
	baseLife = reader.GetIntValue(row, col++);
	attackValue = reader.GetIntValue(row, col++);
	attackType = reader.GetIntValue(row, col++);
	antiPhysicValue = reader.GetIntValue(row, col++);
	antiMagicValue = reader.GetIntValue(row, col++);
	dodgeValue = reader.GetIntValue(row, col++);
	normalSkill1 = reader.GetIntValue(row, col++);
	maxAttack1Times = reader.GetIntValue(row, col++);
	normalSkill2 = reader.GetIntValue(row, col++);
	specialSkill1 = reader.GetIntValue(row, col++);
	specialSkill2 = reader.GetIntValue(row, col++);
	specialSkill3 = reader.GetIntValue(row, col++);
	lifeBarType = reader.GetIntValue(row, col++);
	lifeBarHeight = reader.GetIntValue(row, col++);
	IdleDuration = reader.GetFloatValue(row, col++);
	IdleTurnFaceTime = reader.GetFloatValue(row, col++);
	WanderDuration = reader.GetFloatValue(row, col++);
	WanderChangeDirTime = reader.GetFloatValue(row, col++);
	DeadBodyTime = reader.GetFloatValue(row, col++);
	bulletX = reader.GetIntValue(row, col++);
	bulletY = reader.GetIntValue(row, col++);

	return true;
}

/************************************************************************/
/*                                                   RoleDataMgr                   */
/************************************************************************/
bool RoleDataMgr::Init()
{
	return IDataManager::Init();
}

void RoleDataMgr::Destroy()
{
	for (auto iter = m_roleInfoList.begin(); iter != m_roleInfoList.end(); ++iter)
	{
		if (iter->second)
			delete iter->second;
	}
	m_roleInfoList.clear();
}

bool RoleDataMgr::LoadData(TabFile& reader, int row)
{
	RoleData* roleInfo = new RoleData;
	bool ret = roleInfo->ParseBuffer(reader, row);
	if (ret)
		m_roleInfoList.insert(std::make_pair(roleInfo->id, roleInfo));

	return true;
}

RoleData* RoleDataMgr::GetRoleData(int id)
{
	auto iter = m_roleInfoList.find(id);
	if (iter != m_roleInfoList.end())
		return iter->second;
	else
		return nullptr;
}

RoleData* RoleDataMgr::GetRoleData(std::string name)
{
	for (auto iter = m_roleInfoList.begin(); iter != m_roleInfoList.end(); ++iter)
	{
		if (iter->second->nameID == name)
			return iter->second;
	}
	return nullptr;
}
