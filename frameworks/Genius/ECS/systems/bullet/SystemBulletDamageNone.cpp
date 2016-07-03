
#include "SystemBulletDamageNone.h"
#include "event/EventManager.h"
#include "../../EntityEvents.h"
#include "../../core/Entity.h"
#include "2Ddef.h"
#include "data/BulletDataMgr.h"
#include "../../core/ECSWorld.h"
#include "../../core/SystemManager.h"
#include "../pawn/SystemPawnFight.h"
#include "skill/BuffSystem.h"

using namespace Genius;

void SystemBulletDamageNone::Initialize()
{
	positionMapper.init(*world);
	damageMapper.init(*world);
	bulletTemplateMapper.init(*world);

	// register event.
	EventManager::GetSingleton()->AddListener(this, Event_BulletTrigger);
}

void SystemBulletDamageNone::ProcessEntity(Entity* pEntity)
{
}

bool SystemBulletDamageNone::HandleEvent(IEventData const &evnt)
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

bool SystemBulletDamageNone::TriggerBulletBuff(IEventData const &evt)
{
	const BulletTriggerEvent & castedEvent = static_cast<const BulletTriggerEvent &>(evt);
	Entity* pOwnerEntity = castedEvent.entity;
	if (!IsMyEntity(pOwnerEntity))
		return false;

	ComBulletDamageNone* pAttackCom = damageMapper.get(pOwnerEntity);

	ComBulletTemplate* bulletTempCom = bulletTemplateMapper.get(pOwnerEntity);
	const BulletData* bulletInfo = bulletTempCom->pBulletData;
	for (int i = 0; i < BulletData::BuffNum; ++i)
	{
		if (bulletInfo->buffs[i] != 0)
			BuffSystem::GetSingleton().AddBuff(pOwnerEntity->GetId(), Entity::InvalidID, bulletInfo->buffs[i]);
	}
	
	return true;
}