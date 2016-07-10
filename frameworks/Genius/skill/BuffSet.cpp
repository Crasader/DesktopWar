
#include "BuffSet.h"
#include "data/auto/Buff_cfg.hpp"
#include "data/ConfigPool.h"


using namespace Genius;
using namespace cfg;


int BuffSet::AddBuff(int senderID, int buffTemplateID)
{
	auto buffTempData = FIND_CFG(Buff_cfg, buffTemplateID);
	Buff newBuff;
	newBuff.Init(buffTemplateID);
	for (auto iter = m_buffInsts.begin(); iter != m_buffInsts.end(); ++iter)
	{
		Buff& curBuff = iter->second;
		if (curBuff.IsAlive())
		{
			int curBuffInstID = curBuff.GetInstID();
			int curPileType = curBuff.GetPileType();
			if (newBuff.GetSeries() == curBuff.GetSeries())
			{
				if (curPileType == Pile_Replace)
				{
					return ReplaceBuff(curBuffInstID, senderID, buffTemplateID);
				}
				else if (curPileType == Pile_OnlyOne)
				{
					return false;
				}
			}
		}
	}

	return TileBuff(senderID, buffTemplateID);
}

int BuffSet::ReplaceBuff(int buffInstID, int senderID, int buffTemplateID)
{
	if (RemoveBuff(buffInstID))
	{
		return TileBuff(senderID, buffTemplateID);
	}
	return EBuffRet_Invalid;
}

int BuffSet::TileBuff(int senderID, int buffTemplateID)
{
	Buff newBuff;
	m_instIDCounter++;
	m_buffInsts[m_instIDCounter] = newBuff;
	m_buffInsts[m_instIDCounter].SetInstID(m_instIDCounter);
	m_buffInsts[m_instIDCounter].Init(buffTemplateID);
	m_buffInsts[m_instIDCounter].m_senderID = senderID;
	m_buffInsts[m_instIDCounter].m_receiverID = m_ownerID;
	m_buffInsts[m_instIDCounter].m_alive = true;
	
	return m_buffInsts[m_instIDCounter].AddPile();
}

int BuffSet::RemoveBuff(int buffInstID)
{
	auto iterFind = m_buffInsts.find(buffInstID);
	if (iterFind != m_buffInsts.end() && iterFind->second.IsAlive())
	{
		iterFind->second.RemoveAllPile();
		m_buffInsts.erase(iterFind);
		return EBuffRet_True;
	}
	return EBuffRet_Invalid;
}

void BuffSet::Update(float elpase)
{
	for (auto iter = m_buffInsts.begin(); iter != m_buffInsts.end();)
	{
		int nRet = 0;
		if ((*iter).second.IsAlive())
		{
			nRet = (*iter).second.Update(elpase);
		}

		if (nRet & EBuffRet_Kill)
		{
			auto eraseIT = iter;
			++iter;
			KillBuff((*eraseIT).first);
		}
		else
		{
			++iter;
		}
	}

	DealWithDelBuff();
}

void BuffSet::KillAllBuff()
{
	for (auto iter = m_buffInsts.begin(); iter != m_buffInsts.end(); ++iter)
	{
		if (iter->second.IsAlive())
			iter->second.RemoveAllPile();
	}
	m_buffInsts.clear();
}

int BuffSet::KillBuff(int oldBuffInstID)
{
	auto it = m_buffInsts.find(oldBuffInstID);
	if (it != m_buffInsts.end() && (*it).second.IsAlive())
	{
		(*it).second.RemoveAllPile();

		m_deleteSet.push_back(oldBuffInstID);

		return oldBuffInstID;
	}
	return EBuffRet_Invalid;
}

void BuffSet::DealWithDelBuff()
{
	if (m_deleteSet.empty())
		return;

	for (auto iter = m_deleteSet.begin(); iter != m_deleteSet.end(); ++iter)
	{
		auto del_it = m_buffInsts.find(*iter);
		if (del_it != m_buffInsts.end())
		{
			m_buffInsts.erase(del_it);
		}
	}
	m_deleteSet.clear();
}