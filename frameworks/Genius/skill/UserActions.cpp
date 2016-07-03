
#include "BuffAction.h"
#include "Buff.h"
#include "UserActions.h"
#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include "ECS/ecs.h"
#include "data/RoleDataMgr.h"
#include "data/BulletDataMgr.h"
#include "entity/EntityCreators.h"
#include "ECS/components/pawn/ComPawnAgent.h"
#include "pawn/PawnBlackboard.h"

using namespace Genius;

int ChangeLife(BuffEnvParam& env, BuffParam& buffParam)
{
	int senderID = env.buff->GetSender();
	int receiverID = env.buff->GetReceiver();
	int damageType = env.buff->GetType();
	do
	{
		Entity* senderEntity = ECSWorld::GetSingleton()->GetEntity(senderID);
		Entity* receiverEntity = ECSWorld::GetSingleton()->GetEntity(receiverID);
		if (nullptr == senderEntity || nullptr == receiverEntity)
			break;

		ComPawnAgent* agentCom = receiverEntity->GetComponent<ComPawnAgent>();
		if (nullptr == agentCom)
			break;

		if (env.apply)
		{
			agentCom->GetBlackboard()->m_currentHP -= buffParam.params[0];
			if (agentCom->GetBlackboard()->m_currentHP < 0)
				agentCom->GetBlackboard()->m_currentHP = 0;
		}

	} while (false);
	
	return 1;
}

int DecLifeByPawn(BuffEnvParam& env, BuffParam& buffParam)
{
	int param[MaxParamNum] = { 0 };
	for (int i = 0; i < MaxParamNum; i++)
	{
		param[i] = buffParam.params[i];
	}

	int senderID = env.buff->GetSender();
	int receiverID = env.buff->GetReceiver();
	int damageType = env.buff->GetType();

	do
	{
		Entity* senderEntity = ECSWorld::GetSingleton()->GetEntity(senderID);
		Entity* receiverEntity = ECSWorld::GetSingleton()->GetEntity(receiverID);
		if (nullptr == senderEntity || nullptr == receiverEntity)
			break;

		ComPawnAgent* tempComSender = senderEntity->GetComponent<ComPawnAgent>();
		ComPawnAgent* tempComReceiver = receiverEntity->GetComponent<ComPawnAgent>();
		ComPawnAgent* agentComReceiver = receiverEntity->GetComponent<ComPawnAgent>();
		if (nullptr == tempComSender
			|| nullptr == tempComReceiver
			|| nullptr == agentComReceiver)
			break;

		if (env.apply)
		{
			int realDecLife = 0;
			int atkType = tempComSender->m_pRoleData->attackType;
			switch (atkType)
			{
			case AT_Physic:
				realDecLife = tempComSender->m_pRoleData->attackValue * (1.0f - tempComReceiver->m_pRoleData->antiPhysicValue*0.01f);
				break;
			case AT_Magic:
				realDecLife = tempComSender->m_pRoleData->attackValue * (1.0f - tempComReceiver->m_pRoleData->antiMagicValue*0.01f);
				break;
			default:
				break;
			}

			if (realDecLife <= 0)
				realDecLife = 1;
			
			agentComReceiver->GetBlackboard()->m_currentHP -= realDecLife;
			if (agentComReceiver->GetBlackboard()->m_currentHP < 0)
				agentComReceiver->GetBlackboard()->m_currentHP = 0;

			EventManager::GetSingleton()->FireEvent(HurtEvent(receiverEntity, - realDecLife));
		}

	} while (false);

	return 1;
}

int AddLifeByPawn(BuffEnvParam& env, BuffParam& buffParam)
{
	int senderID = env.buff->GetSender();
	int receiverID = env.buff->GetReceiver();
	int damageType = env.buff->GetType();
	do
	{
		Entity* senderEntity = ECSWorld::GetSingleton()->GetEntity(senderID);
		Entity* receiverEntity = ECSWorld::GetSingleton()->GetEntity(receiverID);
		if (nullptr == senderEntity || nullptr == receiverEntity)
			break;

		ComPawnAgent* agentComReceiver = receiverEntity->GetComponent<ComPawnAgent>();
		ComPawnAgent* tempComReceiver = receiverEntity->GetComponent<ComPawnAgent>();
		if (nullptr == agentComReceiver || nullptr == tempComReceiver)
			break;

		if (env.apply)
		{
			agentComReceiver->GetBlackboard()->m_currentHP += buffParam.params[0];
			int maxLife = tempComReceiver->m_pRoleData->baseLife;
			if (agentComReceiver->GetBlackboard()->m_currentHP > maxLife)
				agentComReceiver->GetBlackboard()->m_currentHP = maxLife;

			EventManager::GetSingleton()->FireEvent(HurtEvent(receiverEntity, buffParam.params[0]));
		}

	} while (false);

	return 1;
}

