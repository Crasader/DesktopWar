#pragma once

#include "../../core/EntityProcessingSystem.h"
#include "../../core/ComponentMapper.h"
#include "../../components/common/ComTransform.h"
#include "../../components/bullet/ComBulletDamageNone.h"
#include "../../components/pawn/ComPawnAgent.h"

namespace Genius
{
	class SystemBulletDamageNone : public EntityProcessingSystem
	{
	private:
		ComponentMapper<ComTransform> transMapper;
		ComponentMapper<ComBulletDamageNone> damageMapper;
		ComponentMapper<ComPawnAgent> agentMapper;

	public:
		SystemBulletDamageNone()
		{
			SetComponentTypes<ComTransform, ComBulletDamageNone, ComPawnAgent>();
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