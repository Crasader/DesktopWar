#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComPosition.h"
#include "../../components/bullet/ComBulletDamageNone.h"
#include "../../components//bullet/ComBulletAgent.h"

namespace Genius
{
	class SystemBulletDamageNone : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComPosition> positionMapper;
		ComponentMapper<ComBulletDamageNone> damageMapper;
		ComponentMapper<ComBulletAgent> agentMapper;

	public:
		SystemBulletDamageNone()
		{
			SetComponentTypes<ComPosition, ComBulletDamageNone, ComBulletAgent>();
		}
		virtual const char* GetName(){ return "SystemBulletDamageNone"; }
		virtual void Initialize();
		virtual void ProcessEntity(Entity* e);

	public:
		virtual bool HandleEvent(IEventData const &event);

	private:
		bool TriggerBulletBuff(IEventData const &evnt);
	};
};