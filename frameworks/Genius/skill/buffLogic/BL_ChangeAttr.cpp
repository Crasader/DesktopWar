
#include "BL_ChangeAttr.h"
#include "../Buff.h"
#include "data/auto/Buff_cfg.hpp"
#include "common/Log.h"
#include "ECS/ecs.h"

#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include "scripting/JSInvoker.h"


using namespace Genius;

IMPL_BUFFLOGIC_CREATOR(BL_ChangeAttr);


void BL_ChangeAttr::OnActive(Buff* buff)
{
	//Log::Error("to do.");
}

void BL_ChangeAttr::OnDeactive(Buff* buff)
{
	//Log::Error("to do.");
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

		JSInvoker::Invoke_ModifyEntityAttr(receiverID, buffCfg->calType, buffCfg->attrType, buffCfg->value);

	} while (false);
}



