
#include "PawnActionFactory.h"
#include "PawnActionIdle.h"
#include "PawnActionDie.h"
#include "PawnActionMove.h"
#include "PawnActionAttackNear.h"
#include "PawnActionAttackFar.h"
#include "PawnActionSkill1.h"
#include "PawnActionSkill2.h"
#include "PawnActionSkill3.h"
#include "PawnActionChangeDir.h"

using namespace Genius;

PawnActionFactory* PawnActionFactory::GetSingleton()
{
	static PawnActionFactory inst;
	return &inst;
}

PawnActionFactory::~PawnActionFactory()
{
	Release();
}

PawnAction* PawnActionFactory::CreatePawnAction(int type)
{
	if (type < 0 || type >= PAT_Count)
		return nullptr;

	PawnAction* pAction = nullptr;

	if (m_actionUnused[type].size() > 0)
	{
		pAction = m_actionUnused[type].front();
		m_actionUnused[type].pop_front();
	}
	else
	{
		switch (type)
		{
		case PAT_Idle:
			pAction = new PawnActionIdle();
			break;
		case PAT_Die:
			pAction = new PawnActionDie();
			break;
		case PAT_Move:
			pAction = new PawnActionMove();
			break;
		case PAT_AttackNear:
			pAction = new PawnActionAttackNear();
			break;
		case PAT_AttackFar:
			pAction = new PawnActionAttackFar();
			break;
		case PAT_Skill1:
			pAction = new PawnActionSkill1();
			break;
		case PAT_Skill2:
			pAction = new PawnActionSkill2();
			break;
		case PAT_Skill3:
			pAction = new PawnActionSkill3();
			break;
		case PAT_ChangeDir:
			pAction = new PawnActionChangeDir();
			break;
		default:
			pAction = nullptr;
			break;
		}
	}

	if (pAction != nullptr)
	{
		pAction->Reset();
		pAction->SetActive();
		m_actionInUse[type].push_back(pAction);
	}

	return pAction;
}

void PawnActionFactory::RecycleAction(PawnAction* pAction)
{
	if (nullptr == pAction)
		return;

	int type = pAction->GetType();
	if (type < 0 || type >= PAT_Count)
		return;

	auto actionsInUse = m_actionInUse[type];
	for (auto iter = actionsInUse.begin(); iter != actionsInUse.end(); ++iter)
	{
		if ((*iter) != nullptr && (*iter) == pAction)
		{
			actionsInUse.erase(iter);
			break;
		}
	}

	bool repeated = false;
	auto actionsUnused = m_actionUnused[type];
	for (auto iter = actionsUnused.begin(); iter != actionsUnused.end(); ++iter)
	{
		if ((*iter) != nullptr && (*iter) == pAction)
		{
			repeated = true;
			break;
		}
	}
	if (!repeated)
	{
		pAction->SetUnused();
		actionsUnused.push_back(pAction);
	}

}

void PawnActionFactory::Release()
{
	for (int i = 0; i < PAT_Count; ++i)
	{
		for (auto iter = m_actionUnused[i].begin(); iter != m_actionUnused[i].end(); ++iter)
		{
			if (*iter)
				delete *iter;
		}
		m_actionUnused[i].clear();
	}

	for (int i = 0; i < PAT_Count; ++i)
	{
		for (auto iter = m_actionInUse[i].begin(); iter != m_actionInUse[i].end(); ++iter)
		{
			if (*iter)
				delete *iter;
		}
		m_actionInUse[i].clear();
	}
}