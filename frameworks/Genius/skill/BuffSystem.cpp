
#include "BuffSystem.h"

using namespace Genius;

BuffSystem& BuffSystem::GetSingleton()
{
	static BuffSystem sys;
	return sys;
}

BuffSystem::BuffSystem():
m_timeCounter(0)
{

}

void BuffSystem::Update(float elapse)
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

bool BuffSystem::AddBuff(int senderID, int targetID, int buffID)
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

void BuffSystem::RemoveBuff(int targetID)
{
	auto iterFind = m_buffSets.find(targetID);
	if (iterFind != m_buffSets.end())
		iterFind->second.KillAllBuff();
}

void BuffSystem::RemoveAllBuff()
{
	for (auto iter = m_buffSets.begin(); iter != m_buffSets.end(); ++iter)
	{
		iter->second.KillAllBuff();
	}
}

int BuffSystem::GetBuffCount()
{
	int count = 0;
	for (auto iter = m_buffSets.begin(); iter != m_buffSets.end(); ++iter)
	{
		count += iter->second.GetBuffCount();
	}
	return count;
}