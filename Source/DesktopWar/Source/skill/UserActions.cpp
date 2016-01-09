// d:)
#include "BuffAction.h"
#include "Buff.h"
#include "UserActions.h"
#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include "ECS/ECSHeaders.h"
#include "data/RoleDataMgr.h"
#include "data/BulletDataMgr.h"
#include "EntityCreators.h"

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

		PawnAttributeCom* attCom = receiverEntity->GetComponent<PawnAttributeCom>();
		if (nullptr == attCom)
			break;

		if (env.apply)
		{
			attCom->curLife -= buffParam.params[0];
			if (attCom->curLife < 0)
				attCom->curLife = 0;
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

		PawnTemplateCom* tempComSender = senderEntity->GetComponent<PawnTemplateCom>();
		PawnTemplateCom* tempComReceiver = receiverEntity->GetComponent<PawnTemplateCom>();
		PawnAttributeCom* attComReceiver = receiverEntity->GetComponent<PawnAttributeCom>();
		if (nullptr == tempComSender
			|| nullptr == tempComReceiver
			|| nullptr == attComReceiver)
			break;

		if (env.apply)
		{
			int realDecLife = 0;
			int atkType = tempComSender->pRoleData->attackType;
			switch (atkType)
			{
			case AT_Physic:
				realDecLife = tempComSender->pRoleData->attackValue * (1.0f - tempComReceiver->pRoleData->antiPhysicValue*0.01f);
				break;
			case AT_Magic:
				realDecLife = tempComSender->pRoleData->attackValue * (1.0f - tempComReceiver->pRoleData->antiMagicValue*0.01f);
				break;
			default:
				break;
			}

			if (realDecLife <= 0)
				realDecLife = 1;
			
			attComReceiver->curLife -= realDecLife;
			if (attComReceiver->curLife < 0)
				attComReceiver->curLife = 0;

			EventManager::GetInstance().FireEvent(HurtEvent(receiverEntity, - realDecLife));
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

		PawnAttributeCom* attComReceiver = receiverEntity->GetComponent<PawnAttributeCom>();
		PawnTemplateCom* tempComReceiver = receiverEntity->GetComponent<PawnTemplateCom>();
		if (nullptr == attComReceiver || nullptr == tempComReceiver)
			break;

		if (env.apply)
		{
			attComReceiver->curLife += buffParam.params[0];
			int maxLife = tempComReceiver->pRoleData->baseLife;
			if (attComReceiver->curLife > maxLife)
				attComReceiver->curLife = maxLife;

			EventManager::GetInstance().FireEvent(HurtEvent(receiverEntity, buffParam.params[0]));
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

		BulletTemplateCom* tempComSender = senderEntity->GetComponent<BulletTemplateCom>();
		PawnTemplateCom* tempComReceiver = receiverEntity->GetComponent<PawnTemplateCom>();
		PawnAttributeCom* attComReceiver = receiverEntity->GetComponent<PawnAttributeCom>();
		if (nullptr == tempComSender
			|| nullptr == tempComReceiver
			|| nullptr == attComReceiver)
			break;

		if (env.apply)
		{
			int realDecLife = 0;
			int atkType = tempComSender->pBulletData->attackType;
			switch (atkType)
			{
			case AT_Physic:
				realDecLife = tempComSender->pBulletData->attackValue * (1.0f - tempComReceiver->pRoleData->antiPhysicValue*0.01f);
				break;
			case AT_Magic:
				realDecLife = tempComSender->pBulletData->attackValue * (1.0f - tempComReceiver->pRoleData->antiMagicValue*0.01f);
				break;
			default:
				break;
			}

			if (realDecLife <= 0)
				realDecLife = 1;

			attComReceiver->curLife -= realDecLife;
			if (attComReceiver->curLife < 0)
				attComReceiver->curLife = 0;

			EventManager::GetInstance().FireEvent(HurtEvent(receiverEntity, -realDecLife));
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

		BulletTemplateCom* tempComSender = senderEntity->GetComponent<BulletTemplateCom>();
		if (nullptr == tempComSender)
			break;

		PositionCom* posCom = senderEntity->GetComponent<PositionCom>();
		if (nullptr == posCom)
			break;

		TeamCom* teamCom = senderEntity->GetComponent<TeamCom>();
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