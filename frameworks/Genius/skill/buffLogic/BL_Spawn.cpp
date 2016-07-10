
#include "BL_Spawn.h"
#include "../Buff.h"
#include "data/auto/Buff_cfg.hpp"
#include "common/Log.h"
#include "ECS/ecs.h"
#include "pawn/PawnBlackboard.h"
#include "event/EventManager.h"
#include "ECS/EntityEvents.h"
#include "entity/EntityCreators.h"


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

		ComPosition* posCom = senderEntity->GetComponent<ComPosition>();
		if (nullptr == posCom)
			break;

		ComTeam* teamCom = senderEntity->GetComponent<ComTeam>();
		if (nullptr == teamCom)
			break;

		EntityCreator::CreatePawn(buff->GetCfg()->calType, posCom->x, posCom->y, teamCom->team);

	}while (false);

}



