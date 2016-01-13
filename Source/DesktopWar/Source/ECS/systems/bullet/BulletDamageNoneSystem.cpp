// d:)
#include "BulletDamageNoneSystem.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"
#include "data/BulletDataMgr.h"
#include "../../core/ECSWorld.h"
#include "../../core/SystemManager.h"
#include "../pawn/PawnFightSystem.h"
#include "skill/BuffSystem.h"

using namespace Genius;

void BulletDamageNoneSystem::Initialize()
{
	positionMapper.init(*world);
	damageMapper.init(*world);
	bulletTemplateMapper.init(*world);

	// register event.
	EventManager::GetInstance().AddListener(this, Event_BulletTrigger);
}

void BulletDamageNoneSystem::ProcessEntity(Entity* pEntity)
{
}

bool BulletDamageNoneSystem::HandleEvent(IEventData const &evnt)
{
	EventType eType = evnt.GetType();
	switch (eType)
	{
	case Event_BulletTrigger:
		return TriggerBulletBuff(evnt);
		break;
	}

	return true;
}

bool BulletDamageNoneSystem::TriggerBulletBuff(IEventData const &evt)
{
	const BulletTriggerEvent & castedEvent = static_cast<const BulletTriggerEvent &>(evt);
	Entity* pOwnerEntity = castedEvent.entity;
	if (!IsMyEntity(pOwnerEntity))
		return false;

	BulletDamageNoneCom* pAttackCom = damageMapper.get(pOwnerEntity);

	BulletTemplateCom* bulletTempCom = bulletTemplateMapper.get(pOwnerEntity);
	const BulletData* bulletInfo = bulletTempCom->pBulletData;
	for (int i = 0; i < BulletData::BuffNum; ++i)
	{
		if (bulletInfo->buffs[i] != 0)
			BuffSystem::GetSingleton().AddBuff(pOwnerEntity->GetId(), Entity::InvalidID, bulletInfo->buffs[i]);
	}
	
	return true;
}