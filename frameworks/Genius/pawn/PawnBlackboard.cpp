
#include "PawnBlackboard.h"
#include "ECS/components/pawn/ComPawnAgent.h"
#include "action/PawnActionFactory.h"
#include "action/ActionHandler.h"
#include "pawn/PawnDefines.h"
#include "data/auto/Role_cfg.hpp"
#include "data/auto/Bullet_cfg.hpp"
#include "common/Log.h"

using namespace Genius;

PawnBlackboard::PawnBlackboard(ComPawnAgent* agent)
{
	m_pAgent = agent;
	auto cfg = agent->m_roleCfg;
	if (cfg != nullptr)
	{
		SetAttr(AttrType::HP, cfg->baseLife);
		SetAttr(AttrType::MoveSpeed, 1);
		SetAttr(AttrType::AttackSpeed, 1);
		SetAttr(AttrType::AttackStren, cfg->attackValue);
		SetAttr(AttrType::DefencePhy, cfg->antiPhysicValue);
		SetAttr(AttrType::DefenceMag, cfg->antiMagicValue);
		SetAttr(AttrType::Dodge, cfg->dodgeValue);
	}
}

PawnBlackboard::~PawnBlackboard()
{

}

void PawnBlackboard::Update()
{

}

void PawnBlackboard::AddAction(PawnAction* pAction)
{
	if (nullptr == pAction)
		return;

	m_actionQueue.push(pAction);

	for (auto iter = m_actionHandlers.begin(); iter != m_actionHandlers.end(); ++iter)
	{
		if ((*iter) != nullptr)
		{
			(*iter)->HandleAction(pAction);
		}
	}

}

void PawnBlackboard::FinishAction(PawnAction* pAction)
{
	if (nullptr == pAction)
		return;

	PawnActionFactory::GetSingleton()->RecycleAction(pAction);
}

void PawnBlackboard::AddActionHandler(ActionHandler* pHandler)
{
	bool repeated = false;
	for (auto iter = m_actionHandlers.begin(); iter != m_actionHandlers.end(); ++iter)
	{
		if ((*iter) != nullptr && (*iter) == pHandler)
		{
			repeated = true;
			break;
		}
	}

	if (!repeated)
	{
		m_actionHandlers.push_back(pHandler);
	}
	
}

void PawnBlackboard::RemoveActionHandler(ActionHandler* pHandler)
{
	for (auto iter = m_actionHandlers.begin(); iter != m_actionHandlers.end(); ++iter)
	{
		if ((*iter) != nullptr && (*iter) == pHandler)
		{
			m_actionHandlers.erase(iter);
			break;
		}
	}
}


int PawnBlackboard::GetAttr(int type)
{
	if (type <= AttrType::ATNone && type >= AttrType::Count)
	{
		Log::Error("PawnBlackboard.GetAttr : wrong type %d", type);
		return 0;
	}

	return m_attr[type];
}

void PawnBlackboard::SetAttr(int type, int value)
{
	if (type <= AttrType::ATNone && type >= AttrType::Count)
	{
		Log::Error("PawnBlackboard.SetAttr : wrong type %d", type);
		return;
	}

	m_attr[type] = value;

	if (m_attr[type] < 0)
		m_attr[type] = 0;
}

void PawnBlackboard::ModAttr(int type, int value)
{
	if (type <= AttrType::ATNone && type >= AttrType::Count)
	{
		Log::Error("PawnBlackboard.SetAttr : wrong type %d", type);
		return;
	}

	m_attr[type] = m_attr[type] + value;

	if (m_attr[type] < 0)
		m_attr[type] = 0;
}

void PawnBlackboard::SetTargetType(int tp)
{
	targetType = tp;
}

void PawnBlackboard::SetTargetID(int id)
{
	targetID = id;
}

void PawnBlackboard::SetTargetX(float x)
{
	targetX = x;
}

void PawnBlackboard::SetTargetY(float y)
{
	targetY = y;
}




