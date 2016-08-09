
#include "BuffManager.h"

using namespace Genius;


BuffManager* BuffManager::GetMe()
{
	return BuffManager::GetSingleton();
}


BuffManager::BuffManager():
m_timeCounter(0)
{

}

void BuffManager::Update(float elapse)
{
	m_timeCounter += elapse;
	if (m_timeCounter < 1)
		return;
	m_timeCounter = 0;
	//
	for (auto iter = m_buffSets.begin(); iter != m_buffSets.end(); ++iter)
	{
		iter->second.Update(elapse);
	}
}

bool BuffManager::AddBuff(int senderID, int targetID, int buffID)
{
	auto iterFind = m_buffSets.find(targetID);
	if (iterFind == m_buffSets.end())
	{
		m_buffSets.insert(std::make_pair(targetID, BuffSet(targetID)));
	}
	iterFind = m_buffSets.find(targetID);
	iterFind->second.AddBuff(senderID, buffID);

	return true;
}

void BuffManager::RemoveBuff(int targetID)
{
	auto iterFind = m_buffSets.find(targetID);
	if (iterFind != m_buffSets.end())
		iterFind->second.KillAllBuff();
}

void BuffManager::RemoveAllBuff()
{
	for (auto iter = m_buffSets.begin(); iter != m_buffSets.end(); ++iter)
	{
		iter->second.KillAllBuff();
	}
}

int BuffManager::GetBuffCount()
{
	int count = 0;
	for (auto iter = m_buffSets.begin(); iter != m_buffSets.end(); ++iter)
	{
		count += iter->second.GetBuffCount();
	}
	return count;
}