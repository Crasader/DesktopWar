
#include "BL_Damage.h"
#include "../Buff.h"
#include "data/auto/Buff_cfg.hpp"
#include "data/auto/Bullet_cfg.hpp"
#include "data/auto/Role_cfg.hpp"
#include "common/Log.h"
#include "ECS/ecs.h"
#include "pawn/PawnBlackboard.h"
#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include "pawn/PawnDefines.h"
#include "scripting/JSInvoker.h"



using namespace Genius;

IMPL_BUFFLOGIC_CREATOR(BL_Damage);


void BL_Damage::OnActive(Buff* buff)
{
	
}

void BL_Damage::OnDeactive(Buff* buff)
{

}

void BL_Damage::OnEffect(Buff* buff)
{
	int senderID = buff->GetSender();
	int receiverID = buff->GetReceiver();
	int damageType = buff->GetModType();
	auto buffCfg = buff->GetCfg();

	do
	{

		Entity* senderEntity = ECSWorld::GetSingleton()->GetEntity(senderID);
		Entity* receiverEntity = ECSWorld::GetSingleton()->GetEntity(receiverID);
		if (nullptr == senderEntity || nullptr == receiverEntity)
		{
			Log::Error("BL_Damage : cannot find entity.");
			break;
		}

		ComPawnAgent* agentSender = senderEntity->GetComponent<ComPawnAgent>();

		/*if (buffCfg->calType == CalcType::NPC)
		{
			ComPawnAgent* agentSender = senderEntity->GetComponent<ComPawnAgent>();
			ComPawnAgent* agentReceiver = receiverEntity->GetComponent<ComPawnAgent>();
			if (nullptr == agentSender
				|| nullptr == agentReceiver)
			{
				Log::Error("BL_Damage : cannot find com.");
				break;
			}

			int realDecLife = 0;
			int atkType = agentSender->m_roleCfg->attackType;
			switch (atkType)
			{
			case HurtType::Phy:
				realDecLife = agentSender->m_roleCfg->attackValue * (1.0f - agentReceiver->m_roleCfg->antiPhysicValue*0.01f);
				break;
			case HurtType::Mag:
				realDecLife = agentSender->m_roleCfg->attackValue * (1.0f - agentReceiver->m_roleCfg->antiMagicValue*0.01f);
				break;
			default:
				break;
			}

			if (realDecLife <= 0)
				realDecLife = 1;
*/
		int attackValue = 0;
		if (agentSender->m_roleCfg)
			attackValue = agentSender->m_roleCfg->attackValue;
		else if (agentSender->pBulletData)
			attackValue = agentSender->pBulletData->attackValue;

		int atkType = 0;
		if (agentSender->m_roleCfg)
			atkType = agentSender->m_roleCfg->attackType;
		else if (agentSender->pBulletData)
			atkType = agentSender->pBulletData->attackType;

		JSInvoker::Invoke_ModifyEntityAttr(receiverID, buffCfg->calType, 1, attackValue, atkType);
		/*}
		else if (buffCfg->calType == CalcType::Bullet)
		{
			ComPawnAgent* agentSender = senderEntity->GetComponent<ComPawnAgent>();
			ComPawnAgent* agentReceiver = receiverEntity->GetComponent<ComPawnAgent>();
			if (nullptr == agentSender
				|| nullptr == agentReceiver)
				break;

			int realDecLife = 0;
			int atkType = agentSender->pBulletData->attackType;
			switch (atkType)
			{
			case HurtType::Phy:
				realDecLife = agentSender->pBulletData->attackValue * (1.0f - agentReceiver->m_roleCfg->antiPhysicValue*0.01f);
				break;
			case HurtType::Mag:
				realDecLife = agentSender->pBulletData->attackValue * (1.0f - agentReceiver->m_roleCfg->antiMagicValue*0.01f);
				break;
			default:
				break;
			}

			if (realDecLife <= 0)
				realDecLife = 1;

			agentReceiver->GetBlackboard()->ModAttr(AttrType::HP, -realDecLife);

			EventManager::GetSingleton()->FireEvent(HurtEvent(receiverEntity, -realDecLife));
		}*/


		

	} while (false);

}