int DecLifeByBullet(BuffEnvParam& env, BuffParam& buffParam)
{
	int param[MaxParamNum] = { 0 };
	for (int i = 0; i < MaxParamNum; i++)
	{
		param[i] = buffParam.params[i];
	}

	int senderID = env.buff->GetSender();
	int receiverID = env.buff->GetReceiver();
	int damageType = env.buff->GetType();

	do
	{
		Entity* senderEntity = ECSWorld::GetSingleton()->GetEntity(senderID);
		Entity* receiverEntity = ECSWorld::GetSingleton()->GetEntity(receiverID);
		if (nullptr == senderEntity || nullptr == receiverEntity)
			break;

		ComBulletTemplate* tempComSender = senderEntity->GetComponent<ComBulletTemplate>();
		ComPawnAgent* tempComReceiver = receiverEntity->GetComponent<ComPawnAgent>();
		ComPawnAgent* agentComReceiver = receiverEntity->GetComponent<ComPawnAgent>();
		if (nullptr == tempComSender
			|| nullptr == tempComReceiver
			|| nullptr == agentComReceiver)
			break;

		if (env.apply)
		{
			int realDecLife = 0;
			int atkType = tempComSender->pBulletData->attackType;
			switch (atkType)
			{
			case AT_Physic:
				realDecLife = tempComSender->pBulletData->attackValue * (1.0f - tempComReceiver->m_pRoleData->antiPhysicValue*0.01f);
				break;
			case AT_Magic:
				realDecLife = tempComSender->pBulletData->attackValue * (1.0f - tempComReceiver->m_pRoleData->antiMagicValue*0.01f);
				break;
			default:
				break;
			}

			if (realDecLife <= 0)
				realDecLife = 1;

			agentComReceiver->GetBlackboard()->m_currentHP -= realDecLife;
			if (agentComReceiver->GetBlackboard()->m_currentHP < 0)
				agentComReceiver->GetBlackboard()->m_currentHP = 0;

			EventManager::GetSingleton()->FireEvent(HurtEvent(receiverEntity, -realDecLife));
		}

	} while (false);

	return 1;
}

int SpawnSpiders(BuffEnvParam& env, BuffParam& buffParam)
{
	int param[MaxParamNum] = { 0 };
	for (int i = 0; i < MaxParamNum; i++)
	{
		param[i] = buffParam.params[i];
	}

	int senderID = env.buff->GetSender();
	int receiverID = env.buff->GetReceiver();
	int damageType = env.buff->GetType();

	do
	{
		Entity* senderEntity = ECSWorld::GetSingleton()->GetEntity(senderID);
		if (nullptr == senderEntity)
			break;

		ComBulletTemplate* tempComSender = senderEntity->GetComponent<ComBulletTemplate>();
		if (nullptr == tempComSender)
			break;

		ComPosition* posCom = senderEntity->GetComponent<ComPosition>();
		if (nullptr == posCom)
			break;

		ComTeam* teamCom = senderEntity->GetComponent<ComTeam>();
		if (nullptr == teamCom)
			break;

		if (env.apply)
		{
			EntityCreator::CreatePawn(param[0], posCom->x, posCom->y, teamCom->team);
		}

	} while (false);

	return 1;
}

/************************************************************************/
/*                                                    func list and finder                  */
/************************************************************************/
BuffActionFucMap s_actionFuncMap[] =
{
	{ "ChangeLife", ChangeLife },
	{ "DecLifeByPawn", DecLifeByPawn },
	{ "AddLifeByPawn", AddLifeByPawn },
	{ "DecLifeByBullet", DecLifeByBullet },
	{ "SpawnSpiders", SpawnSpiders },
	{ "", nullptr },
};

BuffActionFunction UserActions::FindAction(std::string& name)
{
	BuffActionFunction func = nullptr;
	int index = 0;
	while (s_actionFuncMap[index].name != "")
	{
		if (s_actionFuncMap[index].name == name)
		{
			func = s_actionFuncMap[index].func;
			break;
		}
		index++;
	}
	return func;
}