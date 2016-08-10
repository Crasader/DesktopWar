
#include "BL_Damage.h"
#include "../Buff.h"
#include "data/auto/Buff_cfg.hpp"
#include "data/auto/Bullet_cfg.hpp"
#include "data/auto/Role_cfg.hpp"
#include "common/Log.h"
#include "ECS/ecs.h"

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

	} while (false);

}



