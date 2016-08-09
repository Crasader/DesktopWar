
#include "BL_ChangeAttr.h"
#include "../Buff.h"
#include "data/auto/Buff_cfg.hpp"
#include "common/Log.h"
#include "ECS/ecs.h"
#include "pawn/PawnBlackboard.h"
#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include "scripting/JSInvoker.h"


using namespace Genius;

IMPL_BUFFLOGIC_CREATOR(BL_ChangeAttr);


void BL_ChangeAttr::OnActive(Buff* buff)
{
	Log::Error("to do.");
}

void BL_ChangeAttr::OnDeactive(Buff* buff)
{
	Log::Error("to do.");
}

void BL_ChangeAttr::OnEffect(Buff* buff)
{
	int senderID = buff->GetSender();
	int receiverID = buff->GetReceiver();
	int damageType = buff->GetModType();
	do
	{
		Entity* senderEntity = ECSWorld::GetSingleton()->GetEntity(senderID);
		Entity* receiverEntity = ECSWorld::GetSingleton()->GetEntity(receiverID);
		if (nullptr == senderEntity || nullptr == receiverEntity)
		{
			Log::Error("BL_ChangeAttr : cannot find entity.");
			break;
		}

		ComPawnAgent* agentReceiver = receiverEntity->GetComponent<ComPawnAgent>();
		if (nullptr == agentReceiver)
			break;

		auto buffCfg = buff->GetCfg();
		/*int value = 0;
		switch (buffCfg->calType)
		{
		case CalcType::Fixed:
			agentReceiver->GetBlackboard()->ModAttr(buffCfg->attrType, buffCfg->value);
			value = buffCfg->value;
			break;
		case CalcType::Percent:
		{
								  int old = agentReceiver->GetBlackboard()->GetAttr(buffCfg->attrType);
								  value = old * buffCfg->value * 0.01f;
								  agentReceiver->GetBlackboard()->ModAttr(buffCfg->attrType, value);
		}
			break;
		}*/

		JSInvoker::Invoke_ModifyEntityAttr(receiverID, buffCfg->calType, buffCfg->attrType, buffCfg->value);

		EventManager::GetSingleton()->FireEvent(HurtEvent(receiverEntity, value));

	} while (false);
}



