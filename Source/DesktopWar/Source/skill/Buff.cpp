
#include "Buff.h"
#include "data/BuffDataMgr.h"
#include "data/BuffActionDataMgr.h"

using namespace Genius;

Buff::Buff() :
m_buffTemplate(nullptr),
m_senderID(0),
m_receiverID(0),
m_instID(0),
m_duration(0),
m_life(0),
m_curPileCount(0),
m_skillID(0),
m_alive(true),
m_cycleCount(0)
{
}

bool Buff::LoadFromTemplate(int tempID)
{
	auto buffTemplate = BuffDataMgr::GetSingleton()->GetBuffData(tempID);
	if (nullptr == buffTemplate)
		return false;
	
	m_buffTemplate = buffTemplate;
	m_duration = (float)(buffTemplate->duration);
	m_curPileCount = 0;

	// at beginning
	for (auto iter = buffTemplate->beginActions.begin(); iter != buffTemplate->beginActions.end(); ++iter)
	{
		auto actionTemplate = BuffActionDataMgr::GetSingleton()->GetBuffActionData(*iter);
		if (nullptr == actionTemplate)
			continue;
		Effect effect;
		effect.action.SetTemplate(actionTemplate);
		m_beginActions.push_back(effect);
	}

	// cycling
	for (auto iter = buffTemplate->cycleActions.begin(); iter != buffTemplate->cycleActions.end(); ++iter)
	{
		auto actionTemplate = BuffActionDataMgr::GetSingleton()->GetBuffActionData(*iter);
		if (actionTemplate)
		{
			EffectCycle	eff_cyc;
			if (GetMaxPersist() != 0)
			{
				eff_cyc.m_interval = m_buffTemplate->jumpTime;
				eff_cyc.action.SetTemplate(actionTemplate);
				m_cycleActions.push_back(eff_cyc);
			}
		}
	}

	// effect
	for (auto iter = buffTemplate->effectActions.begin(); iter != buffTemplate->effectActions.end(); ++iter)
	{
		auto actionTemplate = BuffActionDataMgr::GetSingleton()->GetBuffActionData(*iter);
		if (nullptr == actionTemplate)
			continue;
		Effect effect;
		effect.action.SetTemplate(actionTemplate);
		m_effectActions.push_back(effect);
	}

	// in the end
	for (auto iter = buffTemplate->endActions.begin(); iter != buffTemplate->endActions.end(); ++iter)
	{
		auto actionData = BuffActionDataMgr::GetSingleton()->GetBuffActionData(*iter);
		if (nullptr == actionData)
			continue;
		Effect effect;
		effect.action.SetTemplate(actionData);
		m_endActions.push_back(effect);
	}
	
	return false;
}

bool Buff::IsAlive()
{
	return true;
}

int Buff::GetSeriesType()
{
	if (m_buffTemplate)
		return m_buffTemplate->series;
	else
		return 0;
}

int Buff::GetPileType()
{
	if (m_buffTemplate)
		return m_buffTemplate->pileType;
	else
		return 0;
}

float Buff::GetMaxPersist()
{
	if (m_buffTemplate)
		return (float)m_buffTemplate->duration;
	else
		return 0;
}

int Buff::GetType()
{ 
	return m_buffTemplate ? m_buffTemplate->hurtType : EBuffHurtType_None; 
}

int Buff::Update(float elapse)
{
	m_life += elapse;

	//for effect_i
	BuffEnvParam env;
	env.buff = this;
	env.apply = true;

	if ((m_cycleCount == (m_duration / m_buffTemplate->jumpTime) || m_life - m_lastActionTime > m_buffTemplate->jumpTime))
	{
		for (unsigned int nloopCount = 0; nloopCount < m_cycleActions.size(); nloopCount++)
		{
			if (m_cycleActions[nloopCount].action.IsConditionRight(env))
				m_cycleActions[nloopCount].action(env);
		}

		m_lastActionTime = m_life;
		m_cycleCount--;
	}

	if (m_duration>0)
	{
		if (m_duration > elapse)
		{
			m_duration -= elapse;
			return EBuffRet_Keep;
		}
		else
		{
			m_duration = 0;
			return EBuffRet_Kill;
		}
	}

	return 0;
}

int Buff::AddPile()
{
	m_duration = GetMaxPersist();
	if (m_buffTemplate->jumpTime > 0)
	{
		m_cycleCount = (int)(m_duration / m_buffTemplate->jumpTime);
	}

	EndEffect();
	if (m_curPileCount < m_buffTemplate->maxPileCount)
	{
		m_curPileCount++;
	}
	BeginEffect();

	if (m_curPileCount == 1)
		Begin();

	return EBuffRet_True;
}

int Buff::RemovePile()
{
	EndEffect();
	if (m_curPileCount > 1)
	{
		m_curPileCount--;
		BeginEffect();
		return EBuffRet_True;
	}
	return EBuffRet_Kill;
}

void Buff::RemoveAllPile()
{
	EndEffect();
	End();
}

bool Buff::Begin()
{
	BuffEnvParam env;
	env.buff = this;
	env.apply = true;
	env.skillID = m_skillID;

	for (auto iter = m_beginActions.begin(); iter != m_beginActions.end(); ++iter)
	{
		if ((*iter).action.IsConditionRight(env))
		{
			(*iter).action(env);
		}
	}

	m_alive = true;
	return true;
}

bool Buff::End()
{
	BuffEnvParam env;
	env.buff = this;
	env.apply = true;
	env.skillID = m_skillID;

	for (auto iter = m_endActions.begin(); iter != m_endActions.end(); ++iter)
	{
		if ((*iter).action.IsConditionRight(env))
		{
			(*iter).action(env);
		}
	}

	m_alive = false;
	return true;
}

bool Buff::BeginEffect()
{
	BuffEnvParam env;
	env.buff = this;
	env.apply = true;
	env.skillID = m_skillID;

	for (auto iter = m_effectActions.begin(); iter != m_effectActions.end(); ++iter)
	{
		if ((*iter).action.IsConditionRight(env))
		{
			(*iter).effected = true;
			(*iter).action(env);
		}
		else
		{
			(*iter).effected = false;
		}
	}

	return true;
}

bool Buff::EndEffect()
{
	BuffEnvParam env;
	env.buff = this;
	env.apply = false;
	env.skillID = m_skillID;

	for (auto iter = m_effectActions.begin(); iter != m_effectActions.end(); ++iter)
	{
		if ((*iter).effected)
		{
			(*iter).action(env);
		}
	}

	return true;
}





