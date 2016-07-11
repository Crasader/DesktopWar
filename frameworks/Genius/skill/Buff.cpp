
#include "Buff.h"
#include "data/auto/Buff_cfg.hpp"
#include "data/ConfigPool.h"
#include "buffLogic/BuffLogic.h"


using namespace Genius;
using namespace cfg;


Buff::Buff() :
m_cfg(nullptr),
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

bool Buff::Init(int cfg)
{
	auto buffCfg = FIND_CFG(Buff_cfg, cfg);
	if (nullptr == buffCfg)
		return false;
	
	m_cfg = buffCfg;
	m_duration = (float)(buffCfg->duration);
	m_curPileCount = 0;

	return false;
}

bool Buff::IsAlive()
{
	return m_alive;
}

int Buff::GetSeries()
{
	if (m_cfg)
		return m_cfg->series;
	else
		return 0;
}

int Buff::GetPileType()
{
	if (m_cfg)
		return m_cfg->pileType;
	else
		return 0;
}

float Buff::GetMaxPersist()
{
	if (m_cfg)
		return (float)m_cfg->duration;
	else
		return 0;
}

int Buff::GetModType()
{ 
	return m_cfg ? m_cfg->modType : EBuffMod_None; 
}

int Buff::Update(float elapse)
{
	m_life += elapse;

	if ((m_cycleCount == (m_duration / m_cfg->jumpTime) || m_life - m_lastActionTime > m_cfg->jumpTime))
	{
// 		BuffEnvParam env;
// 		env.buff = this;
// 		env.apply = true;
		auto logic = BuffLogic::GetLogic(m_cfg->logicId);
		if (nullptr != logic)
		{
			logic->OnEffect(this);
		}

		m_lastActionTime = m_life;
		m_cycleCount--;
	}

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

	return 0;
}

int Buff::AddPile()
{
	m_duration = GetMaxPersist();
	if (m_cfg->jumpTime > 0)
		m_cycleCount = (int)(m_duration / m_cfg->jumpTime);

	EndEffect();

	if (m_curPileCount < m_cfg->maxPileCount)
		m_curPileCount++;

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
// 	BuffEnvParam env;
// 	env.buff = this;
// 	env.apply = true;
// 	env.skillID = m_skillID;

	auto logic = BuffLogic::GetLogic(m_cfg->logicId);
	if (nullptr != logic)
	{
		logic->OnActive(this);
		logic->OnEffect(this);
	}

	m_alive = true;
	return true;
}

bool Buff::End()
{
// 	BuffEnvParam env;
// 	env.buff = this;
// 	env.apply = true;
// 	env.skillID = m_skillID;

	auto logic = BuffLogic::GetLogic(m_cfg->logicId);
	if (nullptr != logic)
	{
		logic->OnDeactive(this);
	}

	m_alive = false;
	return true;
}

bool Buff::BeginEffect()
{
	/*BuffEnvParam env;
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
	}*/

	return true;
}

bool Buff::EndEffect()
{
	/*BuffEnvParam env;
	env.buff = this;
	env.apply = false;
	env.skillID = m_skillID;

	for (auto iter = m_effectActions.begin(); iter != m_effectActions.end(); ++iter)
	{
		if ((*iter).effected)
		{
			(*iter).action(env);
		}
	}*/

	return true;
}





