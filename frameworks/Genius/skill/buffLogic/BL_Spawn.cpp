
#include "BL_Spawn.h"
#include "../Buff.h"
#include "data/auto/Buff_cfg.hpp"
#include "common/Log.h"
#include "ECS/ecs.h"

#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include "entity/EntityCreators.h"
#include "entity/EntityUtility.h"


using namespace Genius;

IMPL_BUFFLOGIC_CREATOR(BL_Spawn);


void BL_Spawn::OnActive(Buff* buff)
{
	Log::Error("to do.");
}

void BL_Spawn::OnDeactive(Buff* buff)
{
	Log::Error("to do.");
}

void BL_Spawn::OnEffect(Buff* buff)
{
	int senderID = buff->GetSender();
	int receiverID = buff->GetReceiver();
	int damageType = buff->GetModType();

	do
	{
		Entity* senderEntity = ECSWorld::GetSingleton()->GetEntity(senderID);
		if (nullptr == senderEntity)
		{
			Log::Error("BL_Spawn : cannot find entity.");
			break;
		}

		ComTransform* posCom = senderEntity->GetComponent<ComTransform>();
		if (nullptr == posCom)
			break;

		ComPawnAgent* bulletAgent = senderEntity->GetComponent<ComPawnAgent>();
		if (nullptr == bulletAgent)
			break;

		bool isTagged = EntityUtility::IsTagged(GameDefine::Tag_Soldier, senderEntity);
		const string& targetTag = isTagged ? GameDefine::Tag_Soldier : GameDefine::Tag_Monster;

		EntityCreator::CreatePawn(buff->GetCfg()->calType, posCom->x, posCom->y, targetTag);

	}while (false);

}



